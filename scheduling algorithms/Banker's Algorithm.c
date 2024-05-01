#include <stdio.h>

// declarations
int need[10][10], allocation[10][10], max[10][10];
int avail[10];
int np, nr;

// Function to calculate need matrix
void calculate_need() {
    int i, j;
    for (i = 0; i < np; i++) {
        for (j = 0; j < nr; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

// Function to read a matrix
void read_matrix(int matrix[10][10]) {
    int i, j;
    for (i = 0; i < np; i++) {
        printf("Enter resources for process P%d: ", i);
        for (j = 0; j < nr; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display a matrix
void display_matrix(int matrix[10][10]) {
    int i, j;
    for (i = 0; i < np; i++) {
        printf("\n P%d", i);
        for (j = 0; j < nr; j++) {
            printf(" %d", matrix[i][j]);
        }
    }
}

// Banker's Algorithm function
void banker() {
    int i, j, k = 0, flag;
    int finish[10] = {0};
    int safe_seq[10];

    // Execute all incomplete processes
    for (i = 0; i < np; i++) {
        flag = 0;
        if (finish[i] == 0) {
            for (j = 0; j < nr; j++) {
                if (need[i][j] > avail[j]) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                finish[i] = 1;    // Mark process as executed
                safe_seq[k++] = i; // Store process in safe sequence
                for (j = 0; j < nr; j++) {
                    avail[j] += allocation[i][j]; // Release allocated resources
                }
                i = -1; // Reset i to check from the beginning
            }
        }
    }

    // Check for any incomplete processes
    for (i = 0; i < np; i++) {
        if (finish[i] == 0) {
            printf("\n The system is in deadlock.");
            return; // Exit function if deadlock detected
        }
    }

    // If all processes executed successfully
    printf("\n The system is in safe state.");
    printf("\n Safe Sequence: ");
    for (i = 0; i < np; i++) {
        printf("P%d ", safe_seq[i]);
    }
    printf("\n");
}

int main() {
    int i, j;

    // Input number of processes and resource types
    printf("Enter number of processes: ");
    scanf("%d", &np);
    printf("Enter number of resource types: ");
    scanf("%d", &nr);

    // Input maximum resource matrix
    printf("Enter the maximum resource matrix:\n");
    read_matrix(max);

    // Input allocation matrix
    printf("Enter the allocation matrix:\n");
    read_matrix(allocation);

    // Input available resources
    printf("Enter the available resources:\n");
    for (j = 0; j < nr; j++) {
        scanf("%d", &avail[j]);
    }

    // Calculate need matrix
    calculate_need();

    // Execute Banker's Algorithm
    banker();

    return 0;
}
