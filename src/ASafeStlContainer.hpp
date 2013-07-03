#ifndef				ASAFESTLCONTAINER_HH_
# define			ASAFESTLCONTAINER_HH_

# include "ASafeContainer.hpp"
# include "ScopedLock.hpp"

namespace			Thread
{
  template<typename StlContainer>
  class	ASafeStlContainer : public ASafeContainer<typename
				 StlContainer::value_type>,
			    private StlContainer
  {
  public:
    typedef typename StlContainer::value_type T;

  public:
    ASafeStlContainer(void) {}
    virtual ~ASafeStlContainer(void) {}

    virtual void push(T value)
    {
      ScopedLock		lock(this->lock);

      StlContainer::push_back(value);
      this->cond.signal();
    }

    virtual T pop(void)
    {
      ScopedLock		lock(this->lock);
      T				value;

      if (StlContainer::empty())
	this->cond.wait(this->lock);
      value = StlContainer::front();
      StlContainer::pop_front();
      return (value);
    }

    virtual bool tryPop(T* value)
    {
      ScopedLock		lock(this->lock);

      if (StlContainer::empty())
	return (false);
      *value = StlContainer::front();
      StlContainer::pop_front();
      return (true);
    }

    virtual int size(void) const
    {
      return (StlContainer::size());
    }

    virtual bool empty(void) const
    {
      return (StlContainer::empty());
    }
  };
}

#endif
