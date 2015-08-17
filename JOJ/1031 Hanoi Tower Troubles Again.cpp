#include <iostream>
using namespace std;
int main()
{
	int N,n;
	cin>>N;
	while(N--)
	{
		cin>>n;
		if(n==1)
			cout<<1<<endl;
		else
			cout<<(n*n)/2+n-(n+1)%2<<endl;
	}
	return 0;
}