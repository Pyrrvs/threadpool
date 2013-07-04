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
