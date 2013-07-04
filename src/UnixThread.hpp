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

#ifndef				UNIXTHREAD_HH_
# define			UNIXTHREAD_HH_

# include <pthread.h>

namespace		Thread
{
  class			UnixThread
  {
  public:
    enum eStatus
      {
	READY,
	STARTED,
	STOPPED
      };

  public:
    UnixThread(void);
    ~UnixThread(void);

    template<typename _funcType>
    void start(_funcType& func);
    template<typename _argType>
    void start(void *(*func)(_argType*), _argType *arg);
    void wait(void);
    void cancel(void);
    void exit(void);
    eStatus getStatus(void) const;

  private:
    template<typename _funcType>
    static void* function(void *arg);

  protected:
    pthread_t		thread;
    eStatus		status;
  };


  template<typename _funcType>
  void* UnixThread::function(void *arg)
  {
    (*reinterpret_cast<_funcType*>(arg))();
    return (0);
  }

  template<typename _funcType>
  void UnixThread::start(_funcType& func)
  {
    if (this->status != STARTED)
      {
	this->status = STARTED;
	if (pthread_create(&this->thread, NULL, &this->function<_funcType>, &func))
	  std::cerr << "pthread_create: failed" << std::endl;
      }
  }

  template<typename _argType>
  void UnixThread::start(void *(*func)(_argType*), _argType *arg)
  {
    if (this->status != STARTED)
      {
	this->status = STARTED;
	if (pthread_create(&this->thread, NULL,
			   reinterpret_cast<void *(*)(void*)>(func), arg))
	  std::cerr << "pthread_create: failed" << std::endl;
      }
  }
}

#endif
