#include <lz_dispatcher.h>

#include <algorithm>
#include <iostream>

namespace LZ {

void Dispatcher::start()
{
    if (d_queue.empty()) {
	std::cout << "Info: no process in the queue\n";
	return;
    }

    // sort 'Process' in ascending order or 'startTime' attribute
    // so that we simulate processes being added to the queue 
    std::sort(d_queue.begin(), d_queue.end(), 
	      [&](const Process& lhs, const Process& rhs) { 
	          return lhs.startTime() < lhs.startTime(); 
	      });

    // add the first process to the schedular
    d_scheduler->add(&d_queue[0]);
    d_tick = d_queue[0].startTime();
    ++d_index;
    
    do {
	addProcess();
	dispatch();
	// one tick for dispatcher itself
	++d_tick;
    } while (!d_scheduler->empty() || d_index != d_queue.size());
}

void Dispatcher::dispatch()
{
    d_tick += d_quantum;
    Process* nxtProcess = d_scheduler->next();
    // idle
    if (!nxtProcess) {
	d_tick -= d_quantum;
	return; 
    }
    unsigned runtime = 0;
    const bool ret = nxtProcess->run(&runtime, d_quantum);
    if (ret) { // ended
	d_scheduler->removeCurrent();
	std::cout << nxtProcess->pid();
	std::cout << " process finished.\n";
    }
    d_tick -= (d_quantum - runtime);

    std::cout << *nxtProcess;
    std::cout << "tick: " << d_tick << "\n\n";
}

void Dispatcher::addProcess()
{
    // all processes are in the scheduler
    // or next process is saved for later
    if (d_index >= d_queue.size() || d_tick < d_queue[d_index].startTime()) {
	return;
    }
    while (d_index < d_queue.size() && d_queue[d_index].startTime() <= d_tick) {
	Process* nxtProcess = &d_queue[d_index++];
	d_scheduler->add(nxtProcess);
    }
    //}
}

} // close namespace


