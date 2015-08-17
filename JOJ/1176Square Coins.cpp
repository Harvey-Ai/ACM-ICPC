#include <iostream>
using namespace std;
int main()
{
	int w[20][301];
	int i,j,k,n,res;
	for(i=1;i<=19;i++)
		for(j=0;j<=300;j++)
		{
			if(i==1||j==0)
				w[i][j]=1;
			else
				w[i][j]=0;
		}

	for(i=2;i<=19;i++)
		for(j=1;j<=300;j++)
		{
			k=0;
			while((j-k*i*i)>=0)
			{
				w[i][j]+=w[i-1][j-k*i*i];
				k++;
			}
		}
	while(cin>>n,n)
		cout<<w[19][n]<<endl;
	return 0;
}
		


