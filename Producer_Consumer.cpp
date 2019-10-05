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
	cout<<"(1)produce\t(2)consume"<<endl;
	while(1)
	{
		cout<<"Enter your choice"<<endl;
		cin>>i;
		switch(i)
		{				
			case 1:
				if(mutex==1 && empty!=0)
				produce();
				else
				cout<<"Buffer is full"<<endl;
				break;
			case 2:
				if(mutex==1 && full!=0)
				consume();
				else
				cout<<"Buffer is empty"<<endl;
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
	cout<<"Producer produced item "<<item<<endl;
	mutex=signal(mutex);	
}
void consume()
{
	mutex=wait(mutex);
	empty=signal(empty);
	full=wait(full);
	cout<<"consumer consume item "<<item<<endl;
	item--;
	mutex=signal(mutex);	
}