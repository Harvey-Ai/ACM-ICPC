/*
Description

A tug of war is to be arranged at the local office picnic. For the tug of war, the picnickers must be divided into two teams. Each person must be on one team or the other; the number of people on the two teams must not differ by more than 1; the total weight of the people on each team should be as nearly equal as possible.
Input

The first line of input contains n the number of people at the picnic. n lines follow. The first line gives the weight of person 1; the second the weight of person 2; and so on. Each weight is an integer between 1 and 450. There are at most 100 people at the picnic.
Output

Your output will be a single line containing 2 numbers: the total weight of the people on one team, and the total weight of the people on the other team. If these numbers differ, give the lesser first.
Sample Input

3
100
90
200
Sample Output

190 200

*/


#include <stdio.h>
#include <memory.h>
bool flag[52][25002];
int arr[25002],p[101];
int main()
{
	int i,j,k,n,sum,s,r,t;
	for(i=0;i<52;i++) flag[i][0]=0;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<25002;i++) flag[51][i]=0;
		r=1;arr[0]=0;
		flag[51][0]=1;flag[0][0]=1;
		sum=0;
		for(i=0;i<n;i++) 
		{
			scanf("%d",&p[i]);
			sum+=p[i];
		}
		for(i=0;i<n;i++)
			for(j=0;j<r;j++)
			{
				t=arr[j]+p[i];
				if(t>sum/2)
					continue;
				if(!flag[51][t])
				{
					for(k=0;k<51;k++)
						flag[k][t]=0;
					flag[51][t]=1;
					arr[r]=t;
					r++;
				}
				for(k=0;k<50;k++)
					if(flag[k][arr[j]])
						flag[k+1][t]=1;
			}
		s=n/2;t=(n+1)/2;
		if(s!=t)
		{
			for(i=sum/2;i>=0;i--)
				if((flag[s][i]||flag[t][i])&&flag[51][i])
					break;
		}
		else
		{
			for(i=sum/2;i>=0;i--)
				if(flag[s][i]&&flag[51][i])
					break;
		}
		printf("%d %d\n",i,sum-i);
	}
	return 0;
}
