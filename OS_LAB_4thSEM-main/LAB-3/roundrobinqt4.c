#include <stdio.h>

int main() {
    int n, i;
    int quantum = 4;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], rt[n], wt[n], tat[n];

    // Input burst times
    for(i = 0; i < n; i++) {
        printf("Enter burst time for P%d: ", i+1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    int time = 0, remain = n;

    // For Gantt chart storage
    int gantt_p[100], gantt_t[100];
    int k = 0;

    printf("\nGantt Chart:\n|");

    while(remain > 0) {
        for(i = 0; i < n; i++) {
            if(rt[i] > 0) {
                gantt_p[k] = i;  // store process index

                if(rt[i] <= quantum) {
                    time += rt[i];
                    gantt_t[k] = time;
                    rt[i] = 0;

                    tat[i] = time;
                    wt[i] = tat[i] - bt[i];

                    remain--;
                } else {
                    time += quantum;
                    rt[i] -= quantum;
                    gantt_t[k] = time;
                }

                printf(" P%d |", i+1);
                k++;
            }
        }
    }

    // Print timeline
    printf("\n0");
    for(i = 0; i < k; i++) {
        printf("   %d", gantt_t[i]);
    }

    // Print results
    float total_wt = 0, total_tat = 0;

    printf("\n\nProcess\tBT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], tat[i], wt[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}
