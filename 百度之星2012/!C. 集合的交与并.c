/*
题目描述:
对于一个闭区间集合{A1,A2......AK}(K>1,Ai≠Aj{i≠j}),我们定义其权值
 	W=|A1∪A2∪„„∪AK|*|A1∩A2∩„„AK|
	其中|X|表示 X 区间的长度;如果 X 为空集|X|=0。
当然,如果这些闭区间没有交集则权值为 0。给定 N 个各不相同的闭区间,请你从中找出若干个(至少 2 个)区间使其权值最大。
输入数据:
第一行一个整数 N (2 <= N <= 10 5 )
接下来 N 行每行两个整数 l r(1<=l<=r<=10 6 ),表示闭区间的两个端点。
输出数据:
最大权值
例如,对于:
4
1 6
4 8
2 7
3 5
其输出结果是:
24
*/


#include <iostream>
#include <algorithm>
using namespace std;

struct tt
{
	int a, b;
}area[100005];

bool cmp(const struct tt a, const struct tt b)
{
	if (a.a < b.a)
		return 1;
	else if (a.a > b.a)
		return 0;
	else if (a.b - a.a > b.b - b.a)
		return 1;
}

int main()
{
	int n;
	int i, j;

	scanf("%d", &n);
	for(i = 0;i < n;i++)
		scanf("%d %d", &area[i].a, &area[i].b);
	sort(&area[0], &area[n], cmp);

//	cout << area[0].a << endl;

	long long res = 0;
	for(i = 0;i < n;i++)
		for(j = i + 1;j < n;j++)
		{
		//	printf("%d %d %d %d\n", area[j].a, area[i].b, (area[j].b - area[i].a), (area[j].a - area[i].b));
			if (area[j].a > area[i].b)
				break;
			else if ((long long)(area[j].b - area[i].a) * (long long)(area[i].b - area[j].a) > res)
			{
				//cout << area[j].b - area[i].a << area[i].b - area[j].a << endl;
				res = (long long)(area[j].b - area[i].a) * (long long)(area[i].b - area[j].a);
			}
		}
	cout << res << endl;
	return 0;
}
