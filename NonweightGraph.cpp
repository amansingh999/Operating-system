#include<iostream>
#define MAX 20
using namespace std;
int main()
{
	int graph[MAX][MAX],i,j,value,n;
	cout<<"Enter number of nodes\n";
	cin>>n;
	cout<<"If there is link between nodes then gives 1 otherwise 0\n\n";
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			cout<<"Is link between "<<i<<" and "<<j<<" : ";
			cin>>value;
			graph[i][j]=value;
			graph[j][i]=value;	
		}
	}
	cout<<"Non weighted network graph is\n";
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cout<<graph[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}