#include <stdio.h>

#define MAX_PROCESSES 30

int main() {
    int i, np, qt;
    int bt[MAX_PROCESSES], at[MAX_PROCESSES];
    int rem_bt[MAX_PROCESSES], wt[MAX_PROCESSES], tat[MAX_PROCESSES];
    float awt = 0, atat = 0;
    int sq = 0; // Simulation time

    printf("Enter number of processes: ");
    scanf("%d", &np);

    printf("Enter time quantum: ");
    scanf("%d", &qt);

    printf("Enter burst time and arrival time for each process:\n");
    for (i = 0; i < np; i++) {
        printf("Process %d - Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
        printf("Process %d - Arrival Time: ", i + 1);
        scanf("%d", &at[i]);
        rem_bt[i] = bt[i]; // Initialize remaining burst time
    }

    // Process each process using Round Robin scheduling
    while (1) {
        int completed = 1; // Flag to check if all processes are completed
        for (i = 0; i < np; i++) {
            if (rem_bt[i] > 0 && at[i] <= sq) {
                completed = 0; // At least one process is not completed
                if (rem_bt[i] > qt) {
                    // Process executes for time quantum (qt)
                    sq += qt;
                    rem_bt[i] -= qt;
                } else {
                    // Process finishes execution
                    sq += rem_bt[i];
                    rem_bt[i] = 0;
                    tat[i] = sq - at[i]; // Turnaround time = Completion time - Arrival time
                }
            }
        }
        if (completed) // If all processes are completed
            break;
    }

    // Calculate waiting time for each process
    for (i = 0; i < np; i++) {
        wt[i] = tat[i] - bt[i]; // Waiting time = Turnaround time - Burst time
        awt += wt[i];
        atat += tat[i];
    }

    // Calculate average waiting time and average turnaround time
    awt /= np;
    atat /= np;

    // Display process details and averages
    printf("\nProcess\tArrival Time\tBurst Time\tTurnaround Time\tWaiting Time\n");
    for (i = 0; i < np; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, at[i], bt[i], tat[i], wt[i]);
    }
    printf("\nAvg Waiting Time: %.2f\n", awt);
    printf("Avg Turnaround Time: %.2f\n", atat);

    return 0;
}

