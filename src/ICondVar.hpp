#ifndef			ICONDVAR_HH_
# define		ICONDVAR_HH_

# include "ILock.hpp"

namespace		Thread
{
  class			ICondVar
  {
  public:
    virtual ~ICondVar(void) {}

    virtual void wait(void) = 0;
    virtual void wait(int timeout) = 0;
    virtual void signal(void) = 0;
    virtual void broadcast(void) = 0;
  };
}

#endif
