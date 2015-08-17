/*
描述
6*9 = 42 对于十进制来说是错误的，但是对于13进制来说是正确的。即, 6(13) * 9(13) = 42(13)， 而 42(13) = 4 * 131 + 2 * 130 = 54(10)。 你的任务是写一段程序读入三个整数p、q和 r，然后确定一个进制 B(2<=B<=16) 使得 p * q = r. 如果 B有很多选择, 输出最小的一个。例如： p = 11, q = 11, r = 121. 则有 11(3) * 11(3) = 121(3) 因为 11(3) = 1 * 31 + 1 * 30 = 4(10) 和 121(3) = 1 * 32 + 2 * 31 + 1 * 30 = 16(10)。 对于进制 10,有 11(10) * 11(10) = 121(10)。这种情况下，应该输出 3。如果没有合适的进制，则输出 0。
输入
输入有 T组测试样例。 T在第一行给出。每一组测试样例占一行，包含三个整数p、q、r。 p、q、r的所有位都是数字，并且1 <= p、q、r <= 1,000,000。
输出
对于每个测试样例输出一行。该行包含一个整数：即使得p * q = r成立的最小的B。如果没有合适的B，则输出 0。
样例输入
3
6 9 42
11 11 121
2 2 2
样例输出
13
3
0
*/


#include <iostream>
using namespace std;

int check(int a)
{
	int big = 0;
	while(a)
	{
		if (a % 10 > big)
			big = a % 10;
		a /= 10;
	}
	return big + 1;
}

int checkMulti(int p, int q, int r, int zhi)
{
	int num1, num2, num3;
	int value;

	num1 = num2 = num3 = 0;
	value = 1;
	while(p)
	{
		num1 += (p % 10) * value;
		value *= zhi;
	//	cout << num1 << endl;
		p /= 10;
	}
	value = 1;
	while(q)
	{
		num2 += (q % 10) * value;
		value *= zhi;
		q /= 10;
	}
	value = 1;
	while(r)
	{
		num3 += (r % 10) * value;
		value *= zhi;
		r /= 10;
	}
//	cout <<zhi<< " " << num1 <<" " << num2 << " " << num3 << endl;
	if (num1 * num2 == num3)
		return 1;
	return 0;
}

int main()
{
	int n;
	int i;
	int p, q, r;

	cin >> n;
	while(n--)
	{
		cin >> p >> q >> r;

		int min = 2;

		int temp = check(p);
		min = min > temp ? min : temp;

		temp = check(q);
		min = min > temp ? min : temp;

		temp = check(r);
		min = min > temp ? min : temp;

	//	cout << p << q << r << endl;
		for(i = min;i <= 16;i++)
			if(checkMulti(p, q, r, i))
				break;

		if (i <= 16)
			cout << i << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}
