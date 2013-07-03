#ifndef				WINCONDVAR_HPP_
# define			WINCONDVAR_HPP_

# include <Windows.h>
# include "ICondVar.hpp"
# include "WinCriticalSection.hpp"

namespace			Thread
{
  class			WinCondVar : public ICondVar
  {
  public:
    WinCondVar(WinCriticalSection & mutex);
    ~WinCondVar(void);

    virtual void wait(void);
    virtual void wait(int timeout);
    virtual void signal(void);
    virtual void broadcast(void);

  private:
    WinCriticalSection &	c_section;
    CONDITION_VARIABLE		cond;
  };
}

#endif
