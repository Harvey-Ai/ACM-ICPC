#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	bool cmp(int arr1[13],int arr2[13]);
	int m,n,i,j,k,bin,temp,sum;
	int intger[13],rel[90][13];
	while(scanf("%d%d",&m,&n),m||n)
	{
		for(i=0;i<n;i++)
			scanf("%d",&intger[i]);
		bin=pow(2,n)-1;
		i=0;
		while(bin>0)
		{
			temp=bin;sum=0;k=1;
			for(j=n-1;temp;j--)
			{
				if(temp%2)
				{
					sum+=intger[j];
					rel[i][k]=intger[j];
					k++;
				}
				temp/=2;
			}
			if(sum==m)
			{
				rel[i][0]=k-1;
				i++;
				for(j=0;j<i-1;j++)
					if(cmp(rel[j],rel[i-1]))
					{
						i--;
						break;
					}
			}
			bin--;
		}
		printf("Sums of %d:\n",m);
		if(i==0)
			printf("NONE\n");
		for(j=0;j<i;j++)
		{
			printf("%d",rel[j][rel[j][0]--]);
			k=rel[j][0];
			while(k)
			{
			   	printf("+%d",rel[j][k]);
			   	k--;
			}
			printf("\n");
		}
	}
	return 0;
}

bool cmp(int arr1[13],int arr2[13])
{
	int i;
	if(arr1[0]!=arr2[0])
		return 0;
	for(i=1;i<=arr1[0];i++)
		if(arr1[i]!=arr2[i])
			return 0;
	return 1;
}
