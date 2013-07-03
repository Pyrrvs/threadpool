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
