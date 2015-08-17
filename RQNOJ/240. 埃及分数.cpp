/*
题目描述
在古埃及，人们使用单位分数的和（形如 1/a 的，a 是正整数）表示一切有理数。
如：2/3 = 1/2 + 1/6，但不允许 2/3 = 1/3 + 1/3，因为加数中有相同的。
对于一个分数 a/b ，表示方法有很多种，但是哪种最好呢？
首先，加数少的比加数多的好，其次，加数个数相同的，最小的分数越大越好。
如：
19/45 = 1/3 + 1/12 + 1/180
19/45 = 1/3 + 1/15 + 1/45
19/45 = 1/3 + 1/18 + 1/30
19/45 = 1/4 + 1/6 + 1/180
19/45 = 1/5 + 1/6 + 1/18
最好的是最后一种，因为 1/18 比 1/180、1/45、1/30、1/180 都要大。
给出a、b (0 < a < b < 1000)，试编程计算最好的表达方式。
输入格式
输入只有一行：a、b，表示需要表示的分数 a/b (0 < a < b < 1000)。
输出格式
一行，依次给出最好的表达方式中各个单位分数的分母（保证都在 32 位整型范围内）。


样例输入
19 45
样例输出
5 6 18

*/


#include <iostream>
using namespace std;

int found;
long long tempRes[25];
long long res[25];
int testDep;

long long gcd(long long a, long long b)
{
    long long t;
    while (b > 0)
    {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

void dfs(long long a, long long b, int depth)
{
	if (depth == testDep)
		return;

	long long common = gcd(b, a);
	a /= common;
	b /= common;

	long long low, high;
	low = b / a;
	if (depth > 0 && low <= tempRes[0])
		low = tempRes[0] + 1;
	high = (b * (testDep - depth) + a - 1) / a;

	if (depth == testDep - 1)
	{
		if (a == 1 && (depth == 0 || b > tempRes[depth - 1]))
		{
			tempRes[depth] = b;
			if (!found || (found  && b < res[depth]))
			{
				for(int j = 0;j < testDep;j++)
					res[j] = tempRes[j];
				found = 1;
			}
		}
	}
	else
	{
		for(long long i = low;i <= high;i++)
		{
			long long zi = a * i - b;
			long long mu = b * i;

			if (zi > 0)
			{
				tempRes[depth] = i;
				dfs(zi, mu, depth + 1);
			}
		}
	}
}

int main()
{
	long long a, b;
	cin >> a >> b;

	found = 0;
	testDep = 0;
	while(!found)
	{
		testDep++;
		dfs(a, b, 0);
	}

	for(int i = 0;i < testDep;i++)
		cout << res[i] << " ";
	cout << endl;
	return 0;
}
