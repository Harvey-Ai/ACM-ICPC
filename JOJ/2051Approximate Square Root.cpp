#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	float n,r;
	while(cin>>n,n)
	{
		r=sqrt(n);	
		cout.precision(0);
		if(r*r<=n&&(r+1)*(r+1)>n)
			cout<<r<<endl;
		else
			if(r*r>n)
				cout<<r-1<<endl;
			else
				cout<<r+1;
	}
	return 0;
}


