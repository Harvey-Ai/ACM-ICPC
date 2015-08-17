/*
#include <iostream>
using namespace std;
int set[1000000][2];
int main()
{
	int n,i,j;
	bool flag;
	while(cin>>n)
	{
		for(i=1;i<=n;i++)
		{
			cin>>set[i][0]>>set[i][1];
		}

		for(i=1;i<=n;i++)
		{
			for(j=i;j<=n;j++)
			{
				flag=0;
				if(set[i][0]==set[j][1]&&set[i][1]==set[j][0])
				{
					flag=1;
					set[j][0]=0;
					set[j][1]=0;
					break;
				}
			}
			if(flag==0)
				break;
		}
		if(flag)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
*/
#include <iostream>
using namespace std;
int a1[100001],a2[100001];
int main()
{
	int i,n,x,y;
	while(cin>>n)
	{
		for(i=0;i<=100000;i++)
			a1[i]=a2[i]=0;

		for(i=0;i<=n-1;i++)
		{
			cin>>x>>y;
			a1[x]+=y;a2[y]+=x;
		}

		for(i=0;i<=100000;i++)
		{
			if(a1[i]!=a2[i])
			{
				cout<<"No"<<endl;
				break;
			}
		}
		if(a1[i]==a2[i])
			cout<<"Yes"<<endl;
	}
	return 0;
}
