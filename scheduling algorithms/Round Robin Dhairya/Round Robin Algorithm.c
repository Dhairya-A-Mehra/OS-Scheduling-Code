#include <stdio.h>
#include <limits.h>

struct Process {
    int AT, BT, ST[20], WT, FT, TAT, pos;
};

int quant;

int main() {
    int n, i, j;
    printf("Enter the no. of processes: ");
    scanf("%d", &n);
    struct Process p[n];
    printf("Enter the quantum: \n");
    scanf("%d", &quant);
    printf("Enter the process numbers: \n");
    for (i = 0; i < n; i++)
        scanf("%d", &p[i].pos);
    printf("Enter the Arrival time of processes: \n");
    for (i = 0; i < n; i++)
        scanf("%d", &p[i].AT);
    printf("Enter the Burst time of processes: \n");
    for (i = 0; i < n; i++)
        scanf("%d", &p[i].BT);

    int c = n, s[n][20];
    float time = 0, mini = INT_MAX, b[n], a[n];

    int index = -1;
    for (i = 0; i < n; i++) {
        b[i] = p[i].BT;
        a[i] = p[i].AT;
        for (j = 0; j < 20; j++) {
            s[i][j] = -1;
        }
    }

    int tot_wt = 0, tot_tat = 0;
    int flag = 0;

    while (c != 0) {
        mini = INT_MAX;
        flag = 0;

        for (i = 0; i < n; i++) {
            float p = time + 0.1;
            if (a[i] <= p && mini > a[i] && b[i] > 0) {
                index = i;
                mini = a[i];
                flag = 1;
            }
        }

        if (!flag) {
            time++;
            continue;
        }

        j = 0;
        while (s[index][j] != -1) {
            j++;
        }

        if (s[index][j] == -1) {
            s[index][j] = time;
            p[index].ST[j] = time;
        }

        if (b[index] <= quant) {
            time += b[index];
            b[index] = 0;
        } else {
            time += quant;
            b[index] -= quant;
        }

        if (b[index] > 0) {
            a[index] = time + 0.1;
        }

        if (b[index] == 0) {
            c--;
            p[index].FT = time;
            p[index].WT = p[index].FT - p[index].AT - p[index].BT;
            tot_wt += p[index].WT;
            p[index].TAT = p[index].BT + p[index].WT;
            tot_tat += p[index].TAT;
        }
    }

    double avg_wt = tot_wt / (double)n;
    double avg_tat = tot_tat / (double)n;

    printf("The average wait time is: %.2f\n", avg_wt);
    printf("The average TurnAround time is: %.2f\n", avg_tat);

    return 0;
}