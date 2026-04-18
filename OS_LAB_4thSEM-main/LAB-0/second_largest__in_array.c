#include <stdio.h>

int main() {
    int arr[100], n;
    int largest, second_largest;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    largest = second_largest = -9999;

    for(int i=0;i<n;i++){
        if(arr[i] > largest){
            second_largest = largest;
            largest = arr[i];
        }
        else if(arr[i] > second_largest && arr[i] != largest){
            second_largest = arr[i];
        }
    }

    printf("Second largest element = %d",second_largest);

    return 0;
}
