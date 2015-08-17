/*
Description

Given m sequences, each contains n non-negative integer. Now we may select one number from each sequence to form a sequence with m integers. It's clear that we may get n ^ m this kind of sequences. Then we can calculate the sum of numbers in each sequence, and get n ^ m values. What we need is the smallest n sums. Could you help us?
Input

The first line is an integer T, which shows the number of test cases, and then T test cases follow. The first line of each case contains two integers m, n (0 < m <= 100, 0 < n <= 2000). The following m lines indicate the m sequence respectively. No integer in the sequence is greater than 10000.
Output

For each test case, print a line with the smallest n sums in increasing order, which is separated by a space.
Sample Input

1
2 3
1 2 3
2 2 3
Sample Output

3 3 4
*/


#include <stdio.h>
#include <algorithm>
using namespace std;
int heap[2005];
int m,n;
void resort(int root) //重建堆
{
	int j,t,temp;
	j=root;
	while(j<=n/2)
	{
		if(heap[j*2]<heap[j*2+1]&&2*j<n)
			t=j*2+1;
		else
			t=j*2;
		if(heap[j]<heap[t])
		{
			temp=heap[j];
			heap[j]=heap[t];
			heap[t]=temp;
			j=t;
		}
		else
			j=n;
	}
}
int main()
{
	int arr[2005],dp[2005];
	int i,j,N;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d%d",&m,&n);
		m--;
		for(i=0;i<n;i++) 
		{
			scanf("%d",&arr[i]);
			heap[i+1]=arr[i];
		}
		for(i=n/2;i>=1;i--)
			resort(i);
		sort(&arr[0],&arr[n]);
		for(i=0;i<n;i++)
			dp[i]=arr[i];
		while(m--)
		{
			for(i=0;i<n;i++) scanf("%d",&arr[i]);
			sort(&arr[0],&arr[n]);
			for(i=1;i<=n;i++) 
				heap[i]+=arr[0];
			for(i=1;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					if(arr[i]+dp[j]<heap[1])
					{
						heap[1]=arr[i]+dp[j];
						resort(1);
					}
					else
						break;
				}
			}
			for(i=1;i<=n;i++)
				dp[i-1]=heap[i];
			sort(&dp[0],&dp[n]);
		}
		printf("%d",dp[0]);
		for(i=1;i<n;i++)
			printf(" %d",dp[i]);
		printf("\n");
	}
	return 0;
}
