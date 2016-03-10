#ifndef LZ_PROCESS_H 
#define LZ_PROCESS_H

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
        // Set actual running time and return whether
	// the process is ended

  private:
    unsigned d_pid;
    unsigned d_duration;
    unsigned d_startTime;

};

} // close namespace

#endif
