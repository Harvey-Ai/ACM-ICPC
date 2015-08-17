#include <stdio.h>
int main()
{
	int i,k,n,sum,temp,rel;
	bool flag;
	while(scanf("%d",&n),n>0)
	{
		rel=0;k=2;
		for(sum=2;k<=n;sum++,k*=2)
		{
			temp=n;flag=1;
			for(i=0;i<sum;i++)
			{
				if((temp-1)%sum)
				{
					flag=0;
					break;
				}
				temp=((temp-1)/sum)*(sum-1);
			}
			if(temp%sum)
				flag=0;
			if(flag)
				if(sum>rel)
					rel=sum;
		}
		if(rel)
			printf("%d coconuts, %d people and 1 monkey\n",n,rel);
		else
			printf("%d coconuts, no solution\n",n);

	}
	return 0;
}

	


