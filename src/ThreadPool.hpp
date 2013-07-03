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
