/*
题目描述：
    用小于等于n元去买100只鸡，大鸡5元/只，小鸡3元/只,还有1/3元每只的一种小鸡，分别记为x只,y只,z只。编程求解x,y,z所有可能解。
输入：
    测试数据有多组，输入n。
输出：
    对于每组输入,请输出x,y,z所有可行解，按照x，y，z依次增大的顺序输出。
样例输入：
40
样例输出：
x=0,y=0,z=100
x=0,y=1,z=99
x=0,y=2,z=98
x=1,y=0,z=99

*/

#include <iostream>
using namespace std;

int main()
{
	int n, i, j;
	while(cin >> n)
	{
		for(i = 0;i <= 100;i++)
			for(j = 0;j <= 100;j++)
				if (5 * i + 3 * j + (100 - i - j + 2) / 3 <= n)
					cout << "x=" << i << ",y=" << j << ",z=" << 100 - i - j << endl;
	}
	return 0;
}
