// BEGIN CUT HERE

// END CUT HERE
#line 5 "ColoredStrokes.cpp"
#include <string>
#include <vector>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std ;
class ColoredStrokes {
	int ans;
	int h, w;
	char g[55][55];
	char temp[55][55];
	public:
	int canR(int ii, int jj)
	{
		if ((g[ii][jj] == 'R' && temp[ii][jj] == '.' ) || g[ii][jj] =='G')
			return 1;
		return 0;
	}
	int canB(int ii, int jj)
	{
		if ((g[ii][jj] == 'B' && temp[ii][jj] == '.' ) || g[ii][jj] =='G')
			return 1;
		return 0;
	}

	void solve()
	{
		int ii, jj;
		int i, j;
		for (ii = 0; ii < h; ii++)
			for (jj = 0; jj < w; jj++)
			{
				if (g[ii][jj] == '.' || g[ii][jj] == temp[ii][jj])
					continue;

				if ((g[ii][jj] == 'B' && temp[ii][jj] == '.') || (g[ii][jj] == 'G' && temp[ii][jj] == 'R'))
				{
					for (i = ii; i < h; i++)
					{
						if (!canB(i, jj))	break;
						else
						{
							if (temp[i][jj] == '.')
								temp[i][jj] = 'B';
							else
								temp[i][jj] = 'G';
						}
					}
					ans++;
				}
				else if ((g[ii][jj] == 'R' && temp[ii][jj] == '.') || (g[ii][jj] == 'G' && temp[ii][jj] == 'B'))
				{
					for (j = jj; j < w; j++)
					{
						if (!canR(ii, j)) break;
						else
						{
							if (temp[ii][j] == '.')
								temp[ii][j] = 'R';
							else
								temp[ii][j] = 'G';
						}
					}
					ans++;
				}
				else if (g[ii][jj] == 'G' &&  temp[ii][jj] == '.')
				{
					for (i = ii; i < h; i++)
					{
						if (!canB(i, jj))	break;
						else
						{
							if (temp[i][jj] == '.')
								temp[i][jj] = 'B';
							else
								temp[i][jj] = 'G';
						}
					}
					for (j = jj; j < w; j++)
					{
						if (!canR(ii, j)) break;
						else
						{
							if (temp[ii][j] == '.')
								temp[ii][j] = 'R';
							else
								temp[ii][j] = 'G';
						}
					}
					ans += 2;
				}
			}
}

	int getLeast(vector <string> picture) {
		int i, j;
		h = picture.size();
		w = picture[0].size();

		for(i = 0;i < h;i++)
			for(j = 0;j < w;j++)
			{
				g[i][j] = picture[i][j];
				temp[i][j] = '.';
			}
		ans = 0;
		solve();
		return ans;
	}
};
