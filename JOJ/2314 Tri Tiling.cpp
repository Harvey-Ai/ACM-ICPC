#include <stdio.h>
int main()
{
	double f[31];
	int i,j,n;
	for(i=0;i<=30;i++)
		f[i]=0;
	f[0]=1;
	for(i=2;i<=30;i+=2)
	{
		f[i]+=f[i-2];
		for(j=i-2;j>=0;j-=2)
			f[i]+=2*f[j];
	}
	while(scanf("%d",&n),n!=-1)
		printf("%.0lf\n",f[n]);
	return 0;
}
