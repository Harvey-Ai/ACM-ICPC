/*
描述
字符串s和t均由字母组成，若在t中除去一些字母能够得到s，我们就说s是t的一个子串。比如abc就是acbefc的子串
(acbefc去掉第二、第四、第五个字符后就得到abc)
输入
有若干组输入数据，每组一行，分别为字符串s和t，s与t之间用空格隔开
输出
对于一组s与t，若s是t的子串，则输出Yes，否则输出No
样例输入
sequence subsequence
abc acb
VERDI vivaVittorioEmanueleReDiItalia
样例输出
Yes
No
Yes
*/

#include <stdio.h>
#include <string.h>

int main()
{
	char str[205], sub[205];
	int dp[205][205];
	int i, j;
	int len1, len2;
	int max, temp;

	while(scanf("%s %s", sub, str) != EOF)
	{
		len1 = strlen(sub);
		len2 = strlen(str);

		for(i = 0;i < len1;i ++)
			for(j = 0;j < len2;j++)
			{
				max = 0;

				if (i > 0 && max < dp[i - 1][j])
					max = dp[i - 1][j];
				if (j > 0 && max < dp[i][j - 1])
					max = dp[i][j - 1];
				if (sub[i] == str[j])
				{
					if (i > 0 && j > 0)
						temp = dp[i - 1][j - 1] + 1;
					else
						temp = 1;
					if (temp > max)
						max =  temp;
				}
				dp[i][j] = max;
			}

		if (dp[len1 - 1][len2 - 1] >= len1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
