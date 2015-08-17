/*
描述
George took sticks of the same length and cut them randomly until all parts became at most 50 units long. Now he wants to return sticks to the original state, but he forgot how many sticks he had originally and how long they were originally. Please help him and design a program which computes the smallest possible original length of those sticks. All lengths expressed in units are integers greater than zero.
输入
The input contains blocks of 2 lines. The first line contains the number of sticks parts after cutting, there are at most 64 sticks. The second line contains the lengths of those parts separated by the space. The last line of the file contains zero.
输出
The output should contains the smallest possible length of original sticks, one per line.
样例输入
9
5 2 1 5 2 1 5 2 1
4
1 2 3 4
0
样例输出
6
5
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int arr[65];
int used[65];
int stickNum;
int n;

int check(int stick, int remind, int pos, int complish)
{
	if (complish == stickNum)
		return 1;
	int i;
	if (remind == 0)
	{
		complish++;
		if (complish == stickNum)
			return 1;
		remind = stick;
		for(i = 0;i < n;i++)
			if (!used[i])
				break;
		used[i] = 1;
		int res = check(stick, remind - arr[i], i + 1, complish);
		used[i] = 0;
		return res;
	}

	int pre = 0;
	for(i = pos;i < n;i++)
	{
		if (!used[i] && arr[i] != pre)
		{
			if ((arr[i - 1] != arr[i] || used[i - 1]) && remind - arr[i] >= 0)
			{
				used[i] = 1;
				if (check(stick, remind - arr[i], i + 1, complish))
					return 1;
				used[i] = 0;
				if (arr[i] == remind)
					return 0;
				pre = arr[i];
			}
		}
	}

	return 0;
}

bool cmp(int a, int b)
{
	return a < b ? 0 : 1;
}

int main()
{
	int i;
	int sum;
	int best;
	while(cin >> n, n)
	{
		for(i = 0;i < n;i++)
			cin >> arr[i];

		sum = 0;
		for(i = 0;i < n;i++)
			sum += arr[i];
		sort(&arr[0], &arr[n], cmp);
		best = sum;

		for(i = arr[0]; i * 2 <= sum;i++)
			if (sum % i == 0)
			{
				memset(used, 0, sizeof(used));
				stickNum = sum / i;
				if (check(i, i, 0, 0) == 1)
				{
					best = i;
					break;
				}
			}
		cout << best << endl;
	}
}


