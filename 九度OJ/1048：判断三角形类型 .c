/*
题目描述：
给定三角形的三条边，a,b,c。判断该三角形类型。
输入：
测试数据有多组，每组输入三角形的三条边。
输出：
对于每组输入,输出直角三角形、锐角三角形、或是钝角三角形。
样例输入：
3 4 5
样例输出：
直角三角形
*/


#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int arr[4];
	while(cin >> arr[0] >> arr[1] >> arr[2])
	{
		sort(&arr[0], &arr[3]);

		if (arr[0] * arr[0] + arr[1] * arr[1] > arr[2] * arr[2])
			cout << "ÈñœÇÈýœÇÐÎ" << endl;
		else if (arr[0] * arr[0] + arr[1] * arr[1] == arr[2] * arr[2])
			cout << "Ö±œÇÈýœÇÐÎ" << endl;
		else
			cout << "¶ÛœÇÈýœÇÐÎ" << endl;
	}
	return 0;
}
