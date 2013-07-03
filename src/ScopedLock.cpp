#include "ScopedLock.hpp"

namespace			Thread
{
  ScopedLock::ScopedLock(ILock& lock) :
    lock(lock)
  {
    this->lock.lock();
  }

  ScopedLock::~ScopedLock(void)
  {
    this->lock.unlock();
  }
}
