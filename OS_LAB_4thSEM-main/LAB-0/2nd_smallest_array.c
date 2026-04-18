#include <stdio.h>

int main() {
    int arr[100], n;
    int smallest, second_smallest;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    smallest = second_smallest = 9999;

    for(int i=0;i<n;i++){
        if(arr[i] < smallest){
            second_smallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i] < second_smallest && arr[i] != smallest){
            second_smallest = arr[i];
        }
    }

    printf("Second smallest element = %d", second_smallest);

    return 0;
}
