#include <stdio.h>

int main() {
    int blocks[] = {100, 500, 200, 300, 600};
    int processes[] = {212, 417, 112, 426};
    int b_count = sizeof(blocks) / sizeof(blocks[0]);
    int p_count = sizeof(processes) / sizeof(processes[0]);

    printf("Process No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < p_count; i++) {
        int allocated_idx = -1;
        for (int j = 0; j < b_count; j++) {
            if (blocks[j] >= processes[i]) {
                allocated_idx = j;
                blocks[j] -= processes[i]; // Deduct allocated memory
                break;                     // Early exit makes First-fit the shortest
            }
        }
        
        printf("%d\t\t%d\t\t", i + 1, processes[i]);
        if (allocated_idx != -1)
            printf("%d\n", allocated_idx + 1);
        else
            printf("Not Allocated\n");
    }
    return 0;
}