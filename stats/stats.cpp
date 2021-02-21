/*
 * Stats.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 */

//TODO fill in content

#include "../includes/stats.h"
#include "../includes/PCB.h"
#include <iostream>
#include <vector>

using namespace std;

Stats::Stats(std::vector<PCB> &finished_vector):
				vec(finished_vector) { calcStats(); }

virtual Stats::~Stats() { delete vec; }

//loops thru vec, prints 1 line for each process using the following format
//Process 1 Required CPU time:2  arrived:0 started:0 finished:2
//if there are 10 processes in vector, should print 10 lines
void Stats::showAllProcessInfo() {
	for (auto& it: vec) {
		cout << "Process " << it.process_number <<
				" Required CPU time: " << it.required_cpu_time <<
				" arrived: " << it.arrival_time <<
				" started: " << it.start_time <<
				" finished: " << it.finish_time << endl;
	}
}

//after a process is placed in the ready_q, how long does
//it take before its placed on the processor?
//response_time per process = start_time - arrival_time
//this funtion returns the average over all processes
float Stats::get_av_response_time() { return av_response_time; }

//after a process is placed in the ready_q, how long does
//it take to complete?
//turnaround time per process = finish_time - arrival_time
//this funtion returns the average over all processes
float Stats::get_av_turnaround_time() { return av_turnaround_time; }

//after a process is placed in the ready_q, how much time does it
//spend waiting for processor time?
//wait time per process = finish_time - arrival_time-required_CPU_time
//this funtion returns the average over all processes
float Stats::get_av_wait_time() { return av_wait_time; }

//does the work (only needs to run once)
void Stats::calcStats() {
	av_wait_time = 0.0;
	av_turnaround_time = 0.0;
	av_response_time = 0.0;
	for (auto& it: vec) {
		av_wait_time += it.finish_time - it.arrival_time - it.required_cpu_time;
		av_turnaround_time += it.finish_time - it.arrival_time;
		av_response_time += it.start_time - it.arrival_time;
	}
	av_wait_time /= vec->size();
	av_turnaround_time /= vec->size();
	av_response_time /= vec->size();
}



