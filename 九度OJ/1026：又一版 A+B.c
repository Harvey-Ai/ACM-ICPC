/*
题目描述：
输入两个不超过整型定义的非负10进制整数A和B(<=231-1)，输出A+B的m (1 < m <10)进制数。
输入：
输入格式：测试输入包含若干测试用例。每个测试用例占一行，给出m和A，B的值。
当m为0时输入结束。
输出：
输出格式：每个测试用例的输出占一行，输出A+B的m进制数。
样例输入：
8 1300 48
2 1 7
0
样例输出：
2504
1000
*/


#include <iostream>
using namespace std;

int main()
{
	int jin;
	unsigned int a, b;
	int arr[1000];

	while(cin >> jin, jin)
	{
		cin >> a >> b;
		unsigned int sum = a + b;
		int i = 0;
		if (sum == 0)
		{
			cout << 0 << endl;
			continue;
		}
		while(sum)
		{
			arr[i++] = sum % jin;
			sum /= jin;
		}
		for(i--;i >= 0;i--)
			cout << arr[i];
		cout << endl;
	}
	return 0;
}
