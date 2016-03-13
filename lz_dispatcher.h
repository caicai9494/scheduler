#ifndef LZ_DISPATCHER_H 
#define LZ_DISPATCHER_H

#include <vector>

#include <lz_process.h>

namespace LZ {

class Dispatcher {

  public:
    Dispatcher(std::vector<Process>&& prcs) :
      d_index(0), d_tick(0), d_queue(std::move(prcs)) {}

    void start();

  private:
    unsigned d_index;
    unsigned d_tick;
    std::vector<Process> d_queue;

    void dispatch();
};

} // close namespace

#endif
