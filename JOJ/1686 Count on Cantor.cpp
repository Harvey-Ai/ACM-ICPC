#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n,k,l,a,b;
	while(cin>>n)
	{
		k=int(sqrt(2*n));
		if((k*k+k)>=2*n)
			k--;
		l=n-((k+1)*k)/2;
		if(k%2)
		{	
			a=l;
			b=k-l+2;
		}
		else
		{
			a=k-l+2;
			b=l;
		}
		cout<<"TERM "<<n<<" IS "<<a<<"/"<<b<<endl;
	}
	return 0;
}


