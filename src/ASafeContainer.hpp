#ifndef			ASAFECONTAINER_HH_
# define		ASAFECONTAINER_HH_

# include "ICondVar.hpp"

namespace		Thread
{
  template<typename T>
  class			ASafeContainer
  {
  public:
    ASafeContainer(void) {}
    virtual ~ASafeContainer(void) {}

    virtual void push(T value) = 0;
    virtual T pop(void) = 0;
    virtual bool tryPop(T* value) = 0;
    virtual int size(void) const = 0;
    virtual bool empty(void) const = 0;

  protected:
    Lock		lock;
    CondVar		cond;
  };
}

#endif
