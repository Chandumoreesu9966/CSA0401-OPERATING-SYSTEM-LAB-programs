#include <stdio.h>
int main()
{
    int n = 3, burstTime[3] = {2, 4, 8};
    int waitingTime[3], turnaroundTime[3],i;
    int totalWaitingTime = 0, totalTurnaroundTime = 0;
    waitingTime[0] = 0;
    for (i = 1; i < n; i++)
        waitingTime[i] = burstTime[i-1] + waitingTime[i-1];
    for (i = 0; i < n; i++)
        turnaroundTime[i] = burstTime[i] + waitingTime[i];
    for (i = 0; i < n; i++) 
	{
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
    }
	printf("Average Waiting Time: %.2f\n", (float)totalWaitingTime / n);
    printf("Average Turnaround Time: %.2f\n", (float)totalTurnaroundTime / n);
    return 0;
}

OUTPUT:
Average Waiting Time: 2.67
Average Turnaround Time: 7.33

--------------------------------
Process exited after 0.1597 seconds with return value 0
Press any key to continue . . .
