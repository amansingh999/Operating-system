#include<bits/stdc++.h>
using namespace std;
int mutex=1,full=0,empty=3,item=0;
void produce();
void consume();
int wait(int);
int signal(int);
int main()
{
	int i;
	printf("(1)produce\t(2)consume\n");
	while(1)
	{
		printf("Enter your choice\n");
		scanf("%d",&i);
		switch(i)
		{				
			case 1:
				if(mutex==1 && empty!=0)
				produce();
				else
				printf("Buffer is full\n");
				break;
			case 2:
				if(mutex==1 && full!=0)
				consume();
				else
				printf("Buffer is empty\n");
				break;
		}
	}
	return 0;	
}
int wait(int s)
{
	return(--s);
}
int signal(int s)
{
	return(++s);
}
void produce()
{
	mutex=wait(mutex);
	empty=wait(empty);
	full=signal(full);
	item++;
	printf("Producer produced item %d\n",item);
	mutex=signal(mutex);	
}
void consume()
{
	mutex=wait(mutex);
	empty=signal(empty);
	full=wait(full);
	printf("consumer consume item %d\n",item);
	item--;
	mutex=signal(mutex);	
}