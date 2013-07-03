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
