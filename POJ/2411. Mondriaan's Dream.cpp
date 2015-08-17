/*
Description

Squares and rectangles fascinated the famous Dutch painter Piet Mondriaan. One night, after producing the drawings in his 'toilet series' (where he had to use his toilet paper to draw on, for all of his paper was filled with squares and rectangles), he dreamt of filling a large rectangle with small rectangles of width 2 and height 1 in varying ways. 


Expert as he was in this material, he saw at a glance that he'll need a computer to calculate the number of ways to fill the large rectangle whose dimensions were integer values, as well. Help him, so that his dream won't turn into a nightmare!
Input

The input contains several test cases. Each test case is made up of two integer numbers: the height h and the width w of the large rectangle. Input is terminated by h=w=0. Otherwise, 1<=h,w<=11.
Output

For each test case, output the number of different ways the given rectangle can be filled with small rectangles of size 2 times 1. Assume the given large rectangle is oriented, i.e. count symmetrical tilings multiple times.
Sample Input

1 2
1 3
1 4
2 2
2 3
2 4
2 11
4 11
0 0
Sample Output

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
using namespace std;

int buffer[12];
bool confilict[1 << 11][1 << 11][11];

bool check(int st1, int st2, int n)
{
	int ok[11];
	for(int i = 0;i < 11;i++)
		ok[i] = 0;

	for(int i = 0;i < 11;i++)
	{
		if (st1 & buffer[i])
		{
			if (st2 & buffer[i])
				return false;
			else
			{
				if (i)
					ok[i] = ok[i - 1];
				else
					ok[i] = 1;
			}
		}
		else
		{
			if (st2 & buffer[i])
			{
				if (i)
					ok[i] = ok[i - 1];
				else
					ok[i] = 1;
			}
			else if (i > 0)
			{
				if ((st2 & buffer[i - 1]) == 0 && (st1 & buffer[i - 1]) == 0)
				{
					if (i == 1)
						ok[i] = 1;
					else if (i > 1 )
						ok[i] = ok[i - 2];
				}
			}
		}
	}
	return ok[n - 1];
}

int main()
{
	int m, n;

    buffer[0] = 1;
    for(int i = 1;i < 12;i++)
        buffer[i] = buffer[i - 1] * 2;
    
    for(int i = 1;i < 12;i++)
       for(int j = 0;j < (1 << i);j++)
          for(int k = 0;k < (1 << i);k++)
                confilict[j][k][i] = !check(j, k, i);
    
	while(cin >> m >> n, m && n)
	{
        if ((m * n) & 0x01)
        {
            cout << 0 << endl;
            continue;
        }
		int oldIndex = 0, newIndex = 1;

		long long  dp[2][1 << 11];
		for(int i = 0;i < buffer[n];i++)
			dp[0][i] = 0;
		dp[0][0] = 1;

		for(int i = 0;i < m;i++)
		{
			for(int j = 0;j < buffer[n];j++)
			{
				dp[newIndex][j] = 0;
				for(int k = 0;k < buffer[n];k++)
					if (!confilict[j][k][n])
						dp[newIndex][j] += dp[oldIndex][k];
			}
			oldIndex = 1 - oldIndex;
			newIndex = 1 - newIndex;
		}

		cout << dp[oldIndex][0] << endl;
	}

	return 0;
}
