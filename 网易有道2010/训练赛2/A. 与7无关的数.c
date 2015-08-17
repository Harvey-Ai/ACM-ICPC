/*
描述
一个正整数,如果它能被7整除,或者它的十进制表示法中某个位数上的数字为7,则称其为与7相关的数.现求所有小于等于n(n<100)的与7无关的正整数的平方和.
输入
输入为一行,正整数n,(n<100)
输出
输出小于等于n的与7无关的正整数的平方和
样例输入
21
样例输出
2336
*/


#include <stdio.h>
#include <string.h>
#define N 101

int arr[N];
int main()
{
	int n;
	int i, j;
	int res;
	memset(arr, 0, sizeof(arr));
	for(i = 1;i * 7 < N;i++)
		arr[i * 7] = 1;

	for(i = 0;i < 10;i++)
		for(j = 0;j < 10;j++)
			if (i == 7 || j == 7)
				arr[i * 10 + j] = 1;

	scanf("%d", &n);

	res = 0;
	for(i = 1;i <= n;i++)
		if (arr[i] == 0)
			res += i * i;

	printf("%d\n", res);
	return 0;
}	
