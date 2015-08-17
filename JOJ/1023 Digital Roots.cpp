/*
#include <iostream>
using namespace std;
int main()
{
	int n;
	int f(int n);
	while((cin>>n,n))
	{
		cout<<f(n)<<endl;
		cout<<endl;
	}
	return 0;
}

int f(int n)
{
	int sum=0;
	while(n)
	{
		sum+=n%10;
		n=int(n/10);
	}
	if(sum>10)
		f(sum);
	else
		return sum;
}
*/

#include <iostream>
using namespace std;
int main()
{
	char a;
	int sum,n;
	while((cin>>a,a!='0'))
	{
		sum=a-'0';
		while((a=cin.get(),a!='\n'))
			sum+=a-'0';
		while(sum>9)
		{
			n=sum;sum=0;
			while(n)
			{
				sum+=n%10;
				n/=10;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}


