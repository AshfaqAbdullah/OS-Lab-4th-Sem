#include <stdio.h>

int main()
{
    int n,i,j,choice;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    int at[n],bt[n],ct[n],tat[n],wt[n],rt[n],rt_bt[n];

    for(i=0;i<n;i++)
    {
        printf("Enter AT and BT for P%d: ",i+1);
        scanf("%d%d",&at[i],&bt[i]);
        rt_bt[i]=bt[i];
    }

    printf("\n1. SJF Non-Preemptive");
    printf("\n2. SRTF Preemptive");
    printf("\nEnter choice: ");
    scanf("%d",&choice);

    float avg_ct=0,avg_tat=0,avg_wt=0,avg_rt=0;

    switch(choice)
    {

    // -------- SJF NON PREEMPTIVE --------
    case 1:
    {
        int completed=0,time=0,smallest;
        int visited[n];

        for(i=0;i<n;i++)
            visited[i]=0;

        while(completed<n)
        {
            smallest=-1;

            for(i=0;i<n;i++)
            {
                if(at[i]<=time && visited[i]==0)
                {
                    if(smallest==-1 || bt[i]<bt[smallest])
                        smallest=i;
                }
            }

            if(smallest==-1)
            {
                time++;
                continue;
            }

            time+=bt[smallest];
            ct[smallest]=time;
            tat[smallest]=ct[smallest]-at[smallest];
            wt[smallest]=tat[smallest]-bt[smallest];
            rt[smallest]=wt[smallest];

            visited[smallest]=1;
            completed++;
        }

        printf("\nSJF Non Preemptive\n");
        break;
    }

    // -------- SRTF PREEMPTIVE --------
    case 2:
    {
        int completed=0,time=0,smallest;

        for(i=0;i<n;i++)
            rt[i]=-1;

        while(completed<n)
        {
            smallest=-1;

            for(i=0;i<n;i++)
            {
                if(at[i]<=time && rt_bt[i]>0)
                {
                    if(smallest==-1 || rt_bt[i]<rt_bt[smallest])
                        smallest=i;
                }
            }

            if(smallest==-1)
            {
                time++;
                continue;
            }

            if(rt[smallest]==-1)
                rt[smallest]=time-at[smallest];

            rt_bt[smallest]--;
            time++;

            if(rt_bt[smallest]==0)
            {
                completed++;
                ct[smallest]=time;
                tat[smallest]=ct[smallest]-at[smallest];
                wt[smallest]=tat[smallest]-bt[smallest];
            }
        }

        printf("\nSRTF Preemptive\n");
        break;
    }

    default:
        printf("Invalid choice");
        return 0;
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    for(i=0;i<n;i++)
    {
        avg_ct+=ct[i];
        avg_tat+=tat[i];
        avg_wt+=wt[i];
        avg_rt+=rt[i];

        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,at[i],bt[i],ct[i],tat[i],wt[i],rt[i]);
    }

    printf("\nAverage CT = %.2f",avg_ct/n);
    printf("\nAverage TAT = %.2f",avg_tat/n);
    printf("\nAverage WT = %.2f",avg_wt/n);
    printf("\nAverage RT = %.2f\n",avg_rt/n);

    return 0;
}
