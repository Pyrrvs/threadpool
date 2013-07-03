#ifndef		_WIN32
# include <iostream>
# include "UnixMutex.hpp"

namespace		Thread
{
  UnixMutex::UnixMutex(void)
  {
    if (pthread_mutex_init(&this->mutex, NULL) != 0)
      std::cerr << "pthread_mutex_init: failed" << std::endl;
  }

  UnixMutex::~UnixMutex(void)
  {
    if (pthread_mutex_destroy(&this->mutex) != 0)
      std::cerr << "pthread_mutex_destroy: failed" << std::endl;
  }

  void UnixMutex::lock(void)
  {
    if (pthread_mutex_lock(&this->mutex) != 0)
      std::cerr << "pthread_mutex_lock: failed" << std::endl;
  }

  bool UnixMutex::trylock(void)
  {
    return (!pthread_mutex_trylock(&this->mutex));
  }

  void UnixMutex::unlock(void)
  {
    if (pthread_mutex_unlock(&this->mutex) != 0)
      std::cerr << "pthread_mutex_unlock: failed" << std::endl;
  }
}

#endif
