/*
题目描述：
Output the k-th prime number.
输入：
k≤10000
输出：
The k-th prime number.
样例输入：
3
7
样例输出：
5
17

*/

#include <iostream>
using namespace std;

int prime[10005];
int init()
{
	prime[0] = 2;

	int i, j;
	int cnt = 1;
	for(i = 3;cnt < 10001;i++)
	{
		for(j = 0;j < cnt && prime[j] * prime[j] <= i;j++)
			if (i % prime[j] ==0)
				break;
		if (j >= cnt || prime[j] * prime[j] > i)
			prime[cnt++] = i;
	}
}

int main()
{
	init();
	int n;
	while(cin >> n)
		cout << prime[n - 1] << endl;
	return 0;
}
