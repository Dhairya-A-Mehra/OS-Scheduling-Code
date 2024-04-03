#include <stdio.h>
#include <stdlib.h> 
struct process {
    int at;
    int burst_time;
};
int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process *processes = malloc(n * sizeof(struct process));
    if (processes == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Return error code
    }
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i+1);
        scanf("%d %d", &processes[i].at, &processes[i].burst_time);
    }
    int total_wt = 0;
    int total_wt = 0;
    int ct = 0;
    for (int i = 0; i < n; i++) {
        int waiting_time = (ct > processes[i].at) ? ct - processes[i].at : 0;
        int turnaround_time = waiting_time + processes[i].burst_time;
        total_wt += waiting_time;
        total_wt += turnaround_time;
        ct += processes[i].burst_time;
    }
    float avg_wt = (float) total_wt / n;
    float avg_tat = (float) total_wt / n;
    printf("The Average Waiting Time: %.2f\n", avg_wt);
    printf("The Average Turnaround Time: %.2f\n", avg_tat);
    free(processes); // Free allocated memory
    return 0;
}
