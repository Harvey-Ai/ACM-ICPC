#include <iostream>
#include <math.h>
using namespace std;
#define pi 3.1415926535898
int main()
{
	double a,b,sum,min,max,rel,temp;
	while(cin>>a>>b)
	{
		if(a>b)
		{
			temp=a;
			a=b;
			b=temp;
		}
		sum=pi*a;
		max=pi/2;min=0;rel=pi/4;
		while(rel*(a+b)-(sin(rel)*cos(rel))*(a+b)-sum>1e-6||rel*(a+b)-(sin(rel)*cos(rel))*(a+b)-sum<-1e-6)
		{
			if(rel*(a+b)-(sin(rel)*cos(rel))*(a+b)-sum>1e-6)
			{
				max=rel;
				rel=(min+rel)/2;
			}
			else
			{
				min=rel;
				rel=(max+rel)/2;
			}
		}
		cout.setf(ios::fixed);
		cout.precision(4);
		cout<<2*sin(rel)<<endl;
	}
	return 0;
}
