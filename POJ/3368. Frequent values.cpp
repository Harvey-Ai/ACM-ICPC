/*
Description

You are given a sequence of n integers a1 , a2 , ... , an in non-decreasing order. In addition to that, you are given several queries consisting of indices i and j (1 ≤ i ≤ j ≤ n). For each query, determine the most frequent value among the integers ai , ... , aj.

Input

The input consists of several test cases. Each test case starts with a line containing two integers n and q (1 ≤ n, q ≤ 100000). The next line contains n integers a1 , ... , an (-100000 ≤ ai ≤ 100000, for each i ∈ {1, ..., n}) separated by spaces. You can assume that for each i ∈ {1, ..., n-1}: ai ≤ ai+1. The following q lines contain one query each, consisting of two integers i and j (1 ≤ i ≤ j ≤ n), which indicate the boundary indices for the 
query.

The last test case is followed by a line containing a single 0.

Output

For each query, print one line with one integer: The number of occurrences of the most frequent value within the given range.

Sample Input

10 3
-1 -1 1 1 1 1 3 10 10 10
2 3
1 10
5 10
0
Sample Output

1
4
3
*/


#include <iostream>
#include <cstdio>
using namespace std;

int compressSeg[100005][3];
int segNum;
int segIndex[100005];

int rmq[20][100005];
void rmpInit()
{
	for(int i = 0;i < segNum;i++)
		rmq[0][i] = compressSeg[i][0];

	for(int i = 2, k = 1;i <= segNum;i <<= 1, k++)
		for(int j = 0;j + i < segNum;j++)
			rmq[k][j] = max(rmq[k - 1][j], rmq[k - 1][j + i >> 1]);
}

int getRMQ(int start, int end)
{
	if (start > end)
		return 0;

	int index = 0, len = 1;
	while(len * 2 <= end - start + 1)
	{
		len *= 2;
		index++;
	}

	return max(rmq[index][start], rmq[index][end - len + 1]);
}

int main()
{
	int n, m;
    int arr[100005];
	while(scanf("%d", &n), n)
	{
		scanf("%d", &m);
		for(int i = 0;i < n;i++)
			scanf("%d", &arr[i]);

		segNum = 0;
		int startIndex = 0;
		for(int i = 1;i < n;i++)
			if (arr[i] != arr[i - 1])
			{
				compressSeg[segNum][0] = i - startIndex;
				compressSeg[segNum][1] = startIndex;
				compressSeg[segNum++][2] = i - 1;

				for(int j = startIndex;j < i;j++)
					segIndex[j] = segNum - 1;
				startIndex = i;
			}
		compressSeg[segNum][0] = n - startIndex;
		compressSeg[segNum][1] = startIndex;
		compressSeg[segNum++][2] = n - 1;
		for(int j = startIndex;j < n;j++)
			segIndex[j] = segNum - 1;

		rmpInit();
		for(int i = 0;i < m;i++)
		{
			int begin, end;
			scanf("%d %d", &begin, &end);
			begin--, end--;
			int seg1 = segIndex[begin];
			int seg2 = segIndex[end];

			if (seg1 == seg2)
                printf("%d\n", end - begin + 1);
			else if (seg2 == seg1 + 1)
                printf("%d\n", max(compressSeg[seg1][2] - begin + 1, end - compressSeg[seg2][1] + 1));
			else
			{
				int res = max(compressSeg[seg1][2] - begin + 1, end - compressSeg[seg2][1] + 1);
				res = max(res, getRMQ(seg1 + 1, seg2 - 1));
				printf("%d\n", res);
			}
		}
	}
	return 0;
}
