#include <iostream>
#include <math.h>
using namespace std;
#define zerro 1e-6
int main()
{
	long long n;
	int i,b,max,k;
	while(cin>>n,n)
	{
		if(n<0)
			k=2;
		else
			k=1;
		if(n<0)
			n=-n;
		i=1;max=1;b=2;
		while(b>1)
		{
			i+=k;
			b=int(pow(n,1.0/i)+zerro);
			if(fabs(pow(b,i)-n)<zerro)
				max=i;
		}
		cout<<max<<endl;
	}
	return 0;
}






















/*


				#include <stdio.h>
int main()
{
 double x,y,b,r;
 int p;
 while(scanf("%lf",&x)!=-1&&x)
 {
  p=0;
  y=x;
  if(x<0)
   y=-x;
  for(b=2;b*b<=y;b++)
  {
   r=b*b;
   p=2;
   while(r<y)
   {
    r=r*b;
    p++;
   }
   if(r==y)
   {
    if(x>0||p%2)
    {
     printf("%d\n",p);
     p=1;
     break;
    }
   }
  }
  if(p!=1)printf("1\n");
 } 
}
*/


