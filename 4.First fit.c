#include<stdio.h>
void firstFit(int blockSize[], int m, int processSize[], int n)
{
    int i, j;
    int allocation[n];
    for(i = 0; i < n; i++)
    {
        allocation[i] = -1;
    }
    for (i = 0; i < n; i++)     
    {
        for (j = 0; j < m; j++)    
        {
            if (blockSize[j] >= processSize[i])
            {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;    
            }
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (i = 0; i < n; i++)
    {
        printf(" %i\t\t\t", i+1);
        printf("%i\t\t\t\t", processSize[i]);
        if (allocation[i] != -1)
            printf("%i", allocation[i] + 1);
        else
            printf("Not Allocated");
        printf("\n");
    }
}
int main()
{
    int m; 
    int n; 
    int blockSize[] = {300,600,350,200,750,125};
    int processSize[] = {115,500,358,200,375};
    m = sizeof(blockSize) / sizeof(blockSize[0]);
    n = sizeof(processSize) / sizeof(processSize[0]);
    firstFit(blockSize, m, processSize, n);
    return 0 ;
}

OUTPUT:
Process No.     Process Size    Block no.
 1                      115                             1
 2                      500                             2
 3                      358                             5
 4                      200                             3
 5                      375                             5

--------------------------------
Process exited after 0.3158 seconds with return value 0
Press any key to continue . . .
