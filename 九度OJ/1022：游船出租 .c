/*
题目描述：
    现有公园游船租赁处请你编写一个租船管理系统。当游客租船时，管理员输入船号并按下S键，系统开始计时；当游客还船时，管理员输入船号并按下E键，系统结束计时。船号为不超过100的正整数。当管理员将0作为船号输入时，表示一天租船工作结束，系统应输出当天的游客租船次数和平均租船时间。
    注意：由于线路偶尔会有故障，可能出现不完整的纪录，即只有租船没有还船，或者只有还船没有租船的纪录，系统应能自动忽略这种无效纪录。
输入：
    测试输入包含若干测试用例，每个测试用例为一整天的租船纪录，格式为：
    船号（1~100） 键值（S或E） 发生时间（小时:分钟）
    每一天的纪录保证按时间递增的顺序给出。当读到船号为-1时，全部输入结束，相应的结果不要输出。
输出：
    对每个测试用例输出1行，即当天的游客租船次数和平均租船时间（以分钟为单位的精确到个位的整数时间）。
样例输入：
1 S 08:10
2 S 08:35
1 E 10:00
2 E 13:16
0 S 17:00
0 S 17:00
3 E 08:10
1 S 08:20
2 S 09:00
1 E 09:20
0 E 17:00
-1
样例输出：
2 196
0 0
1 60
*/

#include <iostream>
#include <cstring>
using namespace std;

struct tt
{
	char begin[100], end[100];
};

int sub(char *s1, char *s2)
{
	int hour = (s2[0] - s1[0]) * 10 + s2[1] - s1[1];
	int minute = (s2[3] - s1[3]) * 10 + s2[4] - s1[4];
	return hour * 60 + minute;
}

int main()
{
	struct tt boat[1000];
	int flag[1000];
	int n;
	char c;
	char ttime[1000];
	int i;

	while(cin >> n, n != -1)
	{
		memset(flag, 0, sizeof(flag));
		cin >> c;
		cin >> ttime;
		if (c == 'S')
		{
			strcpy(boat[n].begin, ttime);
			flag[n] = 1;
		}
		else
		{
			strcpy(boat[n].end, ttime);
			flag[n] = 2;
		}
		if (n == 0)
		{
			cout << 0 << " " << 0 << endl;
			continue;
		}

		while(cin >> n)
		{
			cin >> c;
			cin >> ttime;
			if (c == 'S')
			{
				strcpy(boat[n].begin, ttime);
				flag[n] |= 1;
			}
			else
			{
				strcpy(boat[n].end, ttime);
				flag[n] |= 2;
			}
			if (!n)
				break;
		}

		int res1, res2;
		res1 = res2 = 0;
		for(i = 1;i < 101;i++)
			if (flag[i] == 3)
			{
				res1++;
				res2 += sub(boat[i].begin, boat[i].end);
			}
		if (res1 == 0)
			cout << "0 0" << endl;
		else
		{
			if ((res2 * 1.0 / res1) - (res2 / res1) >= 0.5)
				res2 = res2 / res1 + 1;
			else
				res2 = res2 / res1;
			cout << res1 << " " << res2 << endl;
		}
	}
	return 0;
}

