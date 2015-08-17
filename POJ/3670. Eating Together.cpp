/*
Description

The cows are so very silly about their dinner partners. They have organized themselves into three groups (conveniently numbered 1, 2, and 3) that insist upon dining together. The trouble starts when they line up at the barn to enter the feeding area.

Each cow i carries with her a small card upon which is engraved Di (1 ≤ Di ≤ 3) indicating her dining group membership. The entire set of N (1 ≤ N ≤ 30,000) cows has lined up for dinner but it's easy for anyone to see that they are not grouped by their dinner-partner cards.

FJ's job is not so difficult. He just walks down the line of cows changing their dinner partner assignment by marking out the old number and writing in a new one. By doing so, he creates groups of cows like 111222333 or 333222111 where the cows' dining groups are sorted in either ascending or descending order by their dinner cards.

FJ is just as lazy as the next fellow. He's curious: what is the absolute mminimum number of cards he must change to create a proper grouping of dining partners? He must only change card numbers and must not rearrange the cows standing in line.

Input

* Line 1: A single integer: N
* Lines 2..N+1: Line i describes the i-th cow's current dining group with a single integer: Di

Output

* Line 1: A single integer representing the minimum number of changes that must be made so that the final sequence of cows is sorted in either ascending or descending order

Sample Input

5
1
3
2
1
1
Sample Output

1
*/


#include <stdio.h>
int arr[30005],dp[30005][5];
int main()
{
	int i,min,temp,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	dp[0][1]=dp[0][2]=dp[0][3]=0;
	for(i=1;i<=n;i++)
	{
		if(arr[i]==1)
		{
			dp[i][1]=dp[i-1][1];
			if(dp[i-1][2]>dp[i-1][1])
				dp[i][2]=dp[i-1][1]+1;
			else
				dp[i][2]=dp[i-1][2]+1;
			if(dp[i-1][2]>dp[i-1][3])
				temp=dp[i-1][3];
			else
				temp=dp[i-1][2];
			if(temp>dp[i-1][1])
				temp=dp[i-1][1];
			dp[i][3]=temp+1;
		}
		else
		{
			if(arr[i]==2)
			{
				dp[i][1]=dp[i-1][1]+1;
				if(dp[i-1][2]<dp[i-1][1])
					dp[i][2]=dp[i-1][2];
				else
					dp[i][2]=dp[i-1][1];
				if(dp[i-1][2]>dp[i-1][3])
					temp=dp[i-1][3];
				else
					temp=dp[i-1][2];
				if(temp>dp[i-1][1])
					temp=dp[i-1][1];
				dp[i][3]=temp+1;
			}
			else
			{
				dp[i][1]=dp[i-1][1]+1;
				if(dp[i-1][2]>dp[i-1][1])
					dp[i][2]=dp[i-1][1]+1;
				else
					dp[i][2]=dp[i-1][2]+1;
				if(dp[i-1][2]>dp[i-1][3])
					temp=dp[i-1][3];
				else
					temp=dp[i-1][2];
				if(temp>dp[i-1][1])
					temp=dp[i-1][1];
				dp[i][3]=temp;
			}
		}
	}
	min=dp[n][1];
	if(dp[n][2]<min)
		min=dp[n][2];
	if(dp[n][3]<min)
		min=dp[n][3];
	for(i=1;i<=n/2;i++)
	{
		temp=arr[i];
		arr[i]=arr[n-i+1];
		arr[n-i+1]=temp;
	}
	for(i=1;i<=n;i++)
	{
		if(arr[i]==1)
		{
			dp[i][1]=dp[i-1][1];
			if(dp[i-1][2]>dp[i-1][1])
				dp[i][2]=dp[i-1][1]+1;
			else
				dp[i][2]=dp[i-1][2]+1;
			if(dp[i-1][2]>dp[i-1][3])
				temp=dp[i-1][3];
			else
				temp=dp[i-1][2];
			if(temp>dp[i-1][1])
				temp=dp[i-1][1];
			dp[i][3]=temp+1;
		}
		else
		{
			if(arr[i]==2)
			{
				dp[i][1]=dp[i-1][1]+1;
				if(dp[i-1][2]<dp[i-1][1])
					dp[i][2]=dp[i-1][2];
				else
					dp[i][2]=dp[i-1][1];
				if(dp[i-1][2]>dp[i-1][3])
					temp=dp[i-1][3];
				else
					temp=dp[i-1][2];
				if(temp>dp[i-1][1])
					temp=dp[i-1][1];
				dp[i][3]=temp+1;
			}
			else
			{
				dp[i][1]=dp[i-1][1]+1;
				if(dp[i-1][2]>dp[i-1][1])
					dp[i][2]=dp[i-1][1]+1;
				else
					dp[i][2]=dp[i-1][2]+1;
				if(dp[i-1][2]>dp[i-1][3])
					temp=dp[i-1][3];
				else
					temp=dp[i-1][2];
				if(temp>dp[i-1][1])
					temp=dp[i-1][1];
				dp[i][3]=temp;
			}
		}
	}
	if(dp[n][1]<min)
		min=dp[n][1];
	if(dp[n][2]<min)
		min=dp[n][2];
	if(dp[n][3]<min)
		min=dp[n][3];
	printf("%d\n",min);
	return 0;
}
