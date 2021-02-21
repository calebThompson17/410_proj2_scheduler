/*
 * Dispatcher.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */

//TODO fill in content

#include "../includes/dispatcher.h"
#include "constants.h"
#include "CPU.h"

using namespace std;

class Dispatcher {
public:
	Dispatcher(CPU &cpu):cpu(&cpu),is_valid_job_on_cpu(false){};
	virtual ~Dispatcher(){ delete cpu; };

	//pull current process (if any) off CPU and return it
	//if nothing on CPU returns an uninitialized PCB
	PCB get_from_CPU() {
		if (!isValidJobOnCPU()) return PCB();
		return cpu->get_process_off_core();
	}

	//place the current process on the CPU for execution
	void put_on_CPU(PCB  &process) { cpu->put_process_on_core(process); }

	//is CPU idle or working
	bool isValidJobOnCPU() {
		if (cpu->get_COPY_of_Current_Process().isEmpty()) return false;
		return true;
	}
private:
	CPU *cpu; 	//this is initialized from a reference, it cannot be null
	bool is_valid_job_on_cpu;		//set or reset according to whether  there is a job on the CPU
};
