/*
#include <iostream>
using namespace std;
long long path[2][1000000];
int main()
{
	long n,m,i,j;
	for(i=0;i<10000;i++)
		path[0][i]=1;
	while(cin>>m>>n,m||n)
	{
		for(i=1;i<=n;i++)
		{
			path[1][0]=1;path[0][0]=1;
			for(j=1;j<=m;j++)
				path[1][j]=path[0][j]+path[1][j-1];
			for(j=1;j<=m;j++)
				path[0][j]=path[1][j];
		}
		cout<<path[1][m]<<endl;
	}
	return 0;
}

*/

#include <iostream>
using namespace std;
int main()
{
	double i,j,m,n,temp,rel;
	while(cin>>m>>n,m||n)
	{
		rel=1;
		if(m<n)
		{
			temp=m;
			m=n;
			n=temp;
		}
		j=m+1;
		for(i=1;i<=n;i++)
		{
			rel*=j;
			rel/=i;//归纳，没N个数中肯定有某个数可以除尽N
			j++;
		}
		cout.setf(ios::fixed);
		cout.precision(0);
		cout<<rel<<endl;
	}
	return 0;
}