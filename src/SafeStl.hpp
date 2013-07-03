#ifndef				SAFESTL_HH_
# define			SAFESTL_HH_

# include <list>
# include <vector>
# include <deque>

# include "ASafeStlContainer.hpp"

namespace			Thread
{
  template<typename T>
  struct SafeList : public ASafeStlContainer<std::list<T> > {};

  template<typename T>
  struct SafeVector : public ASafeStlContainer<std::vector<T> > {};

  template<typename T>
  struct SafeDeque : public ASafeStlContainer<std::deque<T> > {};
}

#endif
