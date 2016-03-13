#include <lz_roundrobin.h>

#include <cassert>

namespace LZ {

RoundRobin::RoundRobin() : 
  d_it(d_activeList.end()) {}

void RoundRobin::add(Process *prc) 
{
    assert(NULL != prc);

    d_activeList.push_back(prc);
}

bool RoundRobin::run(unsigned *runtime, unsigned quantum) 
{
    assert(0 != quantum);

    if (d_activeList.empty()) {
	*runtime = 0;
	return false;
    }

    if (d_it == d_activeList.end()) {
	d_it = d_activeList.begin();
    }

    unsigned runtime = 0;
    const bool ret = d_it->run(&runtime, quantum);
    
}

PListIt RoundRobin::getNext()
{
    if (empty()) {
	return d_activeList.end()
    }

    if (d_it == d_activeList.end()) {
	
    }
}

void RoundRobin::removeCurrent()
{
}

} // close namespace


