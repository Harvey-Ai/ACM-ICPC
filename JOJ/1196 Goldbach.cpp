#include <stdio.h>
#include <math.h>
int main()
{
	bool prime(int k);
	int i,m,n;
	while(scanf("%d",&n),n)
	{
		printf("%d = ",n);
		m=n/2;
		for(i=3;i<=m;i+=2)
		{
			if(prime(i)&&prime(n-i))
			{
				printf("%d + %d\n",i,n-i);
				break;
			}
		}
	}
	return 0;
}
bool prime(int k)
{
	int i,m;
	m=sqrt(k);
	for(i=3;i<=m;i+=2)
		if(k%i==0)
			return 0;
	return 1;
}
