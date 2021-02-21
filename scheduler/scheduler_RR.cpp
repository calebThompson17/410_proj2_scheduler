/*
 * SchedulerSTRR.cpp
 *
 *  Created on: Sep 7, 2019
 *      Author: keith
 *
 *      implements round robin scheduling algorithm
 *      pre-emptive
 */

//TODO fill in content

#include "../includes/scheduler_RR.h"
#include "../includes/scheduler.h"

//override base class behaviour if necessary, otherwise call it
bool  Scheduler_RR::time_to_switch_processes(int tick_count, PCB &p)
{ return Scheduler::time_to_switch_processes(tick_count, p); }

//RR - preemptive - no sorting of ready_q needed.
void Scheduler_RR::sort() {}

//class Scheduler_RR: public Scheduler {
//public:
//
//	//this is a preemptive scheduler,set the preemptive member variable to true
//	//when calling the base class
//	Scheduler_RR(std::queue<PCB> &queue,int time_slice =UNINITIALIZED):Scheduler(queue,true,time_slice){};
//	virtual ~Scheduler_RR(): ~Scheduler() {};
//
//	//override base class behaviour if necessary, otherwise call it
//	virtual bool  time_to_switch_processes(int tick_count, PCB &p)
//	{ return Scheduler::time_to_switch_processes(tick_count, p); }
//
//	//RR - preemptive - no sorting of ready_q needed.
//	virtual void sort();
//};
