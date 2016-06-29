#ifndef LZ_PROCESS_H 
#define LZ_PROCESS_H

#include <iostream>

namespace LZ {

class Process {

  public:

    Process(unsigned pid, 
	    unsigned duration, 
	    unsigned startTime); 

    unsigned pid() const { return d_pid; }
    unsigned duration() const { return d_duration; }
    unsigned startTime() const { return d_startTime; }

    bool run(unsigned *runtime, unsigned quantum);
        // Given 'quantum' and set 'runtime' to actual running time 
	// Return whether the process has ended
    friend std::ostream& operator<< (std::ostream& stream, const Process& prc);

  private:
    unsigned d_pid;
    unsigned d_duration;
    unsigned d_startTime;

};

inline
std::ostream& operator<< (std::ostream& stream, const Process& prc)
{
    stream << "pid: " << prc.pid() << '\n';
    stream << "duration: " << prc.duration() << '\n';
}

} // close namespace

#endif
