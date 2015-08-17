#include <iostream>
#include <string>
using namespace std;
int main()
{
	int i,j,k,l,n,m,A[20][20];
	string s[20][20],name[20]={"\0"},name1,name2;
	cin>>n;l=-1;
	while(n--)
	{
		l++;
		cin>>name[l];
		cin>>m;
		s[l][m]="\0";
		while(m--)
			cin>>s[l][m];
	}
	for(i=0;i<20;i++)
		for(j=0;j<20;j++)
			A[i][j]=0;

	for(i=0;i<=l;i++)
	{
		j=0;
		while(s[i][j]!="\0")
		{
			for(k=0;k<=l;k++)
				if(s[i][j]==name[k])
					break;
			A[i][k]=1;
			j++;
		}
	}

	for(k=0;k<=l;k++)
		for(i=0;i<=l;i++)
			if(i!=k)
				for(j=0;j<=l;j++)
					if(j!=k&&j!=i&&A[i][k]!=0&&A[k][j]!=0&&(A[i][k]+A[k][j]<A[i][j]||A[i][j]==0))
						A[i][j]=A[i][k]+A[k][j];

	cin>>n;
	while(n--)
	{
		cin>>name1>>name2;
		for(i=0;i<20;i++)
		{
			if(name1==name[i])
				k=i;
			if(name2==name[i])
				l=i;
		}
		if(A[k][l]==0)
			cout<<name1<<" has no connection to "<<name2<<"."<<endl;
		else
			cout<<name1<<" is separated from "<<name2<<" by "<<A[k][l]-1<<" degrees."<<endl;
	}
	return 0;
}



			







			
