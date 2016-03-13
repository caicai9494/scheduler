#ifndef LZ_ISCHEDULER_H 
#define LZ_ISCHEDULER_H 

#include <lz_process.h>

namespace LZ {

class IScheduler {

  public:

    IScheduler() {} 
    virtual ~IScheduler() {} 
    virtual bool run(unsigned *runtime, unsigned quantum) = 0;
    virtual void add (Process *prc) = 0;
    virtual bool empty() const = 0;

};

} // close namespace

#endif
