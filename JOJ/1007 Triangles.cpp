#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n,k;
	while((cin>>n,n))
	{
		k=int(sqrt(n*2));
		if(k*(k+1)/2==n)
		{
			cout<<n<<" is a triangular number."<<endl;
			for(int j=1;j<=k;j++)
			{
				for(int i=1;i<=j;i++)
					cout<<"*";
				cout<<endl;
			}
		}
		else
			cout<<n<<" is not a triangular number."<<endl;
	}
	return 0;
}



