/*
#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	int arr[500];
	int i,j,n,k,sum,rel;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		for(i=0;i<k;i++)
			scanf("%d",&arr[i]);
		sort(&arr[0],&arr[k]);
		rel=0;
		for(i=0;i<k;i++)
		{
			sum=0;
			for(j=i;j<k;j++)
			{
				if(sum+arr[j]<=n)
					sum+=arr[j];
				else
					break;
			}
			if(sum>rel)
				rel=sum;
		}
		printf("sum:%d\n",rel);
	}
	return 0;
}
*/
/*
#include <stdio.h>
bool arr[100][50000];
int main()
{
	int tr[500];
	int i,j,n,k;
	bool flag;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		for(i=0;i<=k;i++)
			for(j=0;j<=n;j++)
				arr[i][j]=0;

		for(i=0;i<k;i++)
		{
			scanf("%d",&tr[i]);
			arr[i][tr[i]]=1;
		}

		for(i=1;i<k;i++)
		{
			flag=0;
			for(j=0;j<=n;j++)
				if(arr[i-1][j])
				{
					arr[i][j+tr[i]]=1;
					arr[i][j]=1;
				}
			if(arr[i][n])
			{
				flag=1;
				break;
			}
		}
		if(flag)
			printf("sum:%d\n",n);
		else
		{
			for(i=n;i>0;i--)
				if(arr[k-1][i])
					break;
			printf("sum:%d\n",i);
		}
	}
	return 0;
}
*/

#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
bool arr[50000],buffer[50000];
int main()
{
	int tr[200];
	int i,j,m,n,k;
	bool flag;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		for(j=0;j<=n;j++)
			arr[j]=0;
		for(i=0;i<k;i++)
			scanf("%d",&tr[i]);
		sort(&tr[0],&tr[k]);
		for(i=0;i<k;i++)
		{
			flag=0;
			//if(n>=tr[i])
			//	m=n-tr[i];
			for(j=0;j<=n;j++)
				buffer[j]=0;
			buffer[tr[i]]=1;
			for(j=0;j<=m;j++)
				if(arr[j])
				{
					buffer[j]=1;
					buffer[j+tr[i]]=1;
				}
			if(buffer[n])
			{
				flag=1;
				break;
			}
			memcpy(arr,buffer,n);
		}
		if(flag)
			printf("sum:%d\n",n);
		else
		{
			for(i=n;i>0;i--)
				if(arr[i])
					break;
			printf("sum:%d\n",i);
		}
	}
	return 0;
}

