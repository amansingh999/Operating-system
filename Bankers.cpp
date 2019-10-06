#include<iostream>
using namespace std;
int main()
{
	int n,m,i,j,l,k;
	cout<<"Enter number of process and resources\n";
	cin>>n>>m;
	int alloc[n][m],max[n][m],need[n][m],avail[m];

	cout<<"Enter allocated resources for P1 to P"<<n;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			cin>>alloc[i][j];

	cout<<"Enter the max need of resources\n";
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			cin>>max[i][j];
	
	cout<<"Enter available resources\n";
	for(i=0;i<m;i++)
		cin>>avail[i];
	
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			need[i][j]=max[i][j]-alloc[i][j];
	
	int ans[n],visit[n],ind=0;
	for(i=0;i<n;i++)
		visit[i]=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(visit[j]==0)
			{
				int flag=0;
				for(k=0;k<m;k++)
				{
					if(need[j][k]>avail[k])
					{
						flag=1;
						break;
					}
				}
				if(flag==0)
				{
					ans[ind++]=j;
					visit[j]=1;
					for(l=0;l<m;l++)
						avail[l] +=alloc[j][l];
				}
			}
		}
	}
	
	cout<<"Safe sequence\n";
	for(i=0;i<n;i++)
		cout<<ans[i]<<" ";
	return 0;			
		
}
