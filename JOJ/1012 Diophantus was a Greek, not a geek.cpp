/*
#include <iostream>
using namespace std;
int main()
{
	int n,i,j;
	int a,b,c;
	bool flag;
	cin>>n;
	while(n--)
	{
		flag=0;
		cin>>a;
		getchar();getchar();
		cin>>b;
		getchar();getchar();
		cin>>c;
		cout<<a<<"x+"<<b<<"y="<<c;

		for(i=0;i*a<=c;i++)
			for(j=0;j*b<=c;j++)
				if(i*a+j*b==c)
				{
					flag=1;
					break;
				}
		if(flag)
			cout<<" has a solution."<<endl;
		else
			cout<<" has no solution."<<endl;
	}
	return 0;
}
*/

#include <iostream>
using namespace std;
int main()
{
	int n,a,b,c,temp;
	int f(int a,int b);
	cin>>n;
	while(n--)
	{
		cin>>a;
		getchar();getchar();
		cin>>b;
		getchar();getchar();
		cin>>c;
		cout<<a<<"x+"<<b<<"y="<<c;
		if(b>a)
		{
			temp=a;
			a=b;
			b=temp;
		}
		if(c%f(a,b))
			cout<<" has no solution."<<endl;
		else
			cout<<" has a solution."<<endl;
	}
	return 0;
}

int f(int a,int b)
{
	if(b==0)
		return a;
	else
		return f(b,a%b);
}






