#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	int ans[100];
	int ansNum = 0;

	for(int i = 1;i <= 9 * 9;i++)
	{
		long long x = b;
		for(int j = 0;j < a;j++)
			x *= i;
		x += c;
		if (x < 1000000000)
		{
			int xx = (int)x;
			int digitSum = 0;
			while(xx)
			{
				digitSum += xx % 10;
				xx /= 10;
			}
			if (digitSum == i)
				ans[ansNum++] = x;
		}
	}
	cout << ansNum << endl;
	for(int i = 0;i < ansNum;i++)
		cout << ans[i] << " ";
	return 0;
}
