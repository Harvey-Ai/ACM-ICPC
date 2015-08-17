//
#include <stdio.h>
long arr[2100][2100];
int main()
{
	int min_id[2100];
	long min;
	int i,j,k,l,t,m,n;
	bool flag;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		t=0;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				scanf("%ld",&arr[i][j]);

		for(i=0;i<n;i++)
		{
			min=arr[i][0];min_id[0]=0;k=0;
			for(j=1;j<m;j++)
			{
				if(arr[i][j]<min)
				{
					min=arr[i][j];
					k=0;
					min_id[k]=j;
				}
				else
					if(arr[i][j]==min)
					{
						k++;
						min_id[k]=j;
					}
			}
			for(j=0;j<=k;j++)
			{
				flag=1;
				for(l=0;l<n;l++)
					if(arr[l][min_id[j]]<min)
					{
						flag=0;
						break;
					}
				if(flag)
				{
					if(t)
						printf(" ");
					else
						t=1;
					printf("%ld",min);
				}
			}
		}
	}
	return 0;
}
