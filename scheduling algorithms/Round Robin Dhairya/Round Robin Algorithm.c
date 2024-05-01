#include<stdio.h>

int main() {
    int i, np, qt, sq = 0;
    int bt[10], rem_bt[10], wt[10], tat[10];
    float awt = 0, atat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &np);

    printf("Enter time quantum: ");
    scanf("%d", &qt);

    printf("Enter the burst time of each process: ");
    for(i = 0; i < np; i++) {
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i]; // Initialize remaining burst time
    }

    // Process each process using Round Robin scheduling
    while(1) {
        int completed = 1; // Flag to check if all processes are completed
        for(i = 0; i < np; i++) {
            if(rem_bt[i] > 0) {
                completed = 0; // At least one process is not completed
                if(rem_bt[i] > qt) {
                    sq += qt;
                    rem_bt[i] -= qt;
                } else {
                    sq += rem_bt[i];
                    rem_bt[i] = 0;
                    tat[i] = sq; // Set turnaround time when process completes
                }
            }
        }
        if(completed) // If all processes are completed
            break;
    }

    // Calculate waiting time and turnaround time for each process
    for(i = 0; i < np; i++) {
        wt[i] = tat[i] - bt[i];
        awt += wt[i];
        atat += tat[i];
    }

    // Calculate average waiting time and average turnaround time
    awt /= np;
    atat /= np;

    // Display process details and averages
    printf("\nProcess\tBurst Time\tTurnaround Time\tWaiting Time\n");
    for(i = 0; i < np; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], tat[i], wt[i]);
    }
    printf("\nAvg Waiting Time: %.2f\n", awt);
    printf("Avg Turnaround Time: %.2f\n", atat);

    return 0;
}
