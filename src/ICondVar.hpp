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
