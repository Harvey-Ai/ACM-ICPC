#include <iostream>
using namespace std;
int main()
{
	long long i,n,dig,temp,m;
	while(cin>>n)
	{
		cout.width(5);
		cout<<n<<" -> ";
		dig=n%10;i=3;temp=1;
		m=n;
		while(dig==0)
		{
			m/=10;
			dig=m%10;
		}
		while(i--)
		{
			temp*=10;
			m/=10;
			dig+=(m%10)*temp;
		}
		while(--n)
		{
			m=n*dig;
			dig=m%10;i=3;temp=1;
			while(dig==0)
			{
				m/=10;
				dig=m%10;
			}
			while(i--)
			{
				temp*=10;
				m/=10;
				dig+=(m%10)*temp;
			}
		}
		cout<<dig%10<<endl;
	}
	return 0;
}