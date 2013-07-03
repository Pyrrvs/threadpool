#ifdef		_WIN32
# include <iostream>
# include "WinCriticalSection.hpp"

namespace		Thread
{
  WinCriticalSection::WinCriticalSection(void) 
  {
    InitializeCriticalSection(&this->c_section);
  }

  WinCriticalSection::~WinCriticalSection(void)
  {
    DeleteCriticalSection(&this->c_section);
  }

  void WinCriticalSection::lock(void)
  {
    EnterCriticalSection(&this->c_section);
  }

  bool WinCriticalSection::trylock(void)
  {
    return (!TryEnterCriticalSection(&this->c_section));
  }

  void WinCriticalSection::unlock(void)
  {
    LeaveCriticalSection(&this->c_section);
  }

  WinCriticalSection::operator bool(void) const
  {
    return (!this->error);
  }
}

#endif
