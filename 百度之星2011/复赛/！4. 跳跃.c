/*
度度熊最近迷上了一个电脑游戏,游戏中有这样一个场景:在一片高低错落的山地中,度度熊控制的人物从左向右做若干次跳跃,由起点一直跳到终点。经过度度熊最近对这个游戏的研究,他发现游戏中能站立的地点只有 n + 1 个,可以标号为 0, 1, ...,n。其中 0 为起点,n 为终点。在跳跃时只能从左向右跳跃,从点 i 跳跃到点 j 的水平距离为 j – i。点 i 有高度值 hi,对于从点 i 到点 j 的直接跳跃,其水平距离不能超过点 i 的高度,而且在点 i 到点 j 之间不能出现高度值同时大于等于 hi 和 hj 的点(例如 h1=3, h2=4, h3=2,则不能从点 1 直接跳到点 3,因为点 2 的高度值 h2 既大于等于 h1,又大于等于 h3)。如果 hi > hj,则花费的体力值为 0,否则花费的体力值为 hj – hi。由于体力值在游戏中很有用,度度熊希望尽量在这个场景节省体力。他已经知道了每个点的高度值,请你帮助度度熊计算一下最少需要多少体力。
输入描述
输入包含一组数据。
第一行包含一个正整数 n,表示场景中起点与终点的水平距离。
第二行包含 n + 1 个正整数,其中第 i + 1 个整数为 hi,表示点 i 的高度值。
输出描述
输出一行,包含一个正整数,表示至少需要耗费的体力值。
样例输入
5
1 3 4 2 3 1
样例输出
3
提示
对于 30%的数据,1 ≤ n ≤ 3000。
对于 100%的数据,1 ≤ n ≤ 100,000,1 ≤ hi ≤ 109。
*/


#include <iostream>
using namespace std;

int arr[100006];
int main()
{
	int n;
	int i;
	int pos;
	int len;
	int max;
	int max_id;
	long long res;
	scanf("%d", &n);

	for(i = 0;i <= n;i++)
		scanf("%d", &arr[i]);

	pos = 0;
	res = 0;
	while(pos < n)
	{
	//	printf("%d\n", pos);
		len = arr[pos];
		max = -1;
		max_id = -1;

		for(i = 1;i <= len && pos + i <= n;i++)
			if (arr[pos + i] >= max)
			{
				max = arr[pos + i];
				max_id = pos + i;
			}

		if (arr[pos] < arr[max_id])
			res += arr[max_id] - arr[pos];
		pos = max_id;
	}

	printf("%lld\n", res);
	return 0;

}
