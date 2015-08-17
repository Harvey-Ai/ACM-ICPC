#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
int main()
{
	double point[101][2],rd[101];
	double xi,yi,mid,rel;
	int i,n;
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;i++)
			scanf("%lf%lf",&point[i][0],&point[i][1]);
		scanf("%lf%lf",&xi,&yi);

		for(i=0;i<n;i++)
			rd[i]=sqrt((point[i][0]-xi)*(point[i][0]-xi)+(point[i][1]-yi)*(point[i][1]-yi));
		sort(&rd[0],&rd[n]);

		mid=rd[n/2];
		rel=0;
		for(i=0;i<n;i++)
			rel+=fabs(rd[i]-mid);
		printf("%.3lf\n",rel);
	}
	return 0;
}


