#include<iostream>
using namespace std;
int phil[5]={0},i;
int choice()
{
	int n;
	cout<<"Enter choice"<<endl;
	cin>>n;
	switch(n)
	{
		case 0:
			cout<<"Enter the number of philospher who wants to eat"<<endl;
			cin>>i;
			if(phil[i]==1 || phil[(i+1)%5]==1)
			cout<<"Philospher cannot eat at this time"<<endl;
			else
			{
			phil[i]=phil[(i+1)%5]=1;
			cout<<"philospher "<<i<<" now start eating"<<endl;
			}
			choice();
		case 1:
			cout<<"Enter the number of philospher who wants to stop eating and start thinking"<<endl;
			cin>>i;
			if(phil[i]==0 || phil[(i+1)%5]==0)
			cout<<"philospher is already thinking"<<endl;
			else
			{
			phil[i]=phil[(i+1)%5]=0;
			cout<<"philospher "<<i<<" now start thinking"<<endl;
			}
			choice();
	}
	return 0;
}
int main()
{
	cout<<"Enter 0 for eating\nEnter 1 for thinking"<<endl;
	choice();
	return 0;
}
