#include <iostream>
using namespace std;
int main()
{
	long i,a,b,n;
	bool flag;
	while(cin>>n,n)
	{
		flag=0;
		if(n<0)
			n=-n;
		for(i=1;i*i<n;i++)
			if(n%i==0)
			{
				a=n/i;
				b=i;
				if((a-b)%2==0)
				{
					flag=1;
					break;
				}
			}

		if(flag)
			cout<<(a-b)/2<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}