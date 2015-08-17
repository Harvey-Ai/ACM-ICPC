/*
Description

A straight dirt road connects two fields on FJ's farm, but it changes elevation more than FJ would like. His cows do not mind climbing up or down a single slope, but they are not fond of an alternating succession of hills and valleys. FJ would like to add and remove dirt from the road so that it becomes one monotonic slope (either sloping up or down).

You are given N integers A1, ... , AN (1 ≤ N ≤ 2,000) describing the elevation (0 ≤ Ai ≤ 1,000,000,000) at each of N equally-spaced positions along the road, starting at the first field and ending at the other. FJ would like to adjust these elevations to a new sequence B1, . ... , BN that is either nonincreasing or nondecreasing. Since it costs the same amount of money to add or remove dirt at any position along the road, the total cost of modifying the road is

|A1 - B1| + |A2 - B2| + ... + |AN - BN |
Please compute the minimum cost of grading his road so it becomes a continuous slope. FJ happily informs you that signed 32-bit integers can certainly be used to compute the answer.

Input

* Line 1: A single integer: N
* Lines 2..N+1: Line i+1 contains a single integer elevation: Ai

Output

* Line 1: A single integer that is the minimum cost for FJ to grade his dirt road so it becomes nonincreasing or nondecreasing in elevation.

Sample Input

7
1
3
2
4
5
3
9
Sample Output

3

*/

#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
int arr[2005],aa[2005],dp[2005][2005];
int main()
{
	int i,j,n,min,res,temp;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		aa[i]=arr[i];
	}
	sort(&aa[0],&aa[n]);
	for(i=0;i<n;i++)
		dp[0][i]=abs(aa[i]-arr[0]);
	for(i=1;i<n;i++)
	{
		min=dp[i-1][0];
		for(j=0;j<n;j++)
		{
			if(dp[i-1][j]<min)
				min=dp[i-1][j];
			dp[i][j]=min+abs(aa[j]-arr[i]);
		}
	}
	res=dp[n-1][0];
	for(i=1;i<n;i++)
		if(dp[n-1][i]<res)
			res=dp[n-1][i];
	for(i=0;i<n/2;i++)
	{
		temp=arr[i];
		arr[i]=arr[n-1-i];
		arr[n-1-i]=temp;
	}
	for(i=0;i<n;i++)
		dp[0][i]=abs(aa[i]-arr[0]);
	for(i=1;i<n;i++)
	{
		min=dp[i-1][0];
		for(j=0;j<n;j++)
		{
			if(dp[i-1][j]<min)
				min=dp[i-1][j];
			dp[i][j]=min+abs(aa[j]-arr[i]);
		}
	}
	for(i=0;i<n;i++)
		if(dp[n-1][i]<res)
			res=dp[n-1][i];
	printf("%d\n",res);
	return 0;
}
