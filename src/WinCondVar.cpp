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

#ifdef			_WIN32

# include "WinCondVar.hpp"

namespace		Thread
{
  WinCondVar::WinCondVar(WinCriticalSection & c_section) :
    c_section(c_section)
  {
    InitializeConditionVariable(&this->cond);
  }

  WinCondVar::~WinCondVar(void)
  {
  }

  void WinCondVar::wait(void)
  {
    if (!SleepConditionVariableCS(&this->cond, &this->c_section.c_section, INFINITE))
      std::cerr << "SleepConditionVariableCS: failed" << std::endl;
 }

  void WinCondVar::wait(int timeout)
  {
    if (!SleepConditionVariableCS(&this->cond, &this->c_section.c_section, timeout))
      std::cerr << "SleepConditionVariableCS: failed" << std::endl;
  }

  void WinCondVar::signal(void)
  {
    WakeConditionVariable(&this->cond);
  }

  void WinCondVar::broadcast(void)
  {
    WakeAllConditionVariable(&this->cond);
  }
}

#endif
