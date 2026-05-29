#include <stdio.h>

#define MAX 20

void worstFit(int blockSize[], int blocks, int processSize[], int processes) {
    int allocation[MAX];
    
    // Initialize all allocations as -1 (unallocated)
    for (int i = 0; i < processes; i++) {
        allocation[i] = -1;
    }

    // Pick each process and find suitable blocks according to worst fit
    for (int i = 0; i < processes; i++) {
        int worstIdx = -1;
        for (int j = 0; j < blocks; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx]) {
                    worstIdx = j;
                }
            }
        }

        // If a block was found, allocate it to the process
        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i]; // Reduce available memory in that block
        }
    }

    // Display the final allocation results
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < processes; i++) {
        printf(" %d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i] + 1);
        } else {
            printf("Not Allocated\n");
        }
    }
}

int main() {
    int blockSize[MAX], processSize[MAX];
    int blocks, processes;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &blocks);
    printf("Enter the size of each block:\n");
    for (int i = 0; i < blocks; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    printf("\nEnter the number of processes: ");
    scanf("%d", &processes);
    printf("Enter the size of each process:\n");
    for (int i = 0; i < processes; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processSize[i]);
    }

    worstFit(blockSize, blocks, processSize, processes);

    return 0;
}