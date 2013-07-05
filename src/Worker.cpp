/*
** Copyright (c) 2013 Gauthier Lamaison.
** All rights reserved.
**
** Redistribution and use in source and binary forms are permitted
** provided that the above copyright notice and this paragraph are
** duplicated in all such forms and that any documentation,
**  advertising materials, and other materials related to such
** distribution and use acknowledge that the software was developed
**  by the <organization>.  The name of the
**  <organization> may not be used to endorse or promote products derived
** from this software without specific prior written permission.
** THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
**  IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*/

#include <iostream>
#include "Worker.hpp"

static int g_task_count = 0;

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
	    this->noMoreTaskCond.signal();	
	    this->taskCond.wait();
	  }
	if (!this->tasks.empty())
	  {
	    task = this->tasks.front();
	    this->status = ACTIVE;
	    this->tasks.pop();
	    this->taskLock.unlock();
	    task->process();
	    this->status = FREE;
	    this->taskLock.lock();
	    ++g_task_count;
	    delete task;
	    std::cout << "Total executed " << g_task_count << std::endl;
	    this->taskLock.unlock();
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
