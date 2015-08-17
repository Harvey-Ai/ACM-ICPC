#include <stdio.h>
int main()
{
	int i;
	double n;
	long double rel;
	while(scanf("%lf",&n),n)
	{
		if(n<5)
		{
			printf("0\n");
			continue;
		}
		rel=1;
		for(i=1;i<=3;i++)
		{
			rel*=(n+i-3);
			rel/=i;
		}
		rel-=((n-3)*(n-4)+2*(n-3)+(n-2));
		printf("%.0Lf\n",rel);
	}
	return 0;
}
			
