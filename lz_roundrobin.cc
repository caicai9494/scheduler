#include <lz_roundrobin.h>

#include <cassert>
#include <cstddef>

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
    /*
    assert(0 != quantum);

    if (d_activeList.empty()) {
	*runtime = 0;
	return false;
    }

    if (d_it == d_activeList.end()) {
	d_it = d_activeList.begin();
    }

    unsigned rtm = 0;
    */
    return false;
}

RoundRobin::PListIt RoundRobin::getNext()
{
    if (empty()) {
	return d_activeList.end();
    }

    if (d_activeList.end() == d_it) {
	d_it = d_activeList.begin();
	return d_it;
    }
    else {
	PListIt& next = ++d_it;
	if (d_activeList.end() == next) {
	    return ++d_it;
	}
	return d_it;
    }
}

void RoundRobin::removeCurrent()
{
}

} // close namespace


