// BEGIN CUT HERE

// END CUT HERE
#line 5 "Painting.cpp"
#include <string>
#include <vector>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MIN(A,B) ((A) < (B) ? (A) : (B))

using namespace std ;

int pic[60][60];
int f[60][60];

void paint(int a, int b, int d)
{
	int i, j;
	for(i = a;i < a + d;i++)
	{
		for(j = b;j < b + d;j++)
			if (pic[i][j] != 1)
				break;
		if (j < b + d)
			break;
	}
	if (i >= a + d)
	{
		for(i = a;i < a + d;i++)
			for(j = b;j < b + d;j++)
				f[i][j] = 1;
	}
}

class Painting { 
	public:
	int largestBrush(vector <string> picture) {
		int i, j, m, n, d;

		m = picture.size();
		n = picture[0].size();

		for(i = 0;i < m;i++)
			for(j = 0;j < n;j++)
				if (picture[i][j] == 'B')
					pic[i][j] = 1;
				else
					pic[i][j] = 0;


		for(d = 2;d <= MIN(m, n);d++)
		{
			memset(f, 0, sizeof(f));
			for(i = 0;i < m - d + 1;i++)
				for(j = 0;j < n - d + 1;j++)
					paint(i, j, d);

			for(i = 0;i < m;i++)
			{
				for(j = 0;j < n;j++)
					if (pic[i][j] != f[i][j])
						break;
				if (j < n)
					break;
			}
			if (i < m)
				break;
		}

		return d - 1;
	}
};
