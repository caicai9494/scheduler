#ifndef LZ_ROUNDROBIN_H 
#define LZ_ROUNDROBIN_H

#include <list>

#include <lz_ischeduler.h>

namespace LZ {

class RoundRobin : public IScheduler {

  public:

    typedef std::list<Process*> PList;

    RoundRobin();

    ~RoundRobin() {}

    void add(Process *prc) override;

    bool run(unsigned *runtime, unsigned quantum) override;

  private:

    PList d_activeList;
    PList::iterator d_it;

};

} // close namespace

#endif
