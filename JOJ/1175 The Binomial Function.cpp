/*
#include <iostream>
using namespace std;
int main()
{
	int n,m;
	int Binom(int n,int m);
	while((cin>>n>>m,m||n))
		cout<<"Binom("<<n<<", "<<m<<")"<<" = "<<Binom(n,m)<<endl;
	return 0;
}


int Binom(int n,int m)
{
	if(n==0||m==0||m==n)
		return 1;
	else
		return  Binom(n-1,m)+Binom(n-1,m-1);
}
*/
//以上是递归，不符合题目要求！

/*
#include <iostream>
using namespace std;
int main()
{
	int Binom[100][8];
	int k,top,l,temp;
	while(cin>>Binom[0][0]>>Binom[0][1])
	{
		for(int i=0;i<=99;i++)
		{
			Binom[i][6]=0;
			Binom[i][2]=0;
		}
		k=0;top=0;
		Binom[0][0]=Binom[0][0]-1;Binom[0][1]=Binom[0][1];Binom[0][4]=Binom[0][0];Binom[0][5]=Binom[0][1]-1;

		while(Binom[0][2]==0||Binom[0][6]==0)
		{
			if(Binom[k][2]==0)
			{
				top++;
				Binom[top][0]=Binom[k][0]-1;Binom[top][1]=Binom[k][1];Binom[top][3]=k;
				Binom[top][4]=Binom[k][0]-1;Binom[top][5]=Binom[k][1]-1;Binom[top][7]=1;
			}
			if(Binom[top][0]==0||Binom[top][0]==Binom[top][1]||Binom[top][1]==0)
				Binom[top][2]=1;
			if(Binom[top][4]==0||Binom[top][5]==Binom[top][4]||Binom[top][5]==0)
				Binom[top][6]=1;
			if(Binom[k][6]==0)
			{
				top++;
				Binom[top][0]=Binom[k][4]-1;Binom[top][1]=Binom[k][5];Binom[top][3]=k;
				Binom[top][4]=Binom[k][4]-1;Binom[top][5]=Binom[k][5]-1;Binom[top][7]=5;
			}
			if(Binom[top][0]==0||Binom[top][0]==Binom[top][1]||Binom[top][1]==0)
				Binom[top][2]=1;
			if(Binom[top][4]==0||Binom[top][5]==Binom[top][4]||Binom[top][5]==0)
				Binom[top][6]=1;
			l=top;k++;
			while(Binom[l][2]&&Binom[l][6])
			{
				temp=Binom[l][2]+Binom[l][6];
				Binom[Binom[l][3]][Binom[l][7]+1]=temp;
				l=Binom[l][3];
			}
		}
		cout<<Binom[0][2]+Binom[0][6]<<endl;
	}
	return 0;
}
*/

#include <iostream>
using namespace std;
int main()
{
	int b[900][31];
	int i,j;
	for(i=0;i<=999;i++)
		for(j=0;j<=30;j++)
		{
			if(i==j||i==0||j==0)
				b[i][j]=1;
		}
	for(i=1;i<=999;i++)
		for(j=1;j<=30;j++)
			if(i!=j)
				b[i][j]=b[i-1][j]+b[i-1][j-1];
	while(cin>>i>>j,i||j)
		cout<<"Binom("<<i<<", "<<j<<") = "<<b[i][j]<<endl;
	return 0;
}

				

				










