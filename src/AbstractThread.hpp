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

#ifndef			ABSTRACTTHREAD_HPP_
# define		ABSTRACTTHREAD_HPP_

namespace		Thread
{
  template<typename _impl>
  class			AbstractThread
  {
  public:
    typedef typename _impl::eStatus eStatus;

  public:
    AbstractThread(void);
    ~AbstractThread(void);

    template<typename _funcType>
    void start(_funcType& func);
    template<typename _argType>
    void start(void * (*func)(_argType *), _argType * arg);
    void wait(void);
    void cancel(void);
    void exit(void);
    eStatus getStatus(void) const;

  private:
    _impl	impl;
  };

  template<typename _impl>
  AbstractThread<_impl>::AbstractThread(void)
  {
  }

  template<typename _impl>
  AbstractThread<_impl>::~AbstractThread(void)
  {
  }

  template<typename _impl>
  template<typename _funcType>
  void AbstractThread<_impl>::start(_funcType & function)
  {
    this->impl.start<_funcType>(function);
  }

  template<typename _impl>
  template<typename _argType>
  void AbstractThread<_impl>::start(void * (*func)(_argType *), _argType * arg)
  {
    this->impl.start<_argType>(func, arg);
  }

  template<typename _impl>
  void AbstractThread<_impl>::wait(void)
  {
    this->impl.wait();
  }

  template<typename _impl>
  void AbstractThread<_impl>::cancel(void)
  {
    this->impl.cancel();
  }

  template<typename _impl>
  void AbstractThread<_impl>::exit(void)
  {
    this->impl.exit();
  }

  template<typename _impl>
  typename AbstractThread<_impl>::eStatus AbstractThread<_impl>::getStatus(void) const
  {
    return (this->getStatus());
  }
}
#endif
