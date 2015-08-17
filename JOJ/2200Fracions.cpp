#include <iostream>
using namespace std;
int main()
{
	int min[101][101];
	int gcd(int a,int b);
	int a,b,i,t,min,sum;
	for(i=1;i<=100;i++)
		for(j=1;j<=100;j++)
			min[i][j]=i*j;

	for(i=1;i<=100;i++)
		for(j=1;j<=100;j++)
		{
			a=i;b=j;
			t=gcd(a,b);
			a/=t;b/=t;
			b*=a;a*=a;
			for(k=1;k<=a/2;k++)
			{

				sum=b/i+b/(a-i);
				if(sum<min)
					min=sum;
			}
	while(cin>>a>>b)
	{
		min=1000000;
		t=gcd(a,b);
		a/=t;b/=t;
		b*=a;a*=a;
		for(i=1;i<=a/2;i++)
			if(b%i==0&&b%(a-i)==0)
			{
				sum=b/i+b/(a-i);
				if(sum<min)
					min=sum;
			}
		cout<<min<<endl;
	}
	return 0;
}


int gcd(int a,int b)
{
	if(a%b)
		return gcd(b,a%b);
	else
		return b;
}
				