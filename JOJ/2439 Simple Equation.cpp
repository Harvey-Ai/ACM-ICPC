#include <stdio.h>
int main()
{
	long a,b,c,temp;
	int i,t;
	bool flag;
	while(scanf("%ld%ld%ld",&a,&b,&c)!=EOF)
	{
		t=0;
		if(a<b)
		{
			t=1;
			temp=a;
			a=b;
			b=temp;
		}
		flag=0;
		for(i=(c-0.1)/a;i>0;i--)
			if((c-a*i)%b==0)
			{
				flag=1;
				break;
			}
		if(flag)
		{
			if(t)
				printf("%d %d\n",(c-a*i)/b,i);
			else
				printf("%d %d\n",i,(c-a*i)/b);
		}
		else
			printf("No solution\n");
	}
	return 0;
}


