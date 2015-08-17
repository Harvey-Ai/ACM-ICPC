#include <iostream>
#include<string.h>
using namespace std;
int main()
{
	bool flag1,flag,flag2;
	int n1,n2;
	int set1[1000],set2[1000];
	char c;
	while((c=cin.peek())!=EOF)
	{
		flag2=1;
		flag1=1;
		flag=1;
		n1=0;
		n2=0;
		if(c=='\n')
		{
			cin.get();
			c=cin.peek();
			if(c=='\n')
			{
				cout<<"A equals B"<<endl;
				cin.get();
			}
			else
			{
				while((c=cin.get(),c!='\n'));
				cout<<"A is a proper subset of B"<<endl;
			}
			continue;
		}
		else
		{
			while((cin>>set1[n1++],c=cin.get(),c!='\n'));
			c=cin.peek();
			if(c=='\n')
			{
				cout<<"B is a proper subset of A"<<endl;
				cin.get();
				continue;
			}
			else
				while((cin>>set2[n2++],c=cin.get(),c!='\n'));
		}
		n1--;n2--;

		if(n1>n2)
		{
			for(int i=0;i<=n2;i++)
			{
				if(flag==0&&flag1==0)
					break;
				for(int j=0;j<=n1;j++)
				{
					if(set2[i]==set1[j])
					{
						flag1=0;
						flag=1;
						break;
					}
					else
						flag=0;
				}
				if(flag==0)
					flag2=0;
			}
			if(flag2)
				cout<<"B is a proper subset of A"<<endl;
			else
				if(flag1)
					cout<<"A and B are disjoint"<<endl;
				else
					cout<<"I'm confused!"<<endl;
		}
		else
		{
			for(int i=0;i<=n1;i++)
			{
				if(flag==0&&flag1==0)
					break;
				for(int j=0;j<=n2;j++)
				{
					if(set1[i]==set2[j])
					{
						flag1=0;
						flag=1;
						break;
					}
					else
						flag=0;
				}
				if(flag==0)
					flag2=0;
			}
			if(flag2)
			{
				if(n1<n2)
					cout<<"A is a proper subset of B"<<endl;
				else
					cout<<"A equals B"<<endl;
			}
			else
			{
				if(flag1)
					cout<<"A and B are disjoint"<<endl;
				else
					cout<<"I'm confused!"<<endl;
			}
		}
	}
	cout<<endl;
	return 0;
}