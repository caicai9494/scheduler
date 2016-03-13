#ifndef LZ_ROUNDROBIN_H 
#define LZ_ROUNDROBIN_H

#include <list>

#include <lz_ischeduler.h>

namespace LZ {

class RoundRobin : public IScheduler {

  public:

    typedef std::list<Process*> PList;
    typedef PList::iterator PListIt;

    RoundRobin();

    void add(Process *prc) override;

    bool run(unsigned *runtime, unsigned quantum) override;

    bool empty() const override;

  private:

    PList d_activeList;
    PListIt d_it;

    PListIt getNext();
    void removeCurrent();



};

inline
bool RoundRobin::empty() const { return d_activeList.empty(); }

} // close namespace

#endif
