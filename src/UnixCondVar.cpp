#ifndef		_WIN32
# include <iostream>
# include "UnixCondVar.hpp"

namespace			Thread
{
  UnixCondVar::UnixCondVar(UnixMutex & mutex) :
    mutex(mutex)
  {
    if (pthread_cond_init(&this->cond, NULL))
      std::cerr << "pthread_cond_init: failed" << std::endl;
  }

  UnixCondVar::~UnixCondVar(void)
  {
    if (pthread_cond_destroy(&this->cond))
      std::cerr << "pthread_cond_destroy: failed" << std::endl;
  }

  void UnixCondVar::wait(void)
  {
    if (pthread_cond_wait(&this->cond, &this->mutex.mutex))
      std::cerr << "pthread_cond_wait: failed" << std::endl;
  }

  void UnixCondVar::wait(int timeout)
  {
    struct timespec		timer;

    timer.tv_nsec = timeout * 1000000;
    if (pthread_cond_timedwait(&this->cond, &this->mutex.mutex, &timer))
      std::cerr << "pthread_cond_timedwait: failed" << std::endl;
  }

  void UnixCondVar::signal(void)
  {
    if (pthread_cond_signal(&this->cond))
      std::cerr << "pthread_cond_signal: failed" << std::endl;
  }

  void UnixCondVar::broadcast(void)
  {
    if (pthread_cond_broadcast(&this->cond))
      std::cerr << "pthread_cond_broadcast: failed" << std::endl;
  }
}

#endif
