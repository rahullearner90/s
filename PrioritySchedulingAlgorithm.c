/*
C program that implements the Priority Scheduling algorithm with a preemptive
approach. This program takes user input for the number of processes, their arrival times,
burst times, and priorities.
*/
#include <stdio.h>
#include <stdbool.h>

struct Process {
int pid; 
int arrival; 
int burst; 
int priority; 
int remaining; 
bool completed; 
};

void preemptivePriorityScheduling(struct Process processes[], int n) {
int currentTime = 0;
int completedProcesses = 0;
printf("Time\tProcess\n");
while (completedProcesses < n) {
int highestPriority = 1000; // Highest priority
int highestPriorityIndex = -1;
for (int i = 0; i < n; i++) {
if (!processes[i].completed && processes[i].arrival <= currentTime) {
if (processes[i].priority < highestPriority) {
highestPriority = processes[i].priority;
highestPriorityIndex = i;
}
}
}
if (highestPriorityIndex == -1) {

currentTime++;
} else {

processes[highestPriorityIndex].remaining--;
printf("%d\tP%d\n", currentTime, processes[highestPriorityIndex].pid);
if (processes[highestPriorityIndex].remaining == 0) {

processes[highestPriorityIndex].completed = true;
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
printf("Enter priority for process P%d: ", i + 1);
scanf("%d", &processes[i].priority);
processes[i].remaining = processes[i].burst;
processes[i].completed = false;
}
// Perform preemptive Priority scheduling
preemptivePriorityScheduling(processes, n);
return 0;
}