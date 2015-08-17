/*
题目描述：
读入N名学生的成绩，将获得某一给定分数的学生人数输出。
输入：
测试输入包含若干测试用例，每个测试用例的格式为


第1行：N
第2行：N名学生的成绩，相邻两数字用一个空格间隔。
第3行：给定分数

当读到N=0时输入结束。其中N不超过1000，成绩分数为（包含）0到100之间的一个整数。
输出：
对每个测试用例，将获得给定分数的学生人数输出。
样例输入：
3
80 60 90
60
2
85 66
0
5
60 75 90 55 75
75
0
样例输出：
1
0
2

*/

#include <iostream>
using namespace std;

int main()
{
	int n;
	int i;
	int arr[10000];
	int a;

	while(cin >> n, n)
	{
		for(i = 0;i < n;i++)
			cin >> arr[i];
		cin >> a;
		int res = 0;
		for(i = 0;i < n;i++)
			if (a == arr[i])
				res++;
		cout << res << endl;
	}
	return 0;
}
