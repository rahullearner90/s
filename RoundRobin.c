/*
C program that implements the Round-Robin (RR) scheduling algorithm with preemptive
behavior. This program takes user input for the number of processes, their arrival times,
burst times, and the time quantum.
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

void preemptiveRoundRobinScheduling(struct Process processes[], int n, int time_quantum) {
int currentTime = 0;
int completedProcesses = 0;
printf("Time\tProcess\n");
while (completedProcesses < n) {
for (int i = 0; i < n; i++) {
if (!processes[i].completed && processes[i].arrival <= currentTime) {
int execution_time = (processes[i].remaining < time_quantum) ?
processes[i].remaining : time_quantum;
processes[i].remaining -= execution_time;
printf("%d\tP%d\n", currentTime, processes[i].pid);
if (processes[i].remaining == 0) {
processes[i].completed = true;
completedProcesses++;
}
currentTime += execution_time;
}
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
int time_quantum;
printf("Enter the time quantum: ");
scanf("%d", &time_quantum);

preemptiveRoundRobinScheduling(processes, n, time_quantum);
return 0;
}