/*
描述
打印出所有得“水仙花数”，所谓“水仙花数”是指一个3位数，其各位数字的立方和等于该数本身，例如，152是水仙花数，因为153＝1×1×1＋5×5×5＋3×3×3。
输入
无输入。
输出
输出所有水仙花数，每行输出一个水仙花数。
*/


#include <iostream>
using namespace std;

int main()
{
	int i;
	int a, b, c;
	for(i = 100;i < 1000;i++)
	{
		int a = i % 10;
		int b = (i / 10) % 10;
		int c = (i / 100) % 10;

		if (a * a * a + b * b * b + c * c * c == i)
			cout << i << endl;
	}
	return 0;
}
