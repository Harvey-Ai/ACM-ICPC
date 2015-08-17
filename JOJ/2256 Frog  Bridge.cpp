#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	int N,i,j,l,s,t,m,min;
	int arr[1001],stone[100];
	bool flag;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d",&l);
		for(i=0;i<1001;i++)
			arr[i]=10000;

		scanf("%d%d%d",&s,&t,&m);

		for(i=0;i<m;i++)
			scanf("%d",&stone[i]);

		sort(&stone[0],&stone[m]);

		flag=0;
		if(stone[0]==0)
			flag=1;
		if(flag)			
			arr[0]=1;		
		else			
			arr[0]=0;

		for(i=s;i<=t;i++)
		{
			flag=0;
			for(j=0;j<m;j++)
			{
				if(stone[j]==i)
				{
					flag=1;
					break;
				}
				else
				{
					if(stone[j]>i)
						break;
				}
			}
			if(flag)
				arr[i]=arr[0]+1;
			else
				arr[i]=arr[0];
		}

		for(i=t+1;i<=l;i++)
		{
			min=10000;
			for(j=s;j<=t;j++)
				if(arr[i-j]<min)
					min=arr[i-j];

			arr[i]=min;
			flag=0;
			for(j=0;j<m;j++)
			{
				if(stone[j]==i)
				{
					flag=1;
					break;
				}
				else
				{
					if(stone[j]>i)
						break;
				}
			}
			if(flag)
				arr[i]++;
		}

		min=arr[l-t+1];
		for(i=l-t+1;i<=l;i++)
			if(arr[i]<min)
				min=arr[i];
		printf("%d\n",min);
	}
	return 0;
}




	