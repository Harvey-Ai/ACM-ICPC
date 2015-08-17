/*
题目描述:
百度应用平台上有很多有趣的应用,每个应用都由一个开发者开发,每个开发者可能开发一个或多个应用。百度的工程师们想把应用尽可能好的推荐给用户。研究发现,同一个开发者开发的程序的图标有很大的相似性。如果把同一个开发者开发的应用放在一起,用户很快就会厌倦相似的图标,如果把这些图标穿插摆放效果就会好很多。现在工程师想给用户推荐来自 m 个开发者的 n 个应用,在推荐的时候这些应用的图标将排成整齐的一行展示给用户,相邻两个图标之间的距离正好是 1,工程 师们想让这些图标尽可能的穿插摆放。为了衡量穿插摆放的效果,给每个图标定义一个“分离度”,分离度的值是指当前图标和它左边最近的来自同一个开发者的图 标之间的距离。如果一个图标左边没有来自同一个开发者的图标,则分离度为 0。所有图标穿插摆放效果的值定义为所有图标的分离度之和。已知每个开发者开发的应用个数,请帮助百度的工程师找到图标穿插摆放效果的最大值。
输入描述
输入的第一行包含两个整数 n 和 m,用一个空格分隔,分别表示应用的个数和开发者的个数。
第二行包含 m 个正整数,相邻两个数之间用一个空格分隔,表示每个开发者开发的应用个数,这些整数之和必然等于 n。
输出描述
输出一个整数,表示图标穿插摆放效果的最大值。
样例输入:
8 3
3 3 2
样例输出
15
提示
对于 20%的数据,n≤ 10;
对于 40%的数据,n≤ 100。
对于 100%的数据,1≤ m ≤ n ≤ 100,000
*/


#include <iostream>
#include <algorithm>
using namespace std;

struct app
{
	int num, p;
};
struct app ap[100005];
int near[100005];

bool cmp(const app a, const app b)
{
	return a.num < b.num ? 0 : 1;
}

int main()
{
	int i;
	int m, n;
	int flag, pos;
	long long res;
	scanf("%d %d", &n, &m);
	for(i = 0;i < m;i++)
	{
		scanf("%d", &ap[i].num);
		ap[i].p = i;
	}

	sort(&ap[0], &ap[m], cmp);

	for(i = 0;i < m;i++)
		near[i] = -1;

	pos = 0;
	flag = 1;
	res = 0;
	while(flag)
	{
		flag = 0;
		for(i = 0;i < m;i++)
			if (ap[i].num > 0)
			{
				flag = 1;
				if (near[ap[i].p] != -1)
				{
					res += pos - near[ap[i].p];
				//	printf("%lld\n", res);
				}
				near[ap[i].p] = pos;
				ap[i].num--;
				pos++;
			}
	}
	printf("%lldccc\n", res);

	return 0;
}
