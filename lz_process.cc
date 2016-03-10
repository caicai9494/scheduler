#include <lz_process.h>

#include <cassert>

namespace LZ {

Process::Process(unsigned pid, 
	         unsigned duration, 
	         unsigned startTime) :
  d_pid(pid), d_duration(duration), 
  d_startTime(startTime) {}

bool Process::run(unsigned *runtime, unsigned quantum)
{
    assert(runtime != nullptr);
    assert(quantum > 0);

    if (quantum >= d_duration) {
	*runtime = d_duration;
	return true;
    }	
    else {
	d_duration -= quantum;
	*runtime = quantum;
	return false;
    }
}

} // close namespace


