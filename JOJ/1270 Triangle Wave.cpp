#include <iostream>
using namespace std;
int main()
{
	int height,f,l,i,j,k;
	while(cin>>height>>f)
	{
		l=0;
		for(i=1;i<=f;i++)
		{
			if(l)
				cout<<endl;
			else
				l=1;
			for(j=1;j<=height;j++)
			{
				for(k=1;k<=j;k++)
					cout<<j;
				cout<<endl;
			}
			for(j=height-1;j>0;j--)
			{
				for(k=1;k<=j;k++)
					cout<<j;
				cout<<endl;
			}
		}
	}
	return 0;
}
