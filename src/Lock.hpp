#ifndef			LOCK_HPP_
# define		LOCK_HPP_

# ifdef			_WIN32
#  include "WinCriticalSection.hpp"
# else
#  include "UnixMutex.hpp"
# endif


namespace		Thread
{

# ifdef			_WIN32
  class			Lock : public WinCriticalSection
  {
  };
# else
  class			Lock : public UnixMutex
  {
  };
# endif

}

#endif
