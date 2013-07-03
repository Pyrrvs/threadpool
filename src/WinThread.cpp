#ifdef		_WIN32

# include <iostream>
# include "WinThread.hpp"

namespace		Thread
{
  WinThread::WinThread(void) :
    tid(0)
  {
  }

  WinThread::~WinThread(void)
  {
  }

  void WinThread::wait(void)
  {
    if (this->status == STARTED)
      {
	WaitForSingleObject(this->handle, INFINITE);
	this->status = STOPPED;
      }
  }

  void WinThread::printLastErrorMsg(void) const
  {
    DWORD	dw = GetLastError();
    LPVOID	lpMsgBuf;

    FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
		  FORMAT_MESSAGE_FROM_SYSTEM |
		  FORMAT_MESSAGE_IGNORE_INSERTS,
		  NULL,
		  dw,
		  MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		  (LPSTR)&lpMsgBuf,
		  0, NULL);
    std::cerr << static_cast<LPSTR>(lpMsgBuf) << std::endl;
    LocalFree(lpMsgBuf);
  }

  void WinThread::cancel(void)
  {

    if (this->status == STARTED)
      {
	if (TerminateThread(this->handle, 0) == 0)
	  printLastErrorMsg();
	else
	  this->status = STOPPED;
      }
  }

  void WinThread::exit(void)
  {
    if (this->status == STARTED)
      {
	ExitThread(0);
	this->status = STOPPED;
      }
  }
}

#endif
