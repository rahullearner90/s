/*
C program that implements the Shortest Remaining Time First (SRTF) scheduling
algorithm, which is also known as Shortest Job First (SJF) with preemption. This
program takes user input for the number of processes, their arrival times, burst times,
and then simulates the SRTF scheduling algorithm
*/
#include <stdio.h>
#include <stdbool.h>

struct Process {
int pid; 
int arrival; 
int burst; 
int remaining; 
bool completed; 
};

void SRTFScheduling(struct Process processes[], int n) {
int currentTime = 0;
int completedProcesses = 0;
printf("Time\tProcess\n");
while (completedProcesses < n) {
int shortestRemainingTime = 1000; // Initialize with a large value
int shortestProcessIndex = -1;
for (int i = 0; i < n; i++) {
if (!processes[i].completed && processes[i].arrival <= currentTime) {
if (processes[i].remaining < shortestRemainingTime) {
shortestRemainingTime = processes[i].remaining;
shortestProcessIndex = i;
}
}
}
if (shortestProcessIndex == -1) {

currentTime++;
} else {

processes[shortestProcessIndex].remaining--;
printf("%d\tP%d\n", currentTime, processes[shortestProcessIndex].pid);
if (processes[shortestProcessIndex].remaining == 0) {

processes[shortestProcessIndex].completed = true;
completedProcesses++;
}
currentTime++;
}
}
}
int main() {
int n;
printf("Enter the number of processes: ");
scanf("%d", &n);
struct Process processes[n];
// Input process details
for (int i = 0; i < n; i++) {
processes[i].pid = i + 1;
printf("Enter arrival time for process P%d: ", i + 1);
scanf("%d", &processes[i].arrival);
printf("Enter burst time for process P%d: ", i + 1);
scanf("%d", &processes[i].burst);
processes[i].remaining = processes[i].burst;
processes[i].completed = false;
}

SRTFScheduling(processes, n);
return 0;
}