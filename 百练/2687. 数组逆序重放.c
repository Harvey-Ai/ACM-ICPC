/*
描述
将一个数组中的值按逆序重新存放。例如，原来的顺序为8,6,5,4,1。要求改为1,4,5,6,8。
输入
输入为两行：第一行数组中元素的个数n（1<n<100)，第二行是n个整数，每两个整数之间用空格分隔。
输出
输出为一行：输出逆序后数组的整数，每两个整数之间用空格分隔。
样例输入
5
8 6 5 4 1
样例输出
1 4 5 6 8
*/

#include <iostream>
using namespace std;

int main()
{
	int n;
	int i;
	int arr[1000];
	cin >> n;
	for(i = 0;i < n;i++)
		cin >> arr[i];
	for(i = n - 1;i >= 0;i--)
		cout << arr[i] << " ";
	cout << endl;
}
