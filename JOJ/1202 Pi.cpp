#include <stdio.h>
#include <math.h>
int main()
{
	int prime(int n,int m);
	int i,j,n,cnt,arr[60];
	while(scanf("%d",&n),n)
	{
		cnt=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
			for(j=0;j<i;j++)
				if(prime(arr[i],arr[j])==1)
					cnt++;
		}
		if(cnt)
			printf("%.6lf\n",sqrt((3.0*n*(n-1))/cnt));
		else
			printf("No estimate for this data set.\n");
	}
	return 0;
}

int prime(int n,int m)
{
	if(n%m)
		return prime(m,n%m);
	else
		return m;
}
	


