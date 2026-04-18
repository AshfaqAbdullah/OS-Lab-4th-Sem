#include <stdio.h>

struct fcfs {
    int p[20];
    int at[20], bt[20];
    int ft[20], ct[20];
    int tat[20], wt[20], rt[20];
};

int main() {

    struct fcfs x;
    int n, i, j;

    float avg_tat = 0, avg_wt = 0, avg_rt = 0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    // INPUT
    for(i=0;i<n;i++)
    {
        x.p[i]=i+1;
        printf("Enter AT and BT for P%d: ",i+1);
        scanf("%d %d",&x.at[i],&x.bt[i]);
    }

    // TEMP ARRAYS FOR SORTING
    int pat[20], pbt[20], pid[20];

    for(i=0;i<n;i++)
    {
        pat[i]=x.at[i];
        pbt[i]=x.bt[i];
        pid[i]=i;
    }

    // SORT BY ARRIVAL TIME
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(pat[i]>pat[j])
            {
                int temp;

                temp=pat[i];
                pat[i]=pat[j];
                pat[j]=temp;

                temp=pbt[i];
                pbt[i]=pbt[j];
                pbt[j]=temp;

                temp=pid[i];
                pid[i]=pid[j];
                pid[j]=temp;
            }
        }
    }

    int ft[20], ct[20];

    // FCFS CALCULATION
    for(i=0;i<n;i++)
    {
        if(i==0)
            ft[i]=pat[i];
        else if(ct[i-1] < pat[i])
            ft[i]=pat[i];
        else
            ft[i]=ct[i-1];

        ct[i]=ft[i]+pbt[i];
    }

    // STORE BACK IN ORIGINAL ORDER
    for(i=0;i<n;i++)
    {
        int k = pid[i];

        x.ft[k] = ft[i];
        x.ct[k] = ct[i];

        x.tat[k] = x.ct[k] - x.at[k];
        x.wt[k]  = x.tat[k] - x.bt[k];
        x.rt[k]  = x.ft[k] - x.at[k];

        avg_tat += x.tat[k];
        avg_wt  += x.wt[k];
        avg_rt  += x.rt[k];
    }

    printf("\nP\tAT\tBT\tFT\tCT\tTAT\tWT\tRT\n");

    // PRINT IN ORIGINAL ORDER
    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,x.at[i],x.bt[i],x.ft[i],x.ct[i],
        x.tat[i],x.wt[i],x.rt[i]);
    }

    printf("\nAverage TAT = %.2f",avg_tat/n);
    printf("\nAverage WT = %.2f",avg_wt/n);
    printf("\nAverage RT = %.2f",avg_rt/n);

    return 0;
}
