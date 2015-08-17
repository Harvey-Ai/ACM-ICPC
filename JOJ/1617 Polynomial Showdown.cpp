#include <iostream>
using namespace std;
int main()
{
	int coefficient[10];
	int i;
	bool flag;
	while(cin>>coefficient[0])
	{
		flag=0;
		for(i=1;i<9;i++)
			cin>>coefficient[i];
		if(coefficient[0])
		{
			if(coefficient[0]!=1&&coefficient[0]!=-1)
				cout<<coefficient[0];
			if(coefficient[0]==-1)
				cout<<"-";
			cout<<"x^8"; 
			flag=1;
		}

		for(i=1;i<7;i++)
		{
			if(coefficient[i]!=0)
			{
				if(flag)
				{
					if(coefficient[i]>0)
						cout<<" + ";
					else
					{
						cout<<" - ";
						coefficient[i]=-coefficient[i];
					}
				}
				if(coefficient[i]==-1)
					cout<<"-";
				else
				{
					if(coefficient[i]!=1)
						cout<<coefficient[i];
				}
				cout<<"x^"<<8-i;
				flag=1;
			}
		}
		if(coefficient[7])
		{
			if(flag)
			{
				if(coefficient[7]>0)
					cout<<" + ";
				else
				{
					cout<<" - ";
					coefficient[7]=-coefficient[7];
				}
			}
			if(coefficient[7]==-1)
				cout<<"-";
			else
			{
				if(coefficient[7]!=1)
					cout<<coefficient[7];
			}
			cout<<"x";
			flag=1;
		}
		if(coefficient[8])
		{
			if(flag)
			{
				if(coefficient[8]>0)
					cout<<" + ";
				else
				{
					cout<<" - ";
					coefficient[8]=-coefficient[8];
				}
			}
			cout<<coefficient[8];
		}
		else
		{
			if(flag==0)
				cout<<0;
		}
		cout<<endl;
	}
	return 0;
}

