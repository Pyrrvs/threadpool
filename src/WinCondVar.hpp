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
