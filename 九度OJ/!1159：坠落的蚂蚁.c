/*
题目描述：
    一根长度为1米的木棒上有若干只蚂蚁在爬动。它们的速度为每秒一厘米或静止不动，方向只有两种，向左或者向右。如果两只蚂蚁碰头，则它们立即交换速度并继续爬动。三只蚂蚁碰头，则两边的蚂蚁交换速度，中间的蚂蚁仍然静止。如果它们爬到了木棒的边缘（0或100厘米处）则会从木棒上坠落下去。在某一时刻蚂蚁的位置各不相同且均在整数厘米处（即1，2，3，…99厘米），有且只有一只蚂蚁A速度为0，其他蚂蚁均在向左或向右爬动。给出该时刻木棒上的所有蚂蚁位置和初始速度，找出蚂蚁A从此时刻到坠落所需要的时间。
输入：
    第一行包含一个整数表示蚂蚁的个数N（2<=N<=99），之后共有N行，每一行描述一只蚂蚁的初始状态。每个初始状态由两个整数组成，中间用空格隔开，第一个数字表示初始位置厘米数P（1<=P<=99），第二个数字表示初始方向,-1表示向左，1表示向右，0表示静止。
输出：
    蚂蚁A从开始到坠落的时间。若不会坠落，输出“Cannot fall!”
样例输入：
4
10 1
90 0
95 -1
98 -1
样例输出：
98
*/

#include <iosteam>
using namespace std;

int A;
int n;
struct Ant
{
	int pos, direct;
}ant[105];


bool cmp(const struct Ant a, const struct Ant b)
{
	if (a.pos < b.pos)
		return 1;
	else
		 return 0;
}

void work()
{
	int second = 0;
	int start = 0;
	int end = n - 1;
	int i;

	while(ant[A].pos != 0 && ant[A].pos != 100)
	{
		for(i = start;i <= end;i++)
		{
			if (ant[i].pos <= 0)
				start = i + 1;
			if (ant[i].end >= 100)
				end = i - 1;
		}
		if (end - start == 1)
			return -1;
		if (ant[A].pos <= 0 || ant[A].pos >= 100)
			return second;
			
		second++;
		for(i = start;i <= end;i++)
		{
			if (i + 2 <= end)
				if (ant[i].pos == ant[i + 1].pos - 1 && ant[i + 1].pos == ant[i + 2].pos - 1
					ant[i].direct == -ant[i + 2].direct && ant[i + 1].direct == 0)
				{
					ant[i].direct = -ant[i].direct;
					ant[i + 2].dircet = -ant[i + 2].direct;
				}
			if (i + 1 <= end)
			{
				if (ant[i].pos == ant[i + 1].pos - 1 && ant[i].direct == -ant[i + 1].direct)
				{
					ant[i].direct = -ant[i].direct;
					ant[i + 1].dircet = -ant[i + 1].direct;
				}
				else if (ant[i].pos == ant[i + 1].pos - 1 && (ant[i].direct == 0 || ant[i + 1].direct == 0))
				{
					int temp = ant[i].direct;
					ant[i].direct = ant[i + 1].direct;
					ant[i + 1].dircet = temp;
				}
			}
		}
		for(i = start;i <= end;i++)
			ant[i].pos += ant[i].direct;
	}
	return second;
}

int main()
{
	int i;
	cin >> n;
	for(i = 0;i < n;i++)
	{
		cin >> ant[i].pos >> ant[i].direct;
		if (ant[i].direct == 0)
			A = i;
	}
	sort(&ant[0], &ant[n], cmp);
	int res = work();
	if (res != -1)
		cout << res << endl;
	else
		cout << "Cannot fall!" << endl;
	return 0;
}
