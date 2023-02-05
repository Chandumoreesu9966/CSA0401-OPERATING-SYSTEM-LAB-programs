#include <stdio.h>
int main()
{
   int referenceString[10], pageFaults = 0, m, n, s, pages, frames;
   printf("\nEnter the number of Pages:\t");
   scanf("%d", &pages);
   printf("\nEnter reference string values:\n");
   for( m = 0; m < pages; m++)
   {
        printf("Value No. [%d]:\t", m + 1);
        scanf("%d", &referenceString[m]);
   }
   printf("\n What are the total number of frames:\t");
   {
        scanf("%d", &frames);
   }
   int temp[frames];
   for(m = 0; m < frames; m++)
   {
        temp[m] = -1;
    }
    for(m = 0; m < pages; m++)
    {
        s = 0;
        for(n = 0; n < frames; n++)
        {
            if(referenceString[m] == temp[n])
            {
                s++;
                pageFaults--;
            }
        }     
        pageFaults++;
        if((pageFaults <= frames) && (s == 0))
        {
            temp[m] = referenceString[m];
        }   
        else if(s == 0)
        {
            temp[(pageFaults - 1) % frames] = referenceString[m];
        }
        printf("\n");
        for(n = 0; n < frames; n++)
       {     
         printf("%d\t", temp[n]);
       }
} 
printf("\nTotal Page Faults:\t%d\n", pageFaults);
return 0;
}

Output:
Enter the number of Pages:      8

Enter reference string values:
Value No. [1]:  4
Value No. [2]:  1
Value No. [3]:  2
Value No. [4]:  4
Value No. [5]:  3
Value No. [6]:  2
Value No. [7]:  1
Value No. [8]:  5

 What are the total number of frames:   3

4       -1      -1
4       1       -1
4       1       2
4       1       2
3       1       2
3       1       2
3       1       2
3       5       2
Total Page Faults:      5

--------------------------------
Process exited after 73.44 seconds with return value 0
Press any key to continue . . .
