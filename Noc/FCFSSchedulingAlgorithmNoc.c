#include <stdio.h>
struct Process {
    int pid;
    int arrival;
    int burst;
};

void fcfsScheduling(struct Process processes[], int n) {
    int currentTime = 0;
    printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        if (processes[i].arrival > currentTime) {
            currentTime = processes[i].arrival;
        }
        int waitingTime = currentTime - processes[i].arrival;
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

    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Enter arrival time for process P%d: ", i + 1);
        scanf("%d", &processes[i].arrival);
        printf("Enter burst time for process P%d: ", i + 1);
        scanf("%d", &processes[i].burst);
    }

    fcfsScheduling(processes, n);
    return 0;
}
