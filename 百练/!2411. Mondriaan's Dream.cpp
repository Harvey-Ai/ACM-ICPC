/*
描述
Squares and rectangles fascinated the famous Dutch painter Piet Mondriaan. One night, after producing the drawings in his 'toilet series' (where he had to use his toilet paper to draw on, for all of his paper was filled with squares and rectangles), he dreamt of filling a large rectangle with small rectangles of width 2 and height 1 in varying ways. 


Expert as he was in this material, he saw at a glance that he'll need a computer to calculate the number of ways to fill the large rectangle whose dimensions were integer values, as well. Help him, so that his dream won't turn into a nightmare!
输入
The input contains several test cases. Each test case is made up of two integer numbers: the height h and the width w of the large rectangle. Input is terminated by h=w=0. Otherwise, 1<=h,w<=11.
输出
For each test case, output the number of different ways the given rectangle can be filled with small rectangles of size 2 times 1. Assume the given large rectangle is oriented, i.e. count symmetrical tilings multiple times.
样例输入
1 2
1 3
1 4
2 2
2 3
2 4
2 11
4 11
0 0
样例输出
1
0
1
2
3
5
144
51205
*/

#include <iostream>
#include <cmath>
using namespace std;


int work(int m, int n)
{
	int dp[2][2048];
        int i, j;
	for(i = 0;i < 2048;i++)
		dp[0][i] = dp[1][i] = 0;
	dp[0][2047] = 1;
	
	int stateNum = pow(2, n);
	int now = 1, before = 0;
	for(i = 0;i < m;i++)
	{
		int temp = now;
		now = before;
		before = temp;

		for(j = 0;j < stateNum;j++)
		{
			beforeState = ~j;
			dp[now][j] = dp[before][beforeState];
			if (j == 2047)
			{
				if (n % 2 == 0)
					dp[now][j] += dp[before][0];
			}
		}

	}
	
}

int main()
{
	int m, n;
	while(cin >> m >> n, m != 0 && n != 0)
		cout << work(m, n) << endl;
	return 0;
}
