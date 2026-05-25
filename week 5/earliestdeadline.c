#include <stdio.h>

struct Process {
    int pid;
    int burst_time;
    int deadline;
    int completed;
};

int main() {
    int n, i, time = 0, completed = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    // Input process details
    for(i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("\nEnter Burst Time for Process %d: ", i + 1);
        scanf("%d", &p[i].burst_time);

        printf("Enter Deadline for Process %d: ", i + 1);
        scanf("%d", &p[i].deadline);

        p[i].completed = 0;
    }

    printf("\nExecution Order:\n");

    while(completed < n) {
        int min_deadline = 9999;
        int index = -1;

        // Find process with earliest deadline
        for(i = 0; i < n; i++) {
            if(p[i].completed == 0 && p[i].deadline < min_deadline) {
                min_deadline = p[i].deadline;
                index = i;
            }
        }

        if(index != -1) {
            printf("Process P%d runs from %d to %d\n",
                   p[index].pid,
                   time,
                   time + p[index].burst_time);

            time += p[index].burst_time;
            p[index].completed = 1;
            completed++;
        }
    }

    printf("\nAll processes completed successfully.\n");

    return 0;
}
