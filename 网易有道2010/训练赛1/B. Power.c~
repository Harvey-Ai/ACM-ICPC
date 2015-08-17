/*
描述
计算a的b次方对9907取模的值。
输入
第一行有一个正整数T，表示有T组测试数据。
接下来T行，每行是一组测试数据，包含两个整数a和b。
其中T<=10000, 0 <=a,b < 2^31。
输出
有T行，依次输出每组数据的结果。
样例输入
3
1 2
2 3
3 4
样例输出
1
8
81
*/


#include <stdio.h>
#include <string.h>
#define MOD 9907

long long yu[1000];
int main()
{
	long long a, b;
	int recNum;
	long long tempRes;
	int ncase;
	scanf("%d", &ncase);
	
	while(ncase--)
	{
		scanf("%lld %lld", &a, &b);
		if (b == 0)
		{
			printf("1\n");
			continue;
		}

		memset(yu, 0, sizeof(yu));
	
		yu[0] = 1;
		for(recNum = 1;recNum <= b;recNum++)
		{
			tempRes = (yu[recNum - 1] * a) % MOD;
			if (tempRes == 1)
				break;
			yu[recNum] = tempRes;
		}
		printf("%lld\n", yu[b % recNum]);
	}
	return 0;
}
