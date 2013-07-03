#ifndef			CONDVAR_HPP_
# define		CONDVAR_HPP_

# include "Lock.hpp"

# ifdef			_WIN32
#  include "WinCondVar.hpp"
# else
#  include "UnixCondVar.hpp"
# endif

namespace		Thread
{

# ifdef			_WIN32
  class			CondVar : public WinCondVar
  {
  public:
    CondVar(Lock & lock) : WinCondVar(lock) {}
  };
# else
  class			CondVar : public UnixCondVar
  {
  public:
    CondVar(Lock & lock) : UnixCondVar(lock) {}
  };
# endif

}

#endif
