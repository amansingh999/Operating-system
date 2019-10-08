#include<bits/stdc++.h>
using namespace std;

void FCFS(int track[],int n,int head)
{
	int i,current,seek=0;
	for(i=0;i<n;i++)
	{
		current=track[i];
		int value=abs(current-head);
		seek +=value;
		head=current;	
	}
	cout<<"Total seek time is : "<<seek;
}
int main()
{
	int track[20],n,head;
	cout<<"Enter the number of track : ";
	cin>>n;
	cout<<"Enter the track : ";
	for(int i=0;i<n;i++)
		cin>>track[i];
	cout<<"Enter the head track : ";
	cin>>head;
	FCFS(track,n,head);
	return 0;
}
