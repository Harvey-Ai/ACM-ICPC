#include <string>
#include <vector>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std ;
class MakeSquare {
	public:
	int work(char *s1, char *s2)
	{
		int dp[60][60];
		int len1, len2;
		int i, j, temp;
		len1 = strlen(s1);
		len2 = strlen(s2);

		for(i = 0;i <= len1;i++)
			dp[i][0] = i;
		for(i = 0;i <= len2;i++)
			dp[0][i] = i;

		for(i = 0;i < len1;i++)
			for(j = 0;j < len2;j++)
			{
				//mo
				if (s1[i] != s2[j])
					temp = dp[i][j] + 1;
				else
					temp = dp[i][j];
				//ad
				if (temp > dp[i][j + 1] + 1)
					temp =  dp[i][j + 1] + 1;
				//re
				if (temp > dp[i + 1][j] + 1)
					temp = dp[i + 1][j] + 1;
				dp[i + 1][j + 1] = temp;
			}
		return dp[len1][len2];
	}
	int minChanges(string S) {
		int i, j, k;
		char str1[60], str2[60];
		int min, res;
		int len = S.size();
		min = 10000;
		for(i = 1;i <= len;i++)
		{
			for(j = 0;j < i;j++)
				str1[j] = S[j];
			str1[j] = '\0';
			for(k = 0;j < len;j++, k++)
				str2[k] = S[j];
			str2[k] = '\0';
	//		printf("%s %s\n", str1, str2);
			res = work(str1, str2);
	//		printf("%d\n", res);

			if (res < min)
				min = res;
		}
		return min;
	}
};
// BEGIN CUT HERE
int main()
{
	MakeSquare MakeSquare;
	MakeSquare.minChanges("a");
	return 0;
}
// END CUT HERE

