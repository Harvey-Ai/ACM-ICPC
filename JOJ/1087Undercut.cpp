#include <iostream>
using namespace std;
int main()
{
	int i,n,suma,sumb;
	int a[100],b[100];
	bool flag=0;
	while(cin>>n,n)
	{
		if(flag)
			cout<<endl;
		else
			flag=1;
		suma=sumb=0;
		i=0;
		while(i++<n)
			cin>>a[i-1];
		i=0;
		while(i++<n)
			cin>>b[i-1];
		i=0;
		while(i++<n)
		{
			if(a[i-1]==1&&b[i-1]==2||a[i-1]==2&&b[i-1]==1)
			{
				if(a[i-1]==1)
					suma+=6;
				else
					sumb+=6;
				continue;
			}
			if(a[i-1]-b[i-1]==-1||a[i-1]-b[i-1]==1)
			{
				if(a[i-1]>b[i-1])
					sumb+=a[i-1]+b[i-1];
				else
					suma+=a[i-1]+b[i-1];
			}
			else
			{
				if(a[i-1]>b[i-1])
					suma+=a[i-1];
				else
					if(a[i-1]!=b[i-1])
						sumb+=b[i-1];
			}
		}
		cout<<"A has "<<suma<<" points. B has "<<sumb<<" points."<<endl;
	}
	return 0;
}



		
