#include<stdio.h>
#include<stdlib.h>
int mutex=1;
int full=0;
int empty=10,x=0;
void producer()
{
	--mutex;
	++full;
	--empty;
	x++;
	printf("\nproducer produces""item %d",x);
	++mutex;
}
void consumer()
{
	--mutex;
	--full;
	++empty;
	printf("\nconsumer consumes""item %d",x);
	x--;
	++mutex;
}
int main()
{
	int n,i;
	printf("\n1.press 1 for producer""\n2.press 2 for consumer""\n3.press 3 for exist");
	#pragma omp critical
	for(i=1;i>0;++i)
	{
		printf("\nenter your choice:");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
			if((mutex==1)
			&&(empty!=0))
			{
				producer();
			}
			else{
			
			printf("buffer is full!");
			}
			break;
			case 2:
				if((mutex==1)&&(full!=0))
				{
					consumer();
				}
				else
				{
					printf("buffer is empty!");
				}
				break;
				case 3:
					exit(0);
					break;
		}
	}
}

OUTPUT:
1.press 1 for producer
2.press 2 for consumer
3.press 3 for exist
enter your choice:1

producer producesitem 1
enter your choice:2

consumer consumesitem 1
enter your choice:2
buffer is empty!
enter your choice:3

--------------------------------
Process exited after 314.4 seconds with return value 0
Press any key to continue . . .
