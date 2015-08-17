#include <iostream>
using namespace std;
int main()
{
	int search(int t[8][8],int n);
	int i,j,n,graph[8][8];
	char c;
	while(cin>>n,n)
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				cin>>c;
				if(c=='.')
					graph[i][j]=1;
				else
					graph[i][j]=2;
			}
		cout<<search(graph,n)<<endl;;
	}
	return 0;
}

int search(int t[8][8],int n)
{
	int i,j,k,max,temp;
	bool flag;
	max=0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			flag=1;
			for(k=j-1;k>=0;k--)
			{
				if(t[i][k]==0)
				{
					flag=0;
					break;
				}
				if(t[i][k]==2)
					break;
			}
			if(flag)
			{
			for(k=j+1;k<n;k++)
			{
				if(t[i][k]==0)
				{
					flag=0;
					break;
				}
				if(t[i][k]==2)
					break;
			}
			}
			if(flag)
			{
			for(k=i-1;k>=0;k--)
			{
				if(t[k][j]==0)
				{
					flag=0;
					break;
				}
				if(t[k][j]==2)
					break;
			}
			}
			if(flag)
			{
			for(k=i+1;k<n;k++)
			{
				if(t[k][j]==0)
				{
					flag=0;
					break;
				}
				if(t[k][j]==2)
					break;
			}
			}
			if(flag&&t[i][j]==1)
			{
				t[i][j]=0;
				temp=search(t,n);
				if(temp>max)
					max=temp;
				t[i][j]=1;
			}
		}
		if(max==0)
		{
			for(i=0;i<n;i++)
				for(j=0;j<n;j++)
					if(t[i][j]==0)
						max++;
		}
		return max;
}


			