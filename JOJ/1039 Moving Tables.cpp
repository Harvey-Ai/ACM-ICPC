#include <stdio.h>
#include <string>
using namespace std;
int main()
{
	int corridor[220];
	int N,n,i,a,b,max;
	scanf("%d",&N);
	while(N--)
	{
		memset(corridor,0,sizeof(corridor));
		scanf("%d",&n);
		while(n--)
		{
			scanf("%d%d",&a,&b);
			b/=2;
			for(i=a/2;i<=b;i++)
				corridor[i]++;
		}
		max=0;
		for(i=0;i<=200;i++)
			if(corridor[i]>max)
				max=corridor[i];
		printf("%d\n",max*10);
	}
	return 0;
}




