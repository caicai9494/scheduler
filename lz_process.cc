#include <lz_process.h>

#include <cassert>

namespace LZ {

Process::Process(unsigned pid, 
	         unsigned duration, 
	         unsigned startTime) :
  d_pid(pid), d_duration(duration), 
  d_startTime(startTime), d_state(State::Ready) {}

unsigned Process::run(unsigned quantum)
{
    assert(quantum > 0);
    assert(d_state == State::Ready);

    if (quantum >= d_duration) {
	d_state = State::Done;
	return d_duration;
    }	
    else {
	d_duration -= quantum;
	return quantum;
    }
}

} // close namespace


