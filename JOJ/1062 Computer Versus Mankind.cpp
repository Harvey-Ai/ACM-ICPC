#include <iostream>
using namespace std;
int main()
{
	int n1,n2,lcm,gcd,temp;
	while((cin>>n1>>n2,n1||n2))
	{
		lcm=n1*n2;
		while(n2)
		{
			temp=n2;
			n2=n1%n2;
			n1=temp;
		}
		gcd=n1;
		lcm/=gcd;
		cout<<gcd<<" "<<lcm<<endl;
	}
	return 0;
}