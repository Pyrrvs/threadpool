#ifndef			WINCRITICALSECTION_HPP_
# define		WINCRITICALSECTION_HPP_

# include <Windows.h>
# include "ILock.hpp"

namespace		Thread
{
  class			WinCriticalSection : public ILock
  {
    friend class WinCondVar;

  public:
    WinCriticalSection(void);
    ~WinCriticalSection(void);

    virtual void lock(void);
    virtual bool trylock(void);
    virtual void unlock(void);

    virtual operator bool(void) const;

  protected:
    CRITICAL_SECTION	c_section;
    bool 	 	error;
  };
}

#endif
