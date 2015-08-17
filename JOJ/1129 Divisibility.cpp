//自己写了两个程序，第一个感觉有点问题，但是过了，第二个改正了，却没过，不知道为什么，。。。
#include <stdio.h>
#include <string.h>
int main()
{
	bool arr[220],buffer[220];
	int i,j,N,n,k,t;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d%d",&n,&k);
		memset(arr,0,sizeof(arr));
		arr[100]=1;
		for(i=0;i<n;i++)
		{
			scanf("%d",&t);
			memset(buffer,0,sizeof(buffer));
			if(t<0)
				t=-t;
			t=t%k;
			if(t==0)
				continue;
			for(j=101-k;j<100+k;j++)
			{
				if(arr[j])
				{
					buffer[(j+t)%k+100]=1;
					buffer[(j-t)%k+100]=1;
				}
			}
			memcpy(arr,buffer,220);
		}
		if(arr[100])
			printf("Divisible\n");
		else
			printf("Not divisible\n");
	}
	return 0;
}


#include <stdio.h>
#include <string.h>
int main()
{
	bool arr[102],buffer[102];
	int i,j,N,n,k,t;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d%d",&n,&k);
		memset(arr,0,sizeof(arr));
		arr[0]=1;
		for(i=0;i<n;i++)
		{
			scanf("%d",&t);
			memset(buffer,0,sizeof(buffer));
			if(t<0)
				t=-t;
			t=t%k;
			if(t==0)
				continue;
			for(j=0;j<k;j++)
			{
				if(arr[j])
				{
					buffer[(j+t+k)%k]=1;
					buffer[(j-t+k)%k]=1;
				}
			}
			memcpy(arr,buffer,k);
		}
		if(arr[0])
			printf("Divisible\n");
		else
			printf("Not divisible\n");
	}
	return 0;
}
