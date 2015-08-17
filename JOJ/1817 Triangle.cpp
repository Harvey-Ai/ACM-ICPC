#include <iostream>
using namespace std;
int main()
{
	int a,b,c,t,k=0;;
	while(cin>>a>>b>>c)
	{
		k++;
		if(a<b)
		{
			t=a;
			a=b;
			b=t;
		}
		if(a<c)
		{
			t=a;
			a=c;
			c=t;
		}
		if(b+c<=a)
			cout<<"Case "<<k<<": is not a valid triangle."<<endl;
		else
			if(b*b+c*c>a*a)
				cout<<"Case "<<k<<": is a sharp triangle."<<endl;
			else
				if(b*b+c*c<a*a)
					cout<<"Case "<<k<<": is a blunt triangle."<<endl;
				else
					cout<<"Case "<<k<<": is a right triangle."<<endl;
	}
	return 0;
}