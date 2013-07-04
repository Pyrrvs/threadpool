/*
** Copyright (c) 2013 Gauthier Lamaison.
** All rights reserved.
**
** Redistribution and use in source and binary forms are permitted
** provided that the above copyright notice and this paragraph are
** duplicated in all such forms and that any documentation,
**  advertising materials, and other materials related to such
** distribution and use acknowledge that the software was developed
**  by the <organization>.  The name of the
**  <organization> may not be used to endorse or promote products derived
** from this software without specific prior written permission.
** THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
**  IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*/

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
