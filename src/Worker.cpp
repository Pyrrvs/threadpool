#include <iostream>
#include "Worker.hpp"

namespace		Thread
{
  Worker::Worker(TaskQueue & tasks, CondVar & taskCond,
		 Lock & taskLock, CondVar & noMoreTaskCond) :
    status(FREE), tasks(tasks), taskCond(taskCond),
    taskLock(taskLock), noMoreTaskCond(noMoreTaskCond)
  {
    this->start<Worker>(*this);
  }

  Worker::~Worker(void)
  {
    this->cancel();
    this->wait();
  }

  void Worker::operator()(void)
  {
    ITask *task;

    while (1)
      {
	this->taskLock.lock();
	if (this->tasks.empty())
	  {
	    std::cout << "W[" << this << "] No more task" << std::endl;
	    this->noMoreTaskCond.signal();	
	    this->taskCond.wait();
	  }
	if (!this->tasks.empty())
	  {
	    task = this->tasks.front();
	    this->status = ACTIVE;
	    this->tasks.pop();
	    std::cout << "W[" << this << "] Getting task" << std::endl;
	    this->taskLock.unlock();
	    task->process();
	    this->status = FREE;
	  }	    
	else
	  this->taskLock.unlock();
      }
  }

  Worker::eStatus Worker::getStatus(void) const
  {
    return (this->status);
  }
}
