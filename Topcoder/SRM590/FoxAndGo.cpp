#include <string>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
class FoxAndGo {
	public:
	int m, n;
	int data[100][100];
	int used[100][100];
	int killed;
	int live;
	void check(int i, int j)
	{
		used[i][j] = 1;
		killed++;
		if (i >= 1 && !used[i - 1][j])
		{
			if (data[i - 1][j] == '.')
				live = 1;
			else
				if (data[i - 1][j] == 'o')
					check(i - 1, j);
		}
		if (i < m - 1 && !used[i + 1][j])
		{
			if (data[i + 1][j] == '.')
				live = 1;
			else
				if (data[i + 1][j] == 'o')
					check(i + 1, j);
		}

		if (j >= 1 && !used[i][j - 1])
		{
			if (data[i][j - 1] == '.')
				live = 1;
			else
				if (data[i][j - 1] == 'o')
					check(i, j - 1);
		}
		if (j < n - 1 && !used[i][j + 1])
		{
			if (data[i][j + 1] == '.')
				live = 1;
			else
				if (data[i][j + 1] == 'o')
					check(i, j + 1);
		}
	}


	int maxKill(vector <string> board) {

		m = board.size();
		n = board[0].size();
		for(int i = 0;i < m;i++)
			for(int j = 0;j < n;j++)
				data[i][j] = board[i][j];
		
		int best = 0;
		memset(used, 0, sizeof(used));
		for(int i1 = 0;i1 < m;i1++)
			for(int j1 = 0;j1 < n;j1++)
			{
				killed = 0;
				live = 0;
				if (data[i1][j1] != 'o')
					continue;
				if (!used[i1][j1])
				{
					check(i1, j1);
					if (!live)
						best += killed;
				}
			}
		cout << best << endl;
		//printf("%d\n", best);
		for(int i = 0;i < m;i++)
			for(int j = 0;j < n;j++)
				if (data[i][j] == '.')
				{
					data[i][j] = 'x';
					memset(used, 0, sizeof(used));
					int temp = 0;
					for(int i1 = 0;i1 < m;i1++)
						for(int j1 = 0;j1 < n;j1++)
						{
							if (data[i1][j1] != 'o')
								continue;
							killed = 0;
							live = 0;
							if (!used[i1][j1])
							{
								check(i1, j1);
								if (!live)
									temp += killed;
							}
						}
					if (temp > best)
					{
						printf("(%d %d) :%d\n", i, j, temp);
						best = temp;
					}
					data[i][j] = '.';
				}
		return best;

	}
};
