#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	long n;
	while(cin>>n)
	{
		cout.setf(ios::fixed);
		cout.precision(0);
		cout<<pow(n,n-2)<<endl;
	}
	return 0;
}
