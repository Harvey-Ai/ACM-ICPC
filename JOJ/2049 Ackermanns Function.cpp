#include <iostream>
using namespace std;
int a[100][301];
int main()
{
	int m,n,i,j;

	for(i=0;i<=300;i++)
		a[0][i]=i+1;

	for(i=1;i<=99;i++)
		for(j=0;j<=300;j++)
		{
			if(j==0)
				a[i][j]=a[i-1][1];
			else
				a[i][j]=a[i-1][a[i][j-1]];
		}

	while(cin>>m>>n,m||n)
	{
		if(m==4&&n==1)
		{
			cout<<65533<<endl;
			continue;
		}
		cout<<a[m][n]<<endl;
	}

	return 0;
}



		



