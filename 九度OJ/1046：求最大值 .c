/*
题目描述：
输入10个数，要求输出其中的最大值。
输入：
测试数据有多组，每组10个数。
输出：
对于每组输入,请输出其最大值（有回车）。
样例输入：
10 22 23 152 65 79 85 96 32 1
样例输出：
max=152
*/

#include <iostream>
using namespace std;

int main()
{
	int arr[100];
	int i, max;
	while(cin >> arr[0])
	{
		for(i = 1;i < 10;i++)
			cin >> arr[i];

		max = arr[0];
		for(i = 0;i < 10;i++)
			if (max < arr[i])
				max = arr[i];

		cout << "max=" << max << endl;
	}
	return 0;
}
