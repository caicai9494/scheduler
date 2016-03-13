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
    std::sort(d_queue.begin(), d_queue.end(), 
	      [&](const Process& lhs, const Process& rhs) { 
	          return lhs.startTime() < lhs.startTime(); 
	      });

    // TODO: add the first process to the schedular
    
    do {
	dispatch();
    } while (d_index != d_queue.size() && !d_queue.empty());
}

void Dispatcher::dispatch()
{
}

} // close namespace


