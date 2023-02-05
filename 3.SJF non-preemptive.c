#include<stdio.h>
int main() 
{
  int time, burst_time[10], at[10], sum_burst_time = 0, smallest, n, i;
  int sumt = 0, sumw = 0;
  printf("enter the no of processes : ");
  scanf("%d", & n);
  for (i = 0; i < n; i++) 
  {
    printf("the arrival time for process P%d : ", i + 1);
    scanf("%d", & at[i]);
    printf("the burst time for process P%d : ", i + 1);
    scanf("%d", & burst_time[i]);
    sum_burst_time += burst_time[i];
  }
  burst_time[9] = 9999;
  for (time = 0; time < sum_burst_time;) 
  {
    smallest = 9;
    for (i = 0; i < n; i++) 
	{
      if (at[i] <= time && burst_time[i] > 0 && burst_time[i] < burst_time[smallest])
        smallest = i;
    }
    printf("P[%d]\t|\t%d\t|\t%d\n", smallest + 1, time + burst_time[smallest] - at[smallest], time - at[smallest]);
    sumt += time + burst_time[smallest] - at[smallest];
    sumw += time - at[smallest];
    time += burst_time[smallest];
    burst_time[smallest] = 0;
  }
  printf("\n\n average waiting time = %f", sumw * 1.0 / n);
  printf("\n\n average turnaround time = %f", sumt * 1.0 / n);
  return 0;
}

OUTPUT:
enter the no of processes : 4
the arrival time for process P1 : 0
the burst time for process P1 : 6
the arrival time for process P2 : 1
the burst time for process P2 : 8
the arrival time for process P3 : 2
the burst time for process P3 : 7
the arrival time for process P4 : 3
the burst time for process P4 : 7
P[1]    |       6       |       0
P[3]    |       11      |       4
P[4]    |       17      |       10
P[2]    |       27      |       19


 average waiting time = 8.250000

 average turnaround time = 15.250000
--------------------------------
Process exited after 85.15 seconds with return value 0
Press any key to continue . . .
