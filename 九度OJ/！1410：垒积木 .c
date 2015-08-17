/*
题目描述：
给你一些长方体的积木，问按以下规则能最多垒几个积木。
1 一个积木上面最多只能垒另一个积木。
2 在下面的积木的长宽高要大于或等于上面的积木的长宽高
输入：
输入有多组，每组输入第一行是一个整数n（1<=n<=1000000），接下来n行的每行包括三个整数l,w,h（1 <= w,l,h <= 100），表示积木的长宽高。
输出：
对于每组输入，输出按规则最多能垒几个积木。
样例输入：
3
5 2 1
4 2 1
3 3 1
3
1 5 1
5 1 1
2 2 2
样例输出：
2
1

*/

#include <iostream>
#include <algorithm>
using namespace std;

struct block
{
	int l, w, h;
};

struct block bb[100005];
int n;

bool cmp1(struct block a, struct block b )
{
	if (a.l > b.l)
		return 1;
	if (a.l < b.l)
		return 0;
	if (a.w > b.w)
		return 1;
	if (a.w < b.w)
		return 0;
	if (a.h > b.h)
		return 1;
	if (a.h < b.h)
		return 0;
	return 0;
}

bool cmp2(struct block a, struct block b )
{
	if (a.l > b.l)
		return 1;
	if (a.l < b.l)
		return 0;
	if (a.h > b.h)
		return 1;
	if (a.h < b.h)
		return 0;
	if (a.w > b.w)
		return 1;
	if (a.w < b.w)
		return 0;
	return 0;
}

bool cmp3(struct block a, struct block b )
{
	if (a.w > b.w)
		return 1;
	if (a.w < b.w)
		return 0;
	if (a.l > b.l)
		return 1;
	if (a.l < b.l)
		return 0;
	if (a.h > b.h)
		return 1;
	if (a.h < b.h)
		return 0;
	return 0;
}

bool cmp4(struct block a, struct block b )
{
	if (a.w > b.w)
		return 1;
	if (a.w < b.w)
		return 0;
	if (a.h > b.h)
		return 1;
	if (a.h < b.h)
		return 0;
	if (a.l > b.l)
		return 1;
	if (a.l < b.l)
		return 0;
	return 0;
}

bool cmp5(struct block a, struct block b )
{
	if (a.h > b.h)
		return 1;
	if (a.h < b.h)
		return 0;
	if (a.l > b.l)
		return 1;
	if (a.l < b.l)
		return 0;
	if (a.w > b.w)
		return 1;
	if (a.w < b.w)
		return 0;
	return 0;
}

bool cmp6(struct block a, struct block b )
{
	if (a.h > b.h)
		return 1;
	if (a.h < b.h)
		return 0;
	if (a.w > b.w)
		return 1;
	if (a.w < b.w)
		return 0;
	if (a.l > b.l)
		return 1;
	if (a.l < b.l)
		return 0;
	return 0;
}


int work()
{
	int l, w, h;
	l = bb[n - 1].l;
	w = bb[n - 1].w;
	h = bb[n - 1].h;

	int res = 1;
	for(int i = n - 2;i >= 0;i--)
		if (l <= bb[i].l && w <= bb[i].w && h <= bb[i].h)
		{
			l = bb[i].l;
			w = bb[i].w;
			h = bb[i].h;
			res ++;
		}
	return res;
}

int main()
{
	int i;
	int res;
	while(cin >> n)
	{
		for(i = 0;i < n;i++)
			cin >> bb[i].l >> bb[i].w >> bb[i].h;

		sort(&bb[0], &bb[n], cmp1);
		res = work();

		sort(&bb[0], &bb[n], cmp2);
		int temp = work();
		if (temp > res)
			res = temp;

		sort(&bb[0], &bb[n], cmp3);
		temp = work();
		if (temp > res)
			res = temp;

		sort(&bb[0], &bb[n], cmp4);
		temp = work();
		if (temp > res)
			res = temp;

		sort(&bb[0], &bb[n], cmp5);
		temp = work();
		if (temp > res)
			res = temp;

		sort(&bb[0], &bb[n], cmp6);
		temp = work();
		if (temp > res)
			res = temp;
		cout << res << endl;

	}
	return 0;
}
