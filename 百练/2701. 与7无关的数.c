/*
描述
一个正整数,如果它能被7整除,或者它的十进制表示法中某一位上的数字为7,则称其为与7相关的数.现求所有小于等于n(n < 100)的与7无关的正整数的平方和.

输入
输入为一行,正整数n(n < 100)
输出
输出一行，包含一个整数，即小于等于n的所有与7无关的正整数的平方和。
样例输入
21
样例输出
2336
*/


#include <stdio.h>
#include <string.h>

int main()
{
	int i, j;
	int res;
	int arr[105];
	int n;

	memset(arr, 0, sizeof(arr));
	for (i = 0;i < 10;i++)
	{
		if (i == 7)
			continue;
		for (j = 0;j < 10;j++)
		{
			if (j == 7)
				continue;
			if ((i * 10 + j) % 7 ==0)
				continue;
			arr[i * 10 + j] = 1;
		}
	}

	while(scanf("%d", &n) != EOF)
	{
		res = 0;
		for(i = 0;i <= n;i++)
			if (arr[i])
				res += i * i;
		printf("%d\n", res);
	}
}
