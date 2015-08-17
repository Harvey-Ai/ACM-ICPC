/*
题目描述：
You are given a sequence of integer numbers. Zero-complexity transposition of the sequence is the reverse of this sequence. Your task is to write a program that prints zero-complexity transposition of the given sequence.
输入：
For each case, the first line of the input file contains one integer n-length of the sequence (0 ＜ n ≤ 10 000). The second line contains n integers numbers-a1, a2, …, an (-1 000 000 000 000 000 ≤ ai ≤ 1 000 000 000 000 000).
输出：
For each case, on the first line of the output file print the sequence in the reverse order.
样例输入：
5
-3 4 6 -8 9
样例输出：
9 -8 6 4 -3
*/


#include <iostream>
using namespace std;

int main()
{
	int n;
	long long arr[100005];
	int i;

	while(cin >> n)
	{
		for(i = 0;i < n;i++)
			cin >> arr[i];

		cout << arr[n - 1];
		for(i = n - 2;i >= 0;i--)
			cout << " " << arr[i];
		cout << endl;
	}
	return 0;
}
