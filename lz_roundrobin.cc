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

Process* RoundRobin::next()
{
    if (empty()) {
	return NULL;
    }

    if (d_it == d_activeList.end()) {
	++d_it;
    }
    return *(d_it++);
}

void RoundRobin::removeCurrent()
{
    if (empty()) {
	return;
    }

    // d_it points to end
    // we erase next item
    if (d_it == d_activeList.end()) {
	++d_it;
    }

    auto cpy = d_it;
    ++cpy;
    d_activeList.erase(d_it);
    d_it = cpy;
}

} // close namespace


