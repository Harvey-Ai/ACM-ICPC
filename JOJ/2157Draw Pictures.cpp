#include <iostream>
using namespace std;
int main()
{
	int i,j,k,n,row;
	while(cin>>n,n)
	{
		row=3*n+n-1;
		for(i=1;i<=n;i++)
		{
			if(i!=1)
				cout<<" ";
			for(j=1;j<4;j++)
				cout<<"X";
		}
		cout<<endl;
		cout<<"X";
		for(i=2;i<row-1;i+=2)
			cout<<" "<<"X";
		cout<<endl;
		for(i=3;i<row+1;i+=2)
		{
			for(j=1;j<row-i;j+=2)
				cout<<"X"<<" ";
			for(j=1;j<=i;j++)
				cout<<"X";
			cout<<endl;
			if((i+1)<=row)
			{
				cout<<"X";
				for(j=2;j<row-i;j+=2)
					cout<<" "<<"X";
				if((i+1)%4==0)
				{
					k=1;
					while(k<=row-j)
					{
						cout<<" ";
						k++;
					}
					cout<<"X"<<endl;
				}
				else
					cout<<endl;
			}
		}
		cout<<endl;
	}
	return 0;
}
