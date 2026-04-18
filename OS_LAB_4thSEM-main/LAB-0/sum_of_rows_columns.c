#include <stdio.h>

int main() {
    int a[10][10], m, n;

    printf("Enter rows and columns: ");
    scanf("%d%d",&m,&n);

    printf("Enter matrix elements:\n");

    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);

    for(int i=0;i<m;i++){
        int rowsum = 0;
        for(int j=0;j<n;j++){
            rowsum += a[i][j];
        }
        printf("Sum of row %d = %d\n", i+1, rowsum);
    }

    for(int j=0;j<n;j++){
        int colsum = 0;
        for(int i=0;i<m;i++){
            colsum += a[i][j];
        }
        printf("Sum of column %d = %d\n", j+1, colsum);
    }

    return 0;
}
