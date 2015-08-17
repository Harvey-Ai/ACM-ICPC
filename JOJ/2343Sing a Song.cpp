#include <stdio.h>
int main()
{
	int n,m,temp;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==1)
		{
			printf("YES\n");
			continue;
		}
		
		if(m==0)
		{
			printf("NO\n");
			continue;
		}
	
		while(n%m)
		{
			temp=n;
			n=m;
			m=temp%m;
		}
		if(m==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}