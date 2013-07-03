#ifndef			THREAD_HPP_
# define		THREAD_HPP_

# include "AbstractThread.hpp"

# ifdef			_WIN32
#  include "WinThread.hpp"
# else
#  include "UnixThread.hpp"
# endif

namespace		Thread
{
# ifdef			_WIN32

  class			Thread : public AbstractThread<WinThread>
  {
  public:
    Thread(void) {}
    ~Thread(void) {}
  };
# else

  class			Thread : public AbstractThread<UnixThread>
  {
  public:
    Thread(void) {}
    ~Thread(void) {}
  };
# endif

}

#endif
