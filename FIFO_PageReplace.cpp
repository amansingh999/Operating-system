#include<bits/stdc++.h>
using namespace std;
int page_fault(int page[],int n,int f)
{
	unordered_set<int> s;
	queue<int> q;
	int pagefault=0;
	for(int i=0;i<n;i++)
	{
		if(s.size()<f)
		{
			if(s.find(page[i])==s.end())
			{
				s.insert(page[i]);  //insert into unordered set
				q.push(page[i]);
				pagefault++;
			}
		}
		else
		{
			if(s.find(page[i])==s.end())
			{
				int a=q.front();
				q.pop();
				s.erase(a);
				s.insert(page[i]);
				q.push(page[i]);
				pagefault++;
			}	
		}
	}
	return pagefault;
}

int main()
{
	int n,page[100],f;
	cout<<"Enter number of pages and frames\n";
	cin>>n>>f;
	cout<<"Enter the pages\n";
	for(int i=0;i<n;i++)
		cin>>page[i];
	int ans=page_fault(page,n,f);
	cout<<"page fault is "<<ans;
	return 0;
}
