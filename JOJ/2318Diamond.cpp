#include <iostream>
using namespace std;
int main()
{
	int n,i,j;
	while(cin>>n,n)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n-i;j++)
				cout<<" ";
			for(j=1;j<=2*i-1;j++)
				cout<<"*";
			cout<<endl;
		}
		for(i=1;i<=n-1;i++)
		{
			for(j=1;j<=i;j++)
				cout<<" ";
			for(j=2*n-2*i-1;j>=1;j--)
				cout<<"*";
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}

