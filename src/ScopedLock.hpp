#ifndef			SCOPEDLOCK_HH_
# define		SCOPEDLOCK_HH_

# include "ILock.hpp"

namespace		Thread
{
  class			ScopedLock
  {
  private:
    ILock&		lock;

  public:
    ScopedLock(ILock&);
    ~ScopedLock(void);
  };
}

#endif
