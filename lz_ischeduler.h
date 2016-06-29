#ifndef LZ_ISCHEDULER_H 
#define LZ_ISCHEDULER_H 

#include <lz_process.h>

namespace LZ {

class IScheduler {

  public:

    virtual ~IScheduler() {} 
    virtual Process* next() = 0;
    virtual void add (Process *prc) = 0;
    virtual bool empty() const = 0;
    virtual void removeCurrent() = 0;

};

} // close namespace

#endif
