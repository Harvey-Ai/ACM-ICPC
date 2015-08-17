#include <iostream>
using namespace std;
int main()
{
	int i,temp;
	long long rel;
	rel=1;temp=1;
	for(i=2;i<1002;i++)
	{
		temp*=i;
		temp=temp%13;
		rel+=temp;
	}
	cout<<rel<<endl;
	return 0; 
}


