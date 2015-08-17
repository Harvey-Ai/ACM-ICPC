/*
描述
一个数如果恰好等于它的因子之和，这个数就成为“完数”。例如，6的因子为1、2、3，而6＝1＋2＋3，因此6是“完数”。编程序打印出1000之内（包括1000）所有的完数，并按如下格式输出其所有因子：

6 its factors are 1,2,3
输入
无输入
输出
输出1000以内所有的完数及其因子，每行一个完数。
*/


#include <iostream>
using namespace std;

int main()
{
	int i, j;
	int sum;
	int factor[1001];
	int facNum;

	for(i = 1;i < 1001;i++)
	{
		sum = 0;
		facNum = 0;
		for(j = 1;j < i;j++)
			if (i % j == 0)
			{
				factor[facNum] = j;
				facNum++;
				sum += j;
			}
		if (sum == i)
		{
			cout <<i <<" its factors are ";
			cout << factor[0];
			for(j = 1;j < facNum;j++)
				cout << "," << factor[j];
			cout << endl;
		}
	}
	return 0;
}
