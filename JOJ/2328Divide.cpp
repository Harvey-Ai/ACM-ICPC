#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n,k,cnt,max;
	while(cin>>n)
	{
		if(n==1)
		{
			cout<<0<<endl;
			continue;
		}
		if(n==2)
		{
			cout<<1<<endl;
			continue;
		}
		cnt=0;max=sqrt(n);
		if(max*max==n)
		{
			cnt++;
			max=max-1;
		}
		for(k=2;k<=max;k++)
		{
			if(n%k==0)
				cnt+=2;
		}
		cout<<cnt+1<<endl;
	}
	return 0;
}

