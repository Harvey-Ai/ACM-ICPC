#include <iostream>
using namespace std;
int main()
{
	int w[21][21][21];
	int i,j,k;
	for(i=0;i<=20;i++)
		for(j=0;j<=20;j++)
		{
			w[i][j][0]=1;
			w[0][i][j]=1;
			w[i][0][j]=1;
		}
	for(i=1;i<=20;i++)
		for(j=1;j<=20;j++)
			for(k=1;k<=20;k++)
			{
				if(i<j&&j<k)
					w[i][j][k]=w[i][j][k-1]+w[i][j-1][k-1]-w[i][j-1][k];
				else
					w[i][j][k]=w[i-1][j][k]+w[i-1][j-1][k]+w[i-1][j][k-1]-w[i-1][j-1][k-1];
			}
		while(cin>>i>>j>>k,i+1||j+1||k+1)
		{
			cout<<"w("<<i<<", "<<j<<", "<<k<<") = ";
			if(i<=0||j<=0||k<=0)
			{
				cout<<1<<endl;
				continue;
			}
			if(i<=20&&j<=20&&k<=20)
				cout<<w[i][j][k]<<endl;
			else
				cout<<w[20][20][20]<<endl;
		}
	return 0;
}

		


