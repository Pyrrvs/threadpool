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

#ifndef		_WIN32
# include <iostream>
# include "UnixMutex.hpp"

namespace		Thread
{
  UnixMutex::UnixMutex(void)
  {
    if (pthread_mutex_init(&this->mutex, NULL) != 0)
      std::cerr << "pthread_mutex_init: failed" << std::endl;
  }

  UnixMutex::~UnixMutex(void)
  {
    if (pthread_mutex_destroy(&this->mutex) != 0)
      std::cerr << "pthread_mutex_destroy: failed" << std::endl;
  }

  void UnixMutex::lock(void)
  {
    if (pthread_mutex_lock(&this->mutex) != 0)
      std::cerr << "pthread_mutex_lock: failed" << std::endl;
  }

  bool UnixMutex::trylock(void)
  {
    return (!pthread_mutex_trylock(&this->mutex));
  }

  void UnixMutex::unlock(void)
  {
    if (pthread_mutex_unlock(&this->mutex) != 0)
      std::cerr << "pthread_mutex_unlock: failed" << std::endl;
  }
}

#endif
