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

#ifndef			THREADPOOL_HPP_
# define		THREADPOOL_HPP_

# include <list>
# include <queue>
# include "Worker.hpp"
# include "ITask.hpp"
# include "ScopedLock.hpp"

namespace		Thread
{
  typedef std::list<Worker *> WorkerList;
  typedef std::queue<ITask *> TaskQueue;

  class			ThreadPool
  {

  public:
    ThreadPool(size_t nbWorker = 0);
    ~ThreadPool(void);

    void addFreeWorker(size_t nb);
    void removeFreeWorker(size_t nb);
    size_t getFreeWorkerCount(void) const;
    size_t getActiveWorkerCount(void) const;
    size_t getWorkerCount(void) const;
    void addTask(ITask * task);
    void waitForFinish(void);
    bool isFinished(void) const;

  private:
    WorkerList		workers;
    TaskQueue		tasks;
    CondVar		taskCond;
    Lock		taskLock;
    Lock		noMoreTaskLock;
    CondVar		noMoreTaskCond;
  };
}

#endif
