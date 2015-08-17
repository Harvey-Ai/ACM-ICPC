#include <iostream>
using namespace std;
int main()
{
	int i,j,n;
	long long divide[32];
	divide[2]=0;divide[3]=1;
	for(i=4;i<32;i++)
	{
		divide[i]=divide[i-1]*2;
		for(j=2;j<i-2;j++)
			divide[i]+=divide[j+1]*divide[i-j];
	}
	while(cin>>n)
		cout<<divide[n]<<endl;
	return 0;
}