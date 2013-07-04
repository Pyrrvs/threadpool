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
