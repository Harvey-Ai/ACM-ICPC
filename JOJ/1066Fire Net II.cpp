#include <iostream>
using namespace std;
bool check(int t[8][8]);
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
	int i,j,k,max=0,temp;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			if(t[i][j]==1)
			{
				t[i][j]=0;
				if(flag)
					temp=search(t,n);
				if(temp>max)
					max=temp;
				t[i][j]=1;
			}
		}
	if(check(t)&&max!=0)
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(t[i][j]==0)
					max++;
	}
	return max;
}


bool check(int t[8][8])
{
	int i,j;
	bool flag1=0,flag2=0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			if(t[i][j]==0)
			{
				if(flag1)
					return 0;
				else
					flag1=1;
			}
			if(t[i][j]==2)
				flag1=0;
			if(t[j][i]==0)
			{
				if(flag2)
					return 0;
				else
					flag2=2;
			}
			if(t[j][i]==2)
				flag2=0;
		}
	for(//Ð±ÐÐ¼ì²â
}

			
	





