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
# include "WinThread.hpp"

namespace		Thread
{
  WinThread::WinThread(void) :
    tid(0)
  {
  }

  WinThread::~WinThread(void)
  {
  }

  void WinThread::wait(void)
  {
    if (this->status == STARTED)
      {
	WaitForSingleObject(this->handle, INFINITE);
	this->status = STOPPED;
      }
  }

  void WinThread::printLastErrorMsg(void) const
  {
    DWORD	dw = GetLastError();
    LPVOID	lpMsgBuf;

    FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
		  FORMAT_MESSAGE_FROM_SYSTEM |
		  FORMAT_MESSAGE_IGNORE_INSERTS,
		  NULL,
		  dw,
		  MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		  (LPSTR)&lpMsgBuf,
		  0, NULL);
    std::cerr << static_cast<LPSTR>(lpMsgBuf) << std::endl;
    LocalFree(lpMsgBuf);
  }

  void WinThread::cancel(void)
  {

    if (this->status == STARTED)
      {
	if (TerminateThread(this->handle, 0) == 0)
	  printLastErrorMsg();
	else
	  this->status = STOPPED;
      }
  }

  void WinThread::exit(void)
  {
    if (this->status == STARTED)
      {
	ExitThread(0);
	this->status = STOPPED;
      }
  }
}

#endif
