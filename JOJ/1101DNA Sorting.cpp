#include <iostream>
using namespace std;
int main()
{
	char dna[101][51],c;
	int inversion[100],sort[100];
	int N,n,m,i,j,k,temp;
	bool flag=1;
	cin>>N;
	while(N--)
	{
		if(flag==0)
		{
			flag=1;
			cout<<endl;
		}
		cin>>n>>m;
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
				cin>>dna[i][j];
			dna[i][n]='\0';
		}
		for(i=0;i<m;i++)
		{
			sort[i]=i;
			inversion[i]=0;
		}
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
			{
				c=dna[i][j];
				for(k=j+1;k<n;k++)
					if(c>dna[i][k])
						inversion[i]++;
			}
		while(flag)
		{
			flag=0;
			for(i=0;i<m-1;i++)
				if(inversion[i]>inversion[i+1])
				{
					temp=sort[i];
					sort[i]=sort[i+1];
					sort[i+1]=temp;
					temp=inversion[i];
					inversion[i]=inversion[i+1];
					inversion[i+1]=temp;
					flag=1;
				}
		}
		for(i=0;i<m;i++)
			cout<<dna[sort[i]]<<endl;
	}
	return 0;
}





