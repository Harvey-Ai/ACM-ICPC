#include <stdio.h>
#include <string>
int main()
{
	int wet[15],cnt[15],arr[15][1010];
	int i,j,temp,n,rel;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
			scanf("%d",&wet[i]);
		for(i=0;i<n;i++)
			scanf("%d",&cnt[i]);

		for(i=0;i<n;i++)
		{
			memset(arr[i],0,sizeof(arr[i]));
			arr[i][0]=1;
		}

		while(cnt[0])
		{
			arr[0][wet[0]*cnt[0]]=1;
			cnt[0]--;
		}
		for(i=1;i<n;i++)
			for(j=0;j<1000;j++)
			{
				if(arr[i-1][j])
				{
					arr[i][j]=1;
					temp=cnt[i];
					while(temp)
					{
						arr[i][wet[i]*temp+j]=1;
						if(wet[i]*temp>j)
							arr[i][wet[i]*temp-j]=1;
						else
							arr[i][j-wet[i]*temp]=1;
						temp--;
					}
				}
			}
		rel=0;
		for(i=1;i<1000;i++)
			if(arr[n-1][i])
				rel++;
		printf("%d\n",rel);
	}
	return 0;
}


