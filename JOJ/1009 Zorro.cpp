#include <stdio.h>
int main()
{
	int i,j,n,cnt;
	bool flag=0;
	while(scanf("%d",&n),n)
	{
		if(flag)
			putchar('\n');
		else
			flag=1;
		cnt=0;
		for(i=0;i<n;i++)
		{
			putchar(cnt+'a');
			cnt++;
			if(cnt>25)
				cnt-=26;
		}
		putchar('\n');
		for(i=n-2;i>0;i--)
		{
			for(j=0;j<i;j++)
				putchar(' ');
			putchar(cnt+'a');
			cnt++;
			if(cnt>25)
				cnt-=26;
			putchar('\n');
		}
		for(i=0;i<n;i++)
		{
			putchar(cnt+'a');
			cnt++;
			if(cnt>25)
				cnt-=26;
		}
		putchar('\n');
	}
	return 0;
}
