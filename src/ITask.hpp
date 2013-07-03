#ifndef			ITASK_HPP_
# define		ITASK_HPP_

namespace		Thread
{
  class			ITask
  {
  public:
    virtual ~ITask(void) {}

    virtual void process(void) = 0;
  };
}

#endif
