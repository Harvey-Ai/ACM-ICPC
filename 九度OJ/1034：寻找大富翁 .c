/*
题目描述：
    浙江桐乡乌镇共有n个人,请找出该镇上的前m个大富翁.
输入：
    输入包含多组测试用例.
    每个用例首先包含2个整数n（0<n<=100000）和m(0<m<=10)，其中: n为镇上的人数，m为需要找出的大富翁数, 接下来一行输入镇上n个人的财富值.
    n和m同时为0时表示输入结束.
输出：
    请输出乌镇前m个大富翁的财产数，财产多的排前面，如果大富翁不足m个，则全部输出,每组输出占一行.
样例输入：
3 1
2 5 -1
5 3
1 2 3 4 5
0 0
样例输出：
5
5 4 3
*/


#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(const int &a, const int &b)
{
	return a > b ? 1 : 0;
}

int main()
{
	int n, m;
	int arr[100005];
	int i;
	while(cin >> n >> m, n || m)
	{
		for(i = 0;i < n;i++)
			cin >> arr[i];
		sort(&arr[0], &arr[n], cmp);
		if (m > n)
			m = n;
		int flag = 0;
		for(i = 0;i < m;i++)
		{
			if (flag)
				cout << " " << arr[i];
			else
			{
				cout << arr[i];
				flag = 1;
			}
		}
		cout << endl;
	}
	return 0;
}
