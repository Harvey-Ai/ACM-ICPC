#include <iostream.h>
using namespace std;
int main()
{
	int i,j,l,n;
	double a[10000],b[10000];
	l=1;
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;i++)
		{
			scanf("%lf",&a[i]);
			b[i]=a[i];
		}
		for(i=1;i<n;i++)
		{
			for(j=i-1;j>=0;j--)
			{
				if(a[i]>=a[j]&&b[i]<(b[j]+a[i]))
					b[i]=b[j]+a[i];
			}
		}
		j=0;
		for(i=1;i<n;i++)
		{
			if(b[i]>b[j])
				j=i;
		}
		if(l!=1)
			printf("\n");
		printf("Case #%d:\n",l++);
		cout.setf(ios::fixed);
		cout.precision(0);
		printf("%.0lf\n",b[j]);
	}
	return 0;
}

