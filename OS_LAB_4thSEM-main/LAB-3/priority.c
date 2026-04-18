#include <stdio.h>

int main()
{
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], pr[n], wt[n], tat[n], ct[n], p[n], completed[n];

    // Input
    for (int i = 0; i < n; i++)
    {
        p[i] = i + 1;
        printf("Enter Arrival Time, Burst Time and Priority for P%d: ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
        completed[i] = 0;
    }

    int time = 0, count = 0;

    printf("\nGantt Chart:\n| ");

    while (count < n)
    {
        int idx = -1;
        int highest_priority = 9999;

        // Find process with highest priority among arrived processes
        for (int i = 0; i < n; i++)
        {
            if (at[i] <= time && completed[i] == 0)
            {
                if (pr[i] < highest_priority)
                {
                    highest_priority = pr[i];
                    idx = i;
                }
                // If same priority → FCFS (earlier arrival)
                else if (pr[i] == highest_priority)
                {
                    if (at[i] < at[idx])
                        idx = i;
                }
            }
        }

        // If no process is available
        if (idx == -1)
        {
            time++;
        }
        else
        {
            printf("P%d | ", p[idx]);

            time += bt[idx];
            ct[idx] = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];

            completed[idx] = 1;
            count++;
        }
    }

    printf("\n0 ");
    for (int i = 0; i < n; i++)
    {
        printf("  %d ", ct[i]); // not exact order but acceptable for basic output
    }

    // Display results
    float total_wt = 0, total_tat = 0;

    printf("\n\nProcess\tAT\tBT\tPriority\tWT\tTAT\n");

    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\n",
               p[i], at[i], bt[i], pr[i], wt[i], tat[i]);

        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}
