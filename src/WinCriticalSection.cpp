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

#ifdef		_WIN32
# include <iostream>
# include "WinCriticalSection.hpp"

namespace		Thread
{
  WinCriticalSection::WinCriticalSection(void) 
  {
    InitializeCriticalSection(&this->c_section);
  }

  WinCriticalSection::~WinCriticalSection(void)
  {
    DeleteCriticalSection(&this->c_section);
  }

  void WinCriticalSection::lock(void)
  {
    EnterCriticalSection(&this->c_section);
  }

  bool WinCriticalSection::trylock(void)
  {
    return (!TryEnterCriticalSection(&this->c_section));
  }

  void WinCriticalSection::unlock(void)
  {
    LeaveCriticalSection(&this->c_section);
  }

  WinCriticalSection::operator bool(void) const
  {
    return (!this->error);
  }
}

#endif
