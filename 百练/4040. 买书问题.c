/*
描述
某网上书店举行优惠促销，现有两种优惠策略。策略一是购书总额大于100元的可享受免费送货。策略二是如果购书数量大于3本，则购书总额享受95折优惠（不包括运费）。两种优惠策略不能同时享受，最多可选择其中一种优惠策略。运费为20元。小明想在这个网站上买书，请帮他选择最优的优惠策略。

输入
有多行，第一行是买书的种类N（0 <= N <= 100），接下来的N行每行输入一种书目的购买数量M和代价P(P不一定是整数)。当N为-1时结束输入
输出
针对每组数据，分析如何享受优惠策略，输出最少的购书支付金额
样例输入
2
2 60
3 50
-1
样例输出
270
*/

#include <iostream>
using namespace std;

int main()
{
	int arr[105];
	double price[105];
	int i, n;
	while(cin >> n, n != -1)
	{
		for(i = 0;i < n;i++)
			cin >> arr[i] >> price[i];

		int book = 0;
		double sum, sum1, sum2;
		sum = sum1 = sum2 = 0;
		for(i = 0;i < n;i++)
		{
			sum += price[i] * arr[i];
			book += arr[i];
		}
		sum1 = sum2 = sum;
		if (sum > 100) sum1 = sum - 20;
		if (book > 3) sum2 = sum * 0.95;

		if (sum1 > sum2)
			cout << sum2 + 20<< endl;
		else
			cout << sum1 + 20<< endl;
	}
	return 0;
}
