#include <iostream>
using namespace std;
int main()
{
	int N,n,sum;
	cin>>N;
	while(N--)
	{
		sum=0;
		cin>>n;
		n/=5;
		while(n)
		{
			sum+=n;
			n/=5;
		}
		cout<<sum<<endl;
	}
	return 0;
}

