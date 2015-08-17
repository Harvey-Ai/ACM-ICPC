//二分法求根
/*
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	double a,b,c,x1,x2,y1,y2,n;
	while(scanf("%lf",&a)!=EOF)
	{
		scanf("%lf",&b);
		scanf("%lf",&c);
		if(b*b-4*a*c>0)
			n=2;
		else
		{
			if(b*b-4*a*c==0)
				n=1;
			else
				n=0;
		}

		if(n==0)
			cout<<"No solution"<<endl;
		else
		{
			if(n==1)
			{
				cout.setf(ios::fixed);
				cout.precision(2);
				cout<<-sqrt(c)/sqrt(a)<<endl;
			}
			else
			{
				x1=x2=(-2*a)/b;
				y1=a*x1*x1+b*x1+c;y2=a*x2*x2+b*x2+c;
				while(y1*y2>0)
				{
					x2+=5;
					y2=a*x2*x2+b*x2+c;
				}

				while(a*(x1+x2)*(x1+x2)/4+b*(x1+x2)/2+c>1e-4||a*(x1+x2)*(x1+x2)/4+b*(x1+x2)/2+c<-1e-4)
				{
					if(a*(x1+x2)*(x1+x2)/4+b*(x1+x2)/2+c>1e-4)
					{
						if(a<0)
							x1=(x1+x2)/2;
						else
							x2=(x1+x2)/2;
					}
					else
					{
						if(a<0)
							x2=(x1+x2)/2;
						else
							x1=(x1+x2)/2;
					}
					
				}
				cout.setf(ios::fixed);
				cout.precision(2);
				cout<<-b/a-(x1+x2)/2<<" "<<(x1+x2)/2<<endl;
			}
		}
	}
	return 0;
}
*/
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	double a,b,c,d;
	while(cin>>a>>b>>c)
	{
		if(b*b-4*a*c<0)
			cout<<"No solution"<<endl;
		else
		{
			if(b*b-4*a*c==0)
			{
				cout.setf(ios::fixed);
				cout.precision(2);
				cout<<-b/(2*a)<<endl;
			}
			else
			{
				d=sqrt(b*b-4*a*c);
				cout.setf(ios::fixed);
				cout.precision(2);
				if(a>0)
				{
					cout<<(-b-d)/(2*a)<<" ";
					cout<<(-b+d)/(2*a)<<endl;
				}
				else
				{
					cout<<(-b+d)/(2*a)<<" ";
					cout<<(-b-d)/(2*a)<<endl;
				}
			}
		}
	}
	return 0;
}




				


