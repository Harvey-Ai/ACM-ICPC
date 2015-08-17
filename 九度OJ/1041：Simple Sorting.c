/*
题目描述：
You are given an unsorted array of integer numbers. Your task is to sort this array and kill possible duplicated elements occurring in it.
输入：
For each case, the first line of the input contains an integer number N representing the quantity of numbers in this array(1≤N≤1000). Next N lines contain N integer numbers(one number per each line) of the original array.
输出：
For each case ,outtput file should contain at most N numbers sorted in ascending order. Every number in the output file should occur only once.
样例输入：
6
8 8 7 3 7 7
样例输出：
3 7 8
*/


#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int i, n;
	int arr[100005];

	while(cin >> n)
	{
		for(i = 0;i < n;i++)
			cin >> arr[i];
		sort(&arr[0], &arr[n]);

		cout << arr[0];

		for(i = 1;i < n;i++)
			if (arr[i] != arr[i - 1])
				cout << " " << arr[i];
		cout << endl;
	}
	return 0;
}
