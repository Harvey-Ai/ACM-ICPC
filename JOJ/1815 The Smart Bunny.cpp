#include <iostream>
using namespace std;
int main()
{
	int way[41][11];
	int m,n,i,j,k;

	for(i=0;i<=40;i++)
		for(j=1;j<=10;j++)
			if(j==1||i==0)
				way[i][j]=1;
			else
				way[i][j]=0;

	for(j=2;j<=10;j++)
		for(i=1;i<=40;i++)
		{
			if(i<j)
				way[i][j]=way[i][i];
			else
			for(k=1;k<=j;k++)
				way[i][j]+=way[i-k][j];
		}

	while(cin>>m>>n)
		cout<<way[m][n]<<endl;
	return 0;
}
