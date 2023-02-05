#include <stdio.h>
#include <stdbool.h>
#define NUM_BLOCKS 6
#define NUM_PROCESSES 5
int blockSize[NUM_BLOCKS] = {300,600,350,200,750,125};
int processSize[NUM_PROCESSES] = {115,500,358,200,375};
void bestFit(int blockSize[], int m, int processSize[], int n)
{
    int allocation[n];
    for (int i = 0; i < n; i++)
        allocation[i] = -1;
    for (int i = 0; i < n; i++)
    {
        int bestIdx = -1;
        for (int j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (bestIdx == -1)
                    bestIdx = j;
                else if (blockSize[bestIdx] > blockSize[j])
                    bestIdx = j;
            }
        }
        if (bestIdx != -1)
        {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }
    printf("Process No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}
int main()
{
    bestFit(blockSize, NUM_BLOCKS, processSize, NUM_PROCESSES);
    return 0;
}

OUTPUT:
Process No.     Process Size    Block no.
1               115             6
2               500             2
3               358             5
4               200             4
5               375             5

--------------------------------
Process exited after 0.03171 seconds with return value 0
Press any key to continue . . .
