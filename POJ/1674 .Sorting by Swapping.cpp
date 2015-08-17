/*
Description

Given a permutation of numbers from 1 to n, we can always get the sequence 1, 2, 3, ..., n by swapping pairs of numbers. For example, if the initial sequence is 2, 3, 5, 4, 1, we can sort them in the following way: 

2 3 5 4 1 
1 3 5 4 2 
1 3 2 4 5 
1 2 3 4 5 

Here three swaps have been used. The problem is, given a specific permutation, how many swaps we needs to take at least. 
Input

The first line contains a single integer t (1 <= t <= 20) that indicates the number of test cases. Then follow the t cases. Each case contains two lines. The first line contains the integer n (1 <= n <= 10000), and the second line gives the initial permutation.
Output

For each test case, the output will be only one integer, which is the least number of swaps needed to get the sequence 1, 2, 3, ..., n from the initial permutation.
Sample Input

2
3
1 2 3
5
2 3 5 4 1
Sample Output

0
3
*/


#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int arr[10005];
int main()
{
	int ncase;

	cin >> ncase;
	while(ncase--)
	{
		int n;
		cin >> n;
		for(int i = 0;i < n;i++)
			cin >> arr[i];
		
		int res = 0;
		for(int i = 0;i < n;i++)
			if (arr[i])
			{
				int pos = i;
				while(arr[pos])
				{
                    int nextPos = arr[pos] - 1;
					arr[pos] = 0;
                    pos = nextPos;
                    res++;
				}
				res--;
			}

		cout << res << endl;
		
	}

	return 0;
}
