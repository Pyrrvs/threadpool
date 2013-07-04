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
# include "UnixThread.hpp"

namespace			Thread
{
  UnixThread::UnixThread(void) : status(READY) {}

  UnixThread::~UnixThread(void) {}

  void UnixThread::wait(void)
  {
    if (this->status == STARTED)
      {
	if (pthread_join(this->thread, nullptr))
	  std::cerr << "phtread_join: failed" << std::endl;
	this->status = STOPPED;
      }
  }

  UnixThread::eStatus UnixThread::getStatus(void) const
  {
    return (this->status);
  }

  void UnixThread::cancel(void)
  {
    if (this->status == STARTED)
      {
	if (pthread_cancel(this->thread))
	  std::cerr << "phtread_cancel: failed" << std::endl;
	this->status = STOPPED;
      }
  }

  void UnixThread::exit(void)
  {
    if (this->status == STARTED)
      {
	pthread_exit(nullptr);
	this->status = STOPPED;
      }
  }
}

#endif
