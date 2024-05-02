#include <stdio.h>
#define max 30

int main() {
    int i, j, np, t;
    int p[max], bt[max], wt[max], tat[max];
    float awt = 0, atat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &np);

    printf("Enter process numbers: ");
    for (i = 0; i < np; i++)
        scanf("%d", &p[i]);

    printf("Enter burst times: ");
    for (i = 0; i < np; i++)
        scanf("%d", &bt[i]);

    // Sorting processes based on burst time (using Bubble Sort)
    for (i = 0; i < np - 1; i++) {
        for (j = 0; j < np - 1 - i; j++) {
            if (bt[j] > bt[j + 1]) {
                // Swap burst times
                t = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = t;

                // Swap process numbers accordingly
                t = p[j];
                p[j] = p[j + 1];
                p[j + 1] = t;
            }
        }
    }

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    wt[0] = 0; // First process has zero waiting time
    for (i = 0; i < np; i++) {
        // Calculate waiting time for current process
        wt[i] = 0;
        for (j = 0; j < i; j++)
            wt[i] += bt[j];

        // Calculate turnaround time for current process
        tat[i] = wt[i] + bt[i];

        // Calculate total waiting time and total turnaround time
        awt += wt[i];
        atat += tat[i];

        // Print process details
        printf("%d\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }

    // Calculate average waiting time and average turnaround time
    awt /= np;
    atat /= np;

    printf("\nAvg waiting time: %.2f", awt);
    printf("\nAvg turnaround time: %.2f\n", atat);

    return 0;
}

