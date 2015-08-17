//n^k=(n-1+1)^k,然后二项展开
#include <iostream>
using namespace std;
int main()
{
	int k,n;
	while(cin>>n>>k)
	{
		if(k%(n-1))
			cout<<"no"<<endl;
		else
			cout<<"yes"<<endl;
	}
	return 0;
}