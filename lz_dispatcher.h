#ifndef LZ_DISPATCHER_H 
#define LZ_DISPATCHER_H

#include <cassert>
#include <vector>

#include <lz_process.h>
#include <lz_ischeduler.h>

namespace LZ {

class Dispatcher {

  public:
    Dispatcher(IScheduler* scheduler, std::vector<Process>&& prcs, unsigned quantum) :
      d_index(0), 
      d_tick(0), 
      d_quantum(quantum), 
      d_queue(std::move(prcs)), 
      d_scheduler(scheduler) 
    {
        assert(scheduler);
    }

    void start();

  private:
    unsigned d_index;
    unsigned d_tick;
    const unsigned d_quantum;
    std::vector<Process> d_queue;
    IScheduler* d_scheduler;

    void dispatch();
    void addProcess();
};

} // close namespace

#endif
