#include <stdio.h>

struct proc { int at, bt, ct, tat, wt, rt; } p[20];

int main() {
    int n, i, j, cur = 0, idx[20], t;
    float s_tat = 0, s_wt = 0, s_rt = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        idx[i] = i;
        printf("P%d AT & BT: ", i + 1);
        scanf("%d %d", &p[i].at, &p[i].bt);
    }

    // Sort index array by Arrival Time
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (p[idx[j]].at > p[idx[j+1]].at) {
                t = idx[j]; idx[j] = idx[j+1]; idx[j+1] = t;
            }

    // Logic: Calculate based on Arrival Time order (idx)
    for (i = 0; i < n; i++) {
        int k = idx[i];
        if (cur < p[k].at) cur = p[k].at; // Handle CPU idle time

        p[k].rt = cur - p[k].at;          // RT = Start Time - AT
        p[k].ct = cur + p[k].bt;
        p[k].tat = p[k].ct - p[k].at;
        p[k].wt = p[k].tat - p[k].bt;

        cur = p[k].ct;
        s_tat += p[k].tat; s_wt += p[k].wt; s_rt += p[k].rt;
    }

    // Print in original P1, P2... order
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i+1, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt, p[i].rt);

    printf("\nAvg TAT: %.2f\nAvg WT: %.2f\nAvg RT: %.2f", s_tat/n, s_wt/n, s_rt/n);
    return 0;
}
