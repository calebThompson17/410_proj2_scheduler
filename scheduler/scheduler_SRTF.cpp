/*
 * SchedulerSRTF.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 *
 *      implements shortest remaining time first scheduling algorithm
 *     pre-emptive
 */

//TODO fill in content

#include "../includes/scheduler_SRTF.h"
#include "scheduler.h"
#include <vector>

class Scheduler_SRTF: public Scheduler {
public:
	//this is a  preemptive scheduler, so set the preemptive member variable to true
	//when calling the base class
	Scheduler_SRTF(std::queue<PCB> &queue):Scheduler(queue,true,UNINITIALIZED){};
	virtual ~Scheduler_SRTF(): ~Scheduler() {};

	//override base class behaviour if necessary, otherwise call it
	virtual bool  time_to_switch_processes(int tick_count, PCB &p)
	{ return Scheduler::time_to_switch_processes(tick_count, p); }

	//SRTF-preemptive - sort ready_q by remaining_cpu_time whenever add(PCB p) or time_to_switch_processes is called
	virtual void sort() {
		vector<PCB> vec;
	}
};
