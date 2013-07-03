#ifndef			ILOCK_HPP_
# define		ILOCK_HPP_

namespace		Thread
{
  class			ILock
  {
  public:
    virtual ~ILock(void) {}

    virtual void lock(void) = 0;
    virtual bool trylock(void) = 0;
    virtual void unlock(void) = 0;
  };
}

#endif
