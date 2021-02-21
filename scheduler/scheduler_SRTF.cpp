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
#include "../includes/scheduler.h"
#include <algorithm>
#include <vector>

using namespace std;

//override base class behaviour if necessary, otherwise call it
bool Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p) {
	sort();
	return Scheduler::time_to_switch_processes(tick_count, p);
}

//// adding the sort method call
//void Scheduler_SRTF::Scheduler::add(PCB p) {
//	Scheduler::add(p);
//	sort();
//}

// Sort by remaining_CPU_Time
bool remainingCPUTimeSort(PCB p1, PCB p2) {
	return p1.remaining_cpu_time < p2.remaining_cpu_time;
}

//SRTF-preemptive - sort ready_q by remaining_cpu_time whenever add(PCB p) or time_to_switch_processes is called
void Scheduler_SRTF::sort() {
	vector<PCB> vec;
	while (!ready_q->empty()) {
		vec.push_back(ready_q->front());
		ready_q->pop();
	}
	std::sort(vec.begin(), vec.end(), remainingCPUTimeSort);
	while (!vec.empty()) {
		ready_q->push(vec.front());
		vec.erase(vec.begin());
	}
//	delete vec;
}

//class Scheduler_SRTF: public Scheduler {
//public:
//	//this is a  preemptive scheduler, so set the preemptive member variable to true
//	//when calling the base class
//	Scheduler_SRTF(std::queue<PCB> &queue):Scheduler(queue,true,UNINITIALIZED){};
//	virtual ~Scheduler_SRTF(): ~Scheduler() {};
//
//	//override base class behaviour if necessary, otherwise call it
//	virtual bool  time_to_switch_processes(int tick_count, PCB &p) {
//		sort();
//		return Scheduler::time_to_switch_processes(tick_count, p);
//	}
//
//	// adding the sort method call
//	virtual void add(PCB p) {
//		Scheduler::add(p);
//		sort();
//	}
//
//	// Sort by remaining_CPU_Time
//	bool remainingCPUTimeSort(PCB p1, PCB p2) {
//		return p1.remaining_cpu_time < p2.remaining_cpu_time;
//	}
//
//	//SRTF-preemptive - sort ready_q by remaining_cpu_time whenever add(PCB p) or time_to_switch_processes is called
//	virtual void sort() {
//		vector<PCB> vec;
//		while (!ready_q->empty()) {
//			vec.push_back(ready_q->front());
//			ready_q->pop();
//		}
//		std::sort(vec.begin(), vec.end(), remainingCPUTimeSort);
//		while (!vec.empty()) {
//			ready_q->push(vec.front());
//			vec.erase(vec.begin());
//		}
//		delete vec;
//	}
//};
