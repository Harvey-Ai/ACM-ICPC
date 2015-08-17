/*
Description

Farmer John has been informed of the location of a fugitive cow and wants to catch her immediately. He starts at a point N (0 ≤ N ≤ 100,000) on a number line and the cow is at a point K (0 ≤ K ≤ 100,000) on the same number line. Farmer John has two modes of transportation: walking and teleporting.

* Walking: FJ can move from any point X to the points X - 1 or X + 1 in a single minute
* Teleporting: FJ can move from any point X to the point 2 × X in a single minute.

If the cow, unaware of its pursuit, does not move at all, how long does it take for Farmer John to retrieve it?

Input

Line 1: Two space-separated integers: N and K
Output

Line 1: The least amount of time, in minutes, it takes for Farmer John to catch the fugitive cow.
Sample Input

5 17
Sample Output

4
Hint

The fastest way for Farmer John to reach the fugitive cow is to move along the following path: 5-10-9-18-17, which takes 4 minutes.
*/


#include <stdio.h>
int main()
{
	bool flag[100005];
	int buf[100005];
	int i,l,r,rr,n,k,rel,max;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		if(n>=k)
		{
			printf("%d\n",n-k);
			continue;
		}
		for(i=0;i<=k+1;i++) flag[i]=0;
		l=0;r=1;
		buf[0]=n;
		flag[n]=1;
		rel=0;
		while(1)
		{
			rr=r;
			for(i=l;i<rr;i++)
			{
				if(buf[i]+1<=k&&!flag[buf[i]+1])
				{
					buf[r++]=buf[i]+1;
					flag[buf[i]+1]=1;
				}
				if(buf[i]-1>=0&&!flag[buf[i]-1])
				{
					buf[r++]=buf[i]-1;
					flag[buf[i]-1]=1;
				}
				if(buf[i]*2<=k+1&&!flag[buf[i]*2])
				{
					buf[r++]=buf[i]*2;
					flag[buf[i]*2]=1;
				}
			}
			rel++;
			if(flag[k])
				break;
			l=rr;
		}
		printf("%d\n",rel);
	}
	return 0;
}
