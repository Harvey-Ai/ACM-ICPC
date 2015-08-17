#include <stdio.h>
int main()
{
	int a1,a2,n,temp;
	a1=3;a2=5;
	while(scanf("%d",&n),n)
	{
		if(n==2)
		{
			printf("NO\n");
			continue;
		}
		while(a2<=n)
		{
			temp=a2;
			a2=a1+a2;
			a1=temp;
		}
		if(a1!=n)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

