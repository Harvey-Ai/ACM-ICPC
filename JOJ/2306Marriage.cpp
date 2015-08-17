/*
#include <iostream>
using namespace std;
int men[300000],women[300000];
int main()
{
	int i,j,n,max,sum;
	while(cin>>n,n)
	{
		i=0;
		while(i++<n)
			cin>>men[i-1];
		i=0;
		while(i++<n)
			cin>>women[i-1];
		sum=0;max=-1;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				if(women[j]==men[i])
				{
					if(j==i&&max<j)
						sum++;
					if(j>max)
						max=j;
					break;
				}
		}
		cout<<n-sum<<endl;
	}
	return 0;
}
*/

#include <iostream>
using namespace std;
int p[300000];
int main()
{
	int i,n,sum,max;
	while(cin>>n,n)
	{
		sum=n;max=1;
		for(i=0;i<n;i++)
			cin>>p[0];
		for(i=0;i<n;i++)
			cin>>p[i];
		for(i=0;i<n;i++)
		{

		cout<<sum<<endl;
	}
	return 0;
}










