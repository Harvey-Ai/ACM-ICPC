#include <iostream>
using namespace std;
int main()
{
	long long i,j,n,k,rel;
	rel=1;
	while(cin>>n>>k,n||k)
	{
		if(k==0||k==n)
		{
			cout<<"1"<<endl;
			continue;
		}
		if((n-k)<k)
			k=n-k;
		i=1;rel=1;j=n-k+1;
		while(i<=k)
		{
			rel*=j;
			rel/=i;
			i++;j++;
		}
		cout<<rel<<endl;
	}
	return 0;
}


