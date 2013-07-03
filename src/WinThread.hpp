#ifndef			WINTHREAD_HPP_
# define		WINTHREAD_HPP_

# include <Windows.h>

namespace		Thread
{
  class		WinThread
  {
  public:
    enum eStatus
      {
	READY,
	STARTED,
	STOPPED
      };

  public:
    WinThread(void);
    ~WinThread(void);

    template<typename _funcType>
    void start(_funcType& func);
    template<typename _argType>
    void start(void * (*func)(_argType *), _argType * arg);
    void wait(void);
    void cancel(void);
    void exit(void);
    eStatus getStatus(void) const;

  private:
    template<typename _funcType>
    static DWORD WINAPI function(LPVOID arg);
    void printLastErrorMsg(void) const;

  private:
    DWORD		tid;
    HANDLE		handle;
    eStatus		status;
  };

  template<typename _funcType>
  DWORD WINAPI WinThread::function(LPVOID arg)
  {
    (*reinterpret_cast<_funcType *>(arg))();
    return (0);
  }

  template<typename _funcType>
  void WinThread::start(_funcType & func)
  {
    if (this->status != STARTED)
      {
	this->status = STARTED;
	this->handle = CreateThread(nullptr, 0, this->function<_funcType>, &func, 0, &this->tid);
      }
  }

  template<typename _argType>
  void WinThread::start(void *(*func)(_argType * arg), _argType * arg)
  {
    if (this->status != STARTED)
      {
	this->status = STARTED;
	this->handle = CreateThread(nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(func), arg, 0, &this->tid);
      }
  }
}

#endif			/*!WINTHREAD_HPP*/
