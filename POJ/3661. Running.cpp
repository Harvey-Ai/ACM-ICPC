/*
Description

The cows are trying to become better athletes, so Bessie is running on a track for exactly N (1 ≤ N ≤ 10,000) minutes. During each minute, she can choose to either run or rest for the whole minute.

The ultimate distance Bessie runs, though, depends on her 'exhaustion factor', which starts at 0. When she chooses to run in minute i, she will run exactly a distance of Di (1 ≤ Di ≤ 1,000) and her exhaustion factor will increase by 1 -- but must never be allowed to exceed M (1 ≤ M ≤ 500). If she chooses to rest, her exhaustion factor will decrease by 1 for each minute she rests. She cannot commence running again until her exhaustion factor reaches 0. At that point, she can choose to run or rest.

At the end of the N minute workout, Bessie's exaustion factor must be exactly 0, or she will not have enough energy left for the rest of the day.

Find the maximal distance Bessie can run.

Input

* Line 1: Two space-separated integers: N and M
* Lines 2..N+1: Line i+1 contains the single integer: Di

Output

* Line 1: A single integer representing the largest distance Bessie can run while satisfying the conditions.
　

Sample Input

5 2
5
3
4
2
10
Sample Output

9
*/

#include <stdio.h>
#include <string.h>
int arr[10001],dp[10001][501][2];
int main()
{
	int i,j,n,m,temp;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);
		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;i++)
		{
			temp=dp[i-1][0][1];
			if(dp[i-1][1][0]>temp)
				temp=dp[i-1][1][0];
			dp[i][0][1]=temp;
			for(j=1;j<m;j++)
			{
				dp[i][j][1]=dp[i-1][j-1][1]+arr[i-1];
				temp=dp[i][j][1];
				if(temp<dp[i-1][j+1][0])
					temp=dp[i-1][j+1][0];
				dp[i][j][0]=temp;
			}
			dp[i][m][0]=dp[i-1][m-1][1]+arr[i-1];
		}
		printf("%d\n",dp[n][0][1]);
	}
	return 0;
}
