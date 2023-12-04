#include <stdio.h>
// Structure to represent a process
struct Process {
int pid; // Process ID
int arrival; // Arrival time
int burst; // Burst time
};
// Function to perform FCFS scheduling
void fcfsScheduling(struct Process processes[], int n) {
int currentTime = 0;
printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
for (int i = 0; i < n; i++) {
if (processes[i].arrival > currentTime) {
currentTime = processes[i].arrival;
}
// Calculate waiting time
int waitingTime = currentTime - processes[i].arrival;
// Calculate turnaround time
int turnaroundTime = waitingTime + processes[i].burst;
printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival,
processes[i].burst, waitingTime, turnaroundTime);
currentTime += processes[i].burst;
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
}
// Perform FCFS scheduling
fcfsScheduling(processes, n);
return 0;
}