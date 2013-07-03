#ifndef			UNIXCONDVAR_HPP_
# define		UNIXCONDVAR_HPP_

# include <pthread.h>
# include "ICondVar.hpp"
# include "UnixMutex.hpp"

namespace		Thread
{
  class			UnixCondVar : public ICondVar
  {
  public:
    UnixCondVar(UnixMutex & mutex);
    ~UnixCondVar(void);

    virtual void wait(void);
    virtual void wait(int timeout);
    virtual void signal(void);
    virtual void broadcast(void);

  private:
    UnixMutex &		mutex;
    pthread_cond_t	cond;
  };
}

#endif
