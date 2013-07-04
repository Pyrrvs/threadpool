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
