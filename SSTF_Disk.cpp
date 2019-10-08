#include<bits/stdc++.h>
using namespace std;

int find_min(int track[],int n,int head,int visited[])
{	
	int i,min=9999,mintrack;
	for(i=0;i<n;i++)
	{
		int value=abs(track[i]-head);
		if(visited[i]==0 && value<min)
		{
			min=value;
			mintrack=i;				
		}
	}
	return mintrack;
}

void SSTF(int track[],int n,int head)
{
	int i,current,seek=0,visited[n];
	for(i=0;i<n;i++)
		visited[i]=0;
	for(i=0;i<n;i++)
	{
		int mintrack=find_min(track,n,head,visited);
		visited[mintrack]=1;
		int value=abs(track[mintrack]-head);
		seek +=value;
		head=track[mintrack];
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
	SSTF(track,n,head);
	return 0;
}
