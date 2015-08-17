/*
描述
给定一组点(x,y)，求距离最远的两个点之间的距离。
输入
第一行是点数n（n大于等于2）
接着每一行代表一个点，由两个浮点数x y组成。
输出
输出一行是最远两点之间的距离。
使用printf("%.4f\n", dis)输出距离值并精确到小数点后4位。
样例输入
6
34.0 23.0
28.1 21.6
14.7 17.1
17.0 27.2
34.7 67.1
29.3 65.1
样例输出
53.8516
*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define dis(x, y) ((x) * (x) + (y) * (y))

int main()
{
	int n;
	double p[10000][2];
	double max;
	int i, j;

	cout.precision(4);
	cout.setf(ios::fixed);
	cin >> n;
	for(i = 0;i < n;i++)
		cin >> p[i][0] >> p[i][1];

	for(i = 0;i < n;i++)
		for(j = i + 1;j < n;j++)
			if (dis(p[i][0] - p[j][0], p[i][1] - p[j][1]) > max)
				max = dis(p[i][0] - p[j][0], p[i][1] - p[j][1]);

	cout << sqrt(max) << endl;
	return 0;
}
