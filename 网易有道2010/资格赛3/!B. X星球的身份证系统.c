/*
描述
在X星球上的外星人和地球上一样拥有一个长N位的身份证号码，而X星球的人使用的是一种26进制身份证号码，用a~z表示
在X星球上正在举行一次幸运者抽奖活动，X星球的政府首脑制定了一个特殊的抽奖规则，凡是身份证号码符合对称性质（回文串）的人就能够成为本次活动的幸运者。
现在你知道X星球中最大的身份证号码，希望你能够计算出最多有多少人将成为本次活动的幸运者
输入
输入数据的第一行为一个正整数N，第二行为一个长度为N的字符串，表示已知的最大身份证号码. 其中 N <= 30
输出
本次活动的最大幸运人数模10000的结果.
样例输入
3 
bca
样例输出
28    

提示   样例说明:幸运者的身份证号为 a[a~z]a,bab,bbb  
*/


#include <stdio.h>

char str[100];
int main()
{
	int n;
	int i, temp;
	int flag;
	int a, b, min;
	long long res;
	scanf("%d", &n);
	scanf("%s", str);

	temp = 1;
	flag = 1;
	for(i = 0;i < n / 2;i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			a = str[i] - 'a' + 1;
		if (str[n - 1 - i] >= 'a' && str[n - 1 - i] <= 'z')
			b = str[n - 1 - i] - 'a' + 1;
		if (a > b)
			flag = 0;
		min = a  < b ? a : b;
		if (flag == 0)
			temp *= 26;
		else
			temp = (temp - 1) * min + 1;
		temp %= 10000;
	}
	if (n % 2)
	{
		if (flag == 1)
		{
			if (str[n / 2] >= 'a' && str[n / 2] <= 'z')
				a = str[n / 2] - 'a' + 1;
			temp *= a;
		}
		else
			temp *= 26;
	}
	res = temp % 10000;
	printf("%lld\n", res);
	return 0;
}
