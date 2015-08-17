/*
题目描述：
Find a longest common subsequence of two strings.
输入：
First and second line of each input case contain two strings of lowercase character a…z. There are no spaces before, inside or after the strings. Lengths of strings do not exceed 100.
输出：
For each case, output k – the length of a longest common subsequence in one line.
样例输入：
abcd
cxbydz
样例输出：
2
*/


#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int dp[105][105];

	int i, j;
	char str1[1000], str2[1000];

	while(cin >> str1)
	{
		cin >> str2;

		memset(dp, 0, sizeof(dp));
		for(i = 0;str1[i] != '\0';i++)
			for(j = 0;str2[j] != '\0';j++)
				if (str1[i] == str2[j])
				{
					dp[i + 1][j + 1] = dp[i][j] + 1;
					if (dp[i + 1][j + 1] < dp[i + 1][j])
						dp[i + 1][j + 1] = dp[i + 1][j];
					if (dp[i + 1][j + 1] < dp[i][j + 1])
						dp[i + 1][j + 1] = dp[i][j + 1];
				}
				else
				{
					if (dp[i + 1][j] > dp[i][j + 1])
						dp[i + 1][j + 1] = dp[i + 1][j];
					else
						dp[i + 1][j + 1] = dp[i][j + 1];
				}
		cout << dp[i][j] << endl;
	}
	return 0;
}
