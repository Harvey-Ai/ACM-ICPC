#include <stdio.h>

class TheMoviesLevelOneDivTwo
{
	public:
		int find(int n, int m, vector <int> row, vector <int> seat);
};

int TheMoviesLevelOneDivTwo:find(int n, int m, vector <int> row, vector <int> seat);
{
	int g[50][50];
	int res = 0;
	vector<int>::interator it1, it2;
	memset(g, 0, sizeof(g));

	for(it1 = row.begin(), it2 = seat.begin();it1 != row.end();it1++, it2++)
		g[*it1][*it2] = 1;

	for(i = 1;i <= n;i++)
		for(j = 1;j < m;j++)
			if (g[i][j] && g[i][j + 1])
				res++;
	return res;
}
