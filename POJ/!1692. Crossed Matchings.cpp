/*
Description

There are two rows of positive integer numbers. We can draw one line segment between any two equal numbers, with values r, if one of them is located in the first row and the other one is located in the second row. We call this line segment an r-matching segment. The following figure shows a 3-matching and a 2-matching segment. 


We want to find the maximum number of matching segments possible to draw for the given input, such that: 
1.	Each a-matching segment should cross exactly one b-matching segment, where a != b . 
2.	No two matching segments can be drawn from a number. For example, the following matchings are not allowed. 


Write a program to compute the maximum number of matching segments for the input data. Note that this number is always even.
Input

The first line of the input is the number M, which is the number of test cases (1 <= M <= 10). Each test case has three lines. The first line contains N1 and N2, the number of integers on the first and the second row respectively. The next line contains N1 integers which are the numbers on the first row. The third line contains N2 integers which are the numbers on the second row. All numbers are positive integers less than 100.
Output

Output should have one separate line for each test case. The maximum number of matching segments for each test case should be written in one separate line.
Sample Input

3
6 6
1 3 1 3 1 3
3 1 3 1 3 1
4 4
1 1 3 3 
1 1 3 3 
12 11
1 2 3 3 2 4 1 5 1 3 5 10
3 1 2 3 2 4 12 1 5 5 3 
Sample Output

6
0
8
*/


#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int ncase;
	cin >> ncase;

	int arr1[105], arr2[105];
	int dp[105][105];
	while(ncase--)
	{
		int n1, n2;
		cin >> n1 >> n2;

		for(int i = 0;i < n1;i++)
			cin >> arr1[i];
		for(int i = 0;i < n2;i++)
			cin >> arr2[i];

		memset(dp, 0, sizeof(dp));
		for(int i = 1;i < n1;i++)
			for(int j = 1;j < n2;j++)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				if (arr1[i] != arr2[j])
				{
					int index1 = -1, index2 = -1;
					for(int k = i - 1;k >= 0;k--)
						if (arr1[k] == arr2[j])
						{
							index1 = k;
							break;
						}
						
					for(int l = j - 1;l >= 0;l--)
						if (arr2[l] == arr1[i])
						{
							index2 = l;
							break;
						}
					if (index1 != -1 && index2 != -1)
					{
						if (index1 > 0) 
							dp[i][j] = max(dp[index1 - 1][j - 1] + 1, dp[i][j]);
						if (index2 > 0)
							dp[i][j] = max(dp[i - 1][index2 - 1] + 1, dp[i][j]);
						if (index1 == 0 && index2 == 0)
							dp[i][j] = 1;
					}
				}
			}

		int res = 0;
		for(int i = 0;i < n1;i++)
		{
			for(int j = 0;j < n2;j++)
			{
				res = max(res, dp[i][j]);
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
		cout << res << endl;
	}
	return 0;
}
