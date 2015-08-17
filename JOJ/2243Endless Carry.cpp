#include <stdio.h>
int main()
{
	int n,res;
	while(scanf("%d",&n),n)
	{
		res=n;
		while(n)
		{
			res-=n&1;
			n>>=1;
		}
		printf("%d\n",res);
	}
	return 0;
}