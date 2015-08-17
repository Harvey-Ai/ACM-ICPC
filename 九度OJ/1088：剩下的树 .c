/*
题目描述：
    有一个长度为整数L(1<=L<=10000)的马路，可以想象成数轴上长度为L的一个线段，起点是坐标原点，在每个整数坐标点有一棵树，即在0,1,2，...，L共L+1个位置上有L+1棵树。
    现在要移走一些树，移走的树的区间用一对数字表示，如 100 200表示移走从100到200之间（包括端点）所有的树。
    可能有M(1<=M<=100)个区间，区间之间可能有重叠。现在要求移走所有区间的树之后剩下的树的个数。
输入：
    两个整数L(1<=L<=10000)和M(1<=M<=100)。
    接下来有M组整数，每组有一对数字。
输出：
    可能有多组输入数据，对于每组输入数据，输出一个数，表示移走所有区间的树之后剩下的树的个数。
样例输入：
500 3
100 200
150 300
470 471
样例输出：
298

*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int flag[1000006];

int main()
{
	int l, m;
	int i, j;
	int b, e;

	while(cin >> l >> m)
	{
		memset(flag, 0, sizeof(flag));
		for(i = 0;i < m;i++)
		{
			cin >> b >> e;
			for(j = b;j <= e;j++)
				flag[j] = 1;
		}
		int res = 0;
		for(i = 0;i <= l;i++)
			if (flag[i] == 0)
				res++;
		cout << res << endl;
	}
	return 0;
}
