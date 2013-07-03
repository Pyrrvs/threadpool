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
    this->lock.lock();
    std::cout << "Hell yeah" << std::endl;
    this->lock.unlock();
# ifdef _WIN32
  Sleep(2000);
# else
  sleep(2000);
# endif
  }

private:
  Thread::Lock &	lock;
};

void test(void)
{
  Thread::ThreadPool threadPool(4);
  Thread::Lock lock;

  for (int i = 0; i < 12; ++i)
    threadPool.addTask(new Toto(lock));
# ifdef _WIN32
  Sleep(6000);
# else
  sleep(6000);
# endif
}

int main(void)
{
  test();
  return (0);
}
