/*
题目描述：
    Given an increasing sequence S of N integers, the median is the number at the middle position. For example, the median of S1={11, 12, 13, 14} is 12, and the median of S2={9, 10, 15, 16, 17} is 15. The median of two sequences is defined to be the median of the non-decreasing sequence which contains all the elements of both sequences. For example, the median of S1 and S2 is 13.
    Given two increasing sequences of integers, you are asked to find their median.
输入：
    Each input file may contain more than one test case.
    Each case occupies 2 lines, each gives the information of a sequence. For each sequence, the first positive integer N (≤1000000) is the size of that sequence. Then N integers follow, separated by a space.
    It is guaranteed that all the integers are in the range of long int.
输出：
    For each test case you should output the median of the two given sequences in a line.
样例输入：
4 11 12 13 14
5 9 10 15 16 17
样例输出：
13
*/


#include <iostream>
using namespace std;


int arr1[1000005];
int arr2[1000005];
int main()
{
	int n1, n2;
	int i;

	while(cin >> n1)
	{
		for(i = 0;i < n1;i++)
			cin >> arr1[i];
		cin >> n2;
		for(i = 0;i < n2;i++)
			cin >> arr2[i];

		int pos1, pos2, index;
		int res;
		pos1 = pos2 = -1;
		index = -1;
		int flag;

		while(index != (n1 + n2 - 1) / 2)
		{
			if (pos1 + 1 < n1 && pos2 + 1 < n2)
			{
				if (arr1[pos1 + 1] < arr2[pos2 + 1])
				{
					pos1++;	
					res = arr1[pos1];
				}
				else
				{
					pos2++;
					res = arr2[pos2];
				}
			}
			else if (pos1 + 1 < n1)
			{
				pos1++;
				res = arr1[pos1];
			}
			else
			{
				pos2++;
				res = arr2[pos2];
			}
			index++;
		}
		cout << res << endl;
	}
	return 0;
}
