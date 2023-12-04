/*
Implementing a preemptive scheduling algorithm requires tracking the state of
processes and making decisions to switch between processes based on their priority or
remaining execution time. Here's a C program that implements the preemptive SJF
scheduling algorithm:
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

void preemptiveSJFScheduling(struct Process processes[], int n) {
    int currentTime = 0;
    int completedProcesses = 0;
    printf("Time\tProcess\n");

    while (completedProcesses < n) {
        int shortestRemainingTime = -1;
        int shortestProcessIndex = -1;

        for (int i = 0; i < n; i++) {
            if (!processes[i].completed && processes[i].arrival <= currentTime) {
                if (shortestRemainingTime == -1 || processes[i].remaining < shortestRemainingTime) {
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

    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Enter arrival time for process P%d: ", i + 1);
        scanf("%d", &processes[i].arrival);
        printf("Enter burst time for process P%d: ", i + 1);
        scanf("%d", &processes[i].burst);
        processes[i].remaining = processes[i].burst;
        processes[i].completed = false;
    }

    preemptiveSJFScheduling(processes, n);
    return 0;
}

