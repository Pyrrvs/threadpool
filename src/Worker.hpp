#ifndef			WORKER_HPP_
# define		WORKER_HPP_

# include <queue>
# include "Thread.hpp"
# include "ITask.hpp"
# include "CondVar.hpp"

namespace		Thread
{
  typedef std::queue<ITask *> TaskQueue;

  class			Worker : public Thread
  {
  public:
    enum eStatus
      {
	FREE,
	ACTIVE
      };

  public:
    Worker(TaskQueue & tasks, CondVar & taskCond,
	   Lock & taskLock, CondVar & noMoreTaskCond);
    ~Worker(void);

    void operator()(void);
    eStatus getStatus(void) const;

  private:
    eStatus		status;
    TaskQueue &		tasks;
    CondVar &		taskCond;
    Lock &		taskLock;
    CondVar &		noMoreTaskCond;
  };
}

#endif
