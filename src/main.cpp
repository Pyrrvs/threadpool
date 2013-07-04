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

#include <iostream>
#include <unistd.h>

#include "ThreadPool.hpp"
#include "SafeStl.hpp"

class Toto : public Thread::ITask
{
public:
  Toto(Thread::Lock & lock) : lock(lock) {}
  ~Toto(void) {}

  virtual void process(void)
  {
    // this->lock.lock();
    // std::cout << "Processing..." << std::endl;
    // this->lock.unlock();
# ifdef _WIN32
  Sleep(2000);
# else
  usleep(random() % 1000);
# endif
    // this->lock.lock();
    // std::cout << "Done processing" << std::endl;
    // this->lock.unlock();
  }

private:
  Thread::Lock &	lock;
};

void test(void)
{
  Thread::ThreadPool threadPool(10);
  Thread::Lock lock;

  for (int i, j = 0; j < 10; ++j) {
    for (i = 0; i < 50; ++i)
      threadPool.addTask(new Toto(lock));
    lock.lock();
    std::cout << "[" << threadPool.getActiveWorkerCount() << "] / ["
	      << threadPool.getWorkerCount() << "]" << std::endl;
    lock.unlock();
  }
  threadPool.waitForFinish();
}
#include <time.h>

int main(void)
{
  srandom(time(NULL));
  test();
  return (0);
}
