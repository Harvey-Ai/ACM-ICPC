#include <iostream>
using namespace std;
int main()
{
	int k,n;
	double sum;
	while(cin>>k)
	{
		n=0;sum=0;
		while(sum<=k)
		{
			n++;
			sum+=double(1)/n;
		}
		cout<<n<<endl;
	}
	return 0;
}
			
