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

#ifndef			UNIXCONDVAR_HPP_
# define		UNIXCONDVAR_HPP_

# include <pthread.h>
# include "ICondVar.hpp"
# include "UnixMutex.hpp"

namespace		Thread
{
  class			UnixCondVar : public ICondVar
  {
  public:
    UnixCondVar(UnixMutex & mutex);
    ~UnixCondVar(void);

    virtual void wait(void);
    virtual void wait(int timeout);
    virtual void signal(void);
    virtual void broadcast(void);

  private:
    UnixMutex &		mutex;
    pthread_cond_t	cond;
  };
}

#endif
