#include <stdio.h>
#include <math.h>
#define pi 3.1415926535898
int main()
{
	double d,s,r,du1,du2,temp,rel;
	bool flag;
	while(scanf("%lf%lf",&d,&s)!=EOF)
	{
		if(s>d*pi/2)
		{
			s=d*pi-s;
			flag=1;
		}
		else
			flag=0;
		du1=0;du2=pi;
		temp=d*(du1+du2)/2-sin((du1+du2)/2)*s;
		while(temp>1e-10||temp<-1e-10)
		{
			if(temp>1e-10)
				du2=(du1+du2)/2;
			else
				du1=(du1+du2)/2;
			temp=d*(du1+du2)/2-sin((du1+du2)/2)*s;
		}
		du1=(du1+du2)/2;

		rel=0;
		r=(d/2)/sin(du1);
		if(flag)
		{
			rel+=(2*pi-2*du1)*r*r;
			rel+=(d/2)*r*cos(du1);
		}
		else
		{
			rel+=2*du1*r*r;
			rel-=(d/2)*r*cos(du1);
		}
		printf("%.3lf\n",rel);
	}
	return 0;
}



