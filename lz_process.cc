#include <lz_process.h>

#include <cassert>

namespace LZ {

Process::Process(unsigned pid, 
	         unsigned duration, 
	         unsigned startTime) :
  d_pid(pid), d_duration(duration), 
  d_startTime(startTime), d_state(State::Ready) {}

bool Process::run(unsigned *runtime, unsigned quantum)
{
    assert(runtime != nullptr);
    assert(quantum > 0);
    assert(d_state != State::Done);

    if (quantum >= d_duration) {
	d_state = State::Done;
	*runtime = d_duration;
	return true;
    }	
    else {
	d_state = State::Running;
	d_duration -= quantum;
	*runtime = quantum;
	return false;
    }
}

} // close namespace


