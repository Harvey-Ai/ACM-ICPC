#include <cstdio>
int main()
{
	int i,m,n,rel;
	while(scanf("%d",&n),n)
	{
		m=1;i=0;
		while(m-1<=n)
		{
			i++;
			m*=2;
		}
		m/=2;
		i--;
		if(n-2*m+2)
		{
			rel=i;
			n-=(m-1);
		}
		else
		{
			rel=2*i;
			n-=2*(m-1);
		}
		while(n)
		{
			while(m>n)
				m/=2;
			n-=m;
			rel++;
		}
		printf("%d\n",rel);
	}
	return 0;
}
