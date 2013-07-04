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
# include "UnixCondVar.hpp"

namespace			Thread
{
  UnixCondVar::UnixCondVar(UnixMutex & mutex) :
    mutex(mutex)
  {
    if (pthread_cond_init(&this->cond, NULL))
      std::cerr << "pthread_cond_init: failed" << std::endl;
  }

  UnixCondVar::~UnixCondVar(void)
  {
    if (pthread_cond_destroy(&this->cond))
      std::cerr << "pthread_cond_destroy: failed" << std::endl;
  }

  void UnixCondVar::wait(void)
  {
    if (pthread_cond_wait(&this->cond, &this->mutex.mutex))
      std::cerr << "pthread_cond_wait: failed" << std::endl;
  }

  void UnixCondVar::wait(int timeout)
  {
    struct timespec		timer;

    timer.tv_nsec = timeout * 1000000;
    if (pthread_cond_timedwait(&this->cond, &this->mutex.mutex, &timer))
      std::cerr << "pthread_cond_timedwait: failed" << std::endl;
  }

  void UnixCondVar::signal(void)
  {
    if (pthread_cond_signal(&this->cond))
      std::cerr << "pthread_cond_signal: failed" << std::endl;
  }

  void UnixCondVar::broadcast(void)
  {
    if (pthread_cond_broadcast(&this->cond))
      std::cerr << "pthread_cond_broadcast: failed" << std::endl;
  }
}

#endif
