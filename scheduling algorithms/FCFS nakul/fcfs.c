#include <stdio.h>

#define max 30

int main()
{
    int i, n, bt[max], wt[max], tat[max];
    float awt = 0, atat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst time of the processes: ");
    for (i = 0; i < n; i++)
        scanf("%d", &bt[i]);

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
    {
        wt[i] = 0;
        tat[i] = 0;

        for (int j = 0; j < i; j++)
            wt[i] += bt[j];

        tat[i] = wt[i] + bt[i];
        awt += wt[i];
        atat += tat[i];

        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    awt /= n;
    atat /= n;

    printf("\nAverage Waiting Time: %.2f", awt);
    printf("\nAverage Turnaround Time: %.2f", atat);

    return 0;
}
