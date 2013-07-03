#include <iostream>
#include <algorithm>
#include "ThreadPool.hpp"

namespace		Thread
{
  ThreadPool::ThreadPool(size_t nbWorker) :
    taskCond(taskLock), noMoreTaskCond(noMoreTaskLock)
  {
    this->addFreeWorker(nbWorker);
  }

  ThreadPool::~ThreadPool(void)
  {
    std::for_each(this->workers.begin(), this->workers.end(), [](Worker *w) {
	delete w;
      });
  }

  void ThreadPool::addFreeWorker(size_t nb)
  {
    for (size_t i = 0; i < nb; ++i)
      this->workers.push_back(new Worker(this->tasks, this->taskCond, this->taskLock, this->noMoreTaskCond));
  }

  void ThreadPool::removeFreeWorker(size_t nb)
  {
    auto it = this->workers.begin();
    auto end = this->workers.end();

    for (size_t i = 0; i < nb; ++i)
      {
	it = std::find_if(it, end, [](Worker *w) {
	    return (w->getStatus() == Worker::FREE);
	  });
	delete *it;
	it = this->workers.erase(it);
      }
  }

  size_t ThreadPool::getFreeWorkerCount(void) const
  {
    size_t count = 0;

    std::for_each(this->workers.begin(), this->workers.end(), [&count](Worker *w) {
	if (w->getStatus() == Worker::FREE)
	  ++count;
      });
    return (count);
  }

  size_t ThreadPool::getActiveWorkerCount(void) const
  {
    size_t count = 0;

    std::for_each(this->workers.begin(), this->workers.end(), [&count](Worker *w) {
	if (w->getStatus() == Worker::ACTIVE)
	  ++count;
      });
    return (count);
  }

  size_t ThreadPool::getWorkerCount(void) const
  {
    return (this->workers.size());
  }

  void ThreadPool::addTask(ITask* task)
  {
    this->taskLock.lock();
    this->tasks.push(task);
    this->taskLock.unlock();
    this->taskCond.signal();
  }

  bool ThreadPool::isFinished(void) const
  { 
    return (!this->getActiveWorkerCount() && !this->tasks.size());
  }

  void ThreadPool::waitForFinish(void)
  {
    std::cout << "In wait for finish" << std::endl;
    std::cout << "Active workers: " << this->getActiveWorkerCount() << std::endl;
    std::cout << "Tasks: " << this->tasks.size() << std::endl;
    while (this->getActiveWorkerCount() ||
	   this->tasks.size())
      {
	std::cout << "Wait for finish before condwait" << std::endl;
 	std::cout << "Active workers: " << this->getActiveWorkerCount() << std::endl;
	std::cout << "Tasks: " << this->tasks.size() << std::endl;
	this->noMoreTaskCond.wait();
	std::cout << "Wait for finish after condwait" << std::endl;
      }
    std::cout << "Wait for finish done" << std::endl;
    std::cout << "Active workers: " << this->getActiveWorkerCount() << std::endl;
    std::cout << "Tasks: " << this->tasks.size() << std::endl;
  }
}
