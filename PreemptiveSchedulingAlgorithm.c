/*
Implementing a preemptive scheduling algorithm requires tracking the state of
processes and making decisions to switch between processes based on their priority or
remaining execution time. Here's a C program that implements the preemptive SJF
scheduling algorithm:
*/
#include <stdio.h>
#include <stdbool.h>
// Structure to represent a process
struct Process {
int pid; // Process ID
int arrival; // Arrival time
int burst; // Burst time
int remaining; // Remaining burst time
bool completed; // Flag to track if the process has completed
};
// Function to perform preemptive SJF scheduling
void preemptiveSJFScheduling(struct Process processes[], int n) {
int currentTime = 0;
int completedProcesses = 0;
printf("Time\tProcess\n");
while (completedProcesses < n) {
int shortestRemainingTime = -1;
int shortestProcessIndex = -1;
// Find the process with the shortest remaining burst time
for (int i = 0; i < n; i++) {
if (!processes[i].completed && processes[i].arrival <= currentTime) {
if (shortestRemainingTime == -1 || processes[i].remaining < shortestRemainingTime) {
shortestRemainingTime = processes[i].remaining;
shortestProcessIndex = i;
}
}
}
if (shortestProcessIndex == -1) {
// No eligible process is available; increment time
currentTime++;
} else {
// Execute the selected process for one time unit
processes[shortestProcessIndex].remaining--;
printf("%d\tP%d\n", currentTime, processes[shortestProcessIndex].pid);
if (processes[shortestProcessIndex].remaining == 0) {
// Process has completed
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
// Perform preemptive SJF scheduling
preemptiveSJFScheduling(processes, n);
return 0;
}
