#include <iostream>
using namespace std;
double b[501][501];
int main()
{
	double m;
	int i,j,n;
	for(i=0;i<=500;i++)
		for(j=0;j<=500;j++)
		{
			if(j==i)
				b[i][j]=1;
			else
				b[i][j]=0;
		}
	for(i=3;i<=500;i++)
		for(j=2;j<i;j++)
			b[i][j]+=b[i-j][j-1]+b[i-1][j-1];
	while((cin>>n&&n!=0))
	{
		m=0;
		for(j=2;j<n;j++)
			m+=b[n][j];
		cout.precision(15);
		cout<<m<<endl;
	}
	return 0;
}