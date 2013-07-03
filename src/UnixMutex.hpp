#ifndef _WIN32
#ifndef			UNIXMUTEX_HPP_
# define		UNIXMUTEX_HPP_

# include <pthread.h>
# include <cstdio>
# include "ILock.hpp"

namespace		Thread
{
  class			UnixMutex : public ILock
  {
    friend class UnixCondVar;

  public:
    UnixMutex(void);
    ~UnixMutex(void);

    virtual void lock(void);
    virtual bool trylock(void);
    virtual void unlock(void);

  protected:
    pthread_mutex_t	mutex;
  };
}

#endif
#endif