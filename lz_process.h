#ifndef LZ_PROCESS_H 
#define LZ_PROCESS_H

namespace LZ {

class Process {

  public:

    Process(unsigned pid, 
	    unsigned duration, 
	    unsigned startTime); 

    enum class State { Running, Done, Ready };

    unsigned pid() const { return d_pid; }
    unsigned duration() const { return d_duration; }
    unsigned startTime() const { return d_startTime; }

    State state() const { return d_state; }

    bool run(unsigned *runtime, unsigned quantum);
        // Set actual running time and return whether
	// the process is ended

  private:
    unsigned d_pid;
    unsigned d_duration;
    unsigned d_startTime;
    State d_state;

};

} // close namespace

#endif
