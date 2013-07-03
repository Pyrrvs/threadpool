#ifndef		_WIN32

# include <iostream>
# include "UnixThread.hpp"

namespace			Thread
{
  UnixThread::UnixThread(void) : status(READY) {}

  UnixThread::~UnixThread(void) {}

  void UnixThread::wait(void)
  {
    if (this->status == STARTED)
      {
	if (pthread_join(this->thread, nullptr))
	  std::cerr << "phtread_join: failed" << std::endl;
	this->status = STOPPED;
      }
  }

  UnixThread::eStatus UnixThread::getStatus(void) const
  {
    return (this->status);
  }

  void UnixThread::cancel(void)
  {
    if (this->status == STARTED)
      {
	if (pthread_cancel(this->thread))
	  std::cerr << "phtread_cancel: failed" << std::endl;
	this->status = STOPPED;
      }
  }

  void UnixThread::exit(void)
  {
    if (this->status == STARTED)
      {
	pthread_exit(nullptr);
	this->status = STOPPED;
      }
  }
}

#endif
