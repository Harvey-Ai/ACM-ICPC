/*
题目描述
　　在河上有一座独木桥，一只青蛙想沿着独木桥从河的一侧跳到另一侧。在桥上有一些石子，青蛙很讨厌踩在这些石子上。由于桥的长度和青蛙一次跳过的距离都是正整数，我们可以把独木桥上青蛙可能到达的点看成数轴上的一串整点：0，1，……，L（其中L是桥的长度）。坐标为0的点表示桥的起点，坐标为L的点表示桥的终点。青蛙从桥的起点开始，不停的向终点方向跳跃。一次跳跃的距离是S到T之间的任意正整数（包括S,T）。当青蛙跳到或跳过坐标为L的点时，就算青蛙已经跳出了独木桥。
　　题目给出独木桥的长度L，青蛙跳跃的距离范围S,T，桥上石子的位置。你的任务是确定青蛙要想过河，最少需要踩到的石子数。
　　对于30%的数据，L <= 10000；
　　对于全部的数据，L <= 10^9。
输入格式
　　输入的第一行有一个正整数L（1 <= L <= 10^9），表示独木桥的长度。第二行有三个正整数S，T，M，分别表示青蛙一次跳跃的最小距离，最大距离，及桥上石子的个数，其中1 <= S <= T <= 10，1 <= M <= 100。第三行有M个不同的正整数分别表示这M个石子在数轴上的位置（数据保证桥的起点和终点处没有石子）。所有相邻的整数之间用一个空格隔开。
输出格式
　　输出只包括一个整数，表示青蛙过河最少需要踩到的石子数。

样例输入
10
2 3 5
2 3 5 6 7

样例输出
2
*/


#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int l;
	int s, t, m;
	int arr[105];

	cin >> l;
	cin >> s >> t >> m;
	for(int i = 0;i < m;i++)
		cin >> arr[i];
	sort(arr, arr + m);

    if (s == t)
    {
        int res = 0;
        for(int i = 0;i < m;i++)
            if (arr[i] % s == 0)
                res++;
        cout << res << endl;
        return 0;
    }
	int cirLen = 101;
	int dp[cirLen];
	int pos = 0;
	int index = 0;

	for(int i = 0;i < cirLen;i++)
		dp[i] = -1;
	dp[0] = 0;
	for(int i = 0;i < m;i++)
	{
		int preIndex = index;
		index = (index + 1) % cirLen;
		for(int j = pos + 1;j < arr[i] && index != preIndex;j++, index = (index + 1) % cirLen)
		{
			int minV = -1;
			for(int k = (index - t + cirLen) % cirLen;k != (index - s + 1 + cirLen) % cirLen;k = (k + 1) % cirLen)
				if (dp[k] != -1 && (dp[k] < minV || minV == -1))
					minV = dp[k];
			dp[index] = minV;
		}

		int minV = -1;
		for(int k = (index - t + cirLen) % cirLen;k != (index - s + 1 + cirLen) % cirLen;k = (k + 1) % cirLen)
			if (dp[k] != -1 && (dp[k] < minV || minV == -1))
				minV = dp[k];
		pos = arr[i];
		if (minV != -1)
			dp[index] = minV + 1;
		else
			dp[index] = -1;
	}

	int preIndex = index;
	index = (index + 1) % cirLen;
	for(int j = pos + 1;j <= l && index != preIndex;j++, index = (index + 1) % cirLen)
	{
		int minV = -1;
		for(int k = (index - t + cirLen) % cirLen;k != (index - s + 1 + cirLen) % cirLen;k = (k + 1) % cirLen)
		{
			if (dp[k] != -1 && (dp[k] < minV || minV == -1))
				minV = dp[k];
		}
		dp[index] = minV;
	}

	cout << dp[(index - 1 + cirLen) % cirLen] << endl;
	return 0;
}
