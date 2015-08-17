#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	long long i,n,m;
	while(cin>>n)
	{
		m=sqrt(n);
		for(i=m;i>=1;i--)
			if(n%(i*i)==0)
				break;
		cout<<(i+1)*(i+1)*(n/(i*i))<<endl;
	}
	return 0;
}