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
