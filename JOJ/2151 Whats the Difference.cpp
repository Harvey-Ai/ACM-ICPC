#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	string name1,name2;
	int i,j,n1,n2;
	int pid1[10000],pid2[10000];
	bool flag;
	while(cin>>name1)
	{
		cin>>n1;
		for(i=0;i<n1;i++)
			cin>>pid1[i];
		cin>>name2;
		cin>>n2;
		for(i=0;i<n2;i++)
			cin>>pid2[i];
		for(i=0;i<n1;i++)
			for(j=0;j<n2;j++)
				if(pid1[i]==pid2[j])
				{
					pid1[i]=pid2[j]=0;
					break;
				}
		sort(&pid1[0],&pid1[n1]);
		sort(&pid1[0],&pid1[n2]);
		cout<<name1<<" has done but "<<name2<<" hasn't done:"<<endl;
		flag=0;
		for(i=0;i<n1;i++)
		{
			if(pid1[i])
			{
				if(flag)
					cout<<" ";
				cout<<pid1[i];
				flag=1;
			}
		}
		if(flag==0)
			cout<<"none";
		cout<<endl;
		cout<<name2<<" has done but "<<name1<<" hasn't done:"<<endl;
		flag=0;
		for(i=0;i<n2;i++)
		{
			if(pid2[i])
			{
				if(flag)
					cout<<" ";
				cout<<pid2[i];
				flag=1;
			}
		}
		if(flag==0)
			cout<<"none";
		cout<<endl;
		cout<<endl;
	}
	return 0;
}


