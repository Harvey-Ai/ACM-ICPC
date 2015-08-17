#include <string>
#include <vector>
#include <map>
#include <queue>
#include <cstring>
#include <iostream>
using namespace std;
class ShadowSculpture {
	public:
	vector<string> XY;
    vector<string> YZ;
    vector<string> ZX;
	int n;

	bool check(int cube[20][20][20])
	{
		for(int i = 0;i < n;i++)
			for(int j = 0;j < n;j++)
			{
				int flag = 0;
				for(int k = 0;k < n;k++)
					flag |= cube[i][j][k];
				if ((XY[i][j] == 'Y') != flag)
					return false;
			}

		for(int i = 0;i < n;i++)
			for(int k = 0;k < n;k++)
			{
				int flag = 0;
				for(int j = 0;j < n;j++)
					flag |= cube[i][j][k];
				if ((ZX[k][i] == 'Y') != flag)
					return false;
			}
		
		for(int j = 0;j < n;j++)
			for(int k = 0;k < n;k++)
			{
				int flag = 0;
				for(int i = 0;i < n;i++)
					flag |= cube[i][j][k];
				if ((YZ[j][k] == 'Y') != flag)
					return false;
			}

		return true;
	}

	void dfs(int x, int y, int z, int cube[20][20][20])
	{
		int dir[6][3] = {{0, 0, 1}, {0, 0, -1}, {1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}};
		
		for(int i = 0;i < 6;i++)
			if ((x + dir[i][0] >= 0 && x + dir[i][0] < n)
					&& (y + dir[i][1] >= 0 && y + dir[i][1] < n)
					&& (z + dir[i][2] >= 0 && z + dir[i][2] < n)	
					&& XY[x + dir[i][0]][y + dir[i][1]] == 'Y'
				   	&& YZ[y + dir[i][1]][z + dir[i][2]] == 'Y'
					&& ZX[z + dir[i][2]][x + dir[i][0]] == 'Y'
					&& !(cube[x + dir[i][0]][y + dir[i][1]][z + dir[i][2]]))
			{
				cube[x + dir[i][0]][y + dir[i][1]][z + dir[i][2]] = 1;
				dfs(x + dir[i][0], y + dir[i][1], z + dir[i][2], cube);
			}
	}

	string possible(vector <string> XY, vector <string> YZ, vector <string> ZX) {
		int cube[20][20][20];
		memset(cube, 0, sizeof(cube));
		this->XY = XY;
		this->YZ = YZ;
		this->ZX = ZX;
		n = XY.size();

		int flag = 0;
		for(int i = 0;i < n;i++)
			for(int j = 0;j < n;j++)
				for(int k = 0;k < n;k++)
				{
					int temp[20][20][20];
					memset(temp, 0, sizeof(temp));
					if (XY[i][j] == 'Y' && YZ[j][k] == 'Y' && ZX[k][i] == 'Y'
							&& !cube[i][j][k])
					{
						flag = 1;
						temp[i][j][k] = 1;
						dfs(i, j, k, temp);
						if (check(temp))
							return "Possible";
						
						for(int ii = 0;ii < 20;ii++)
							for(int jj = 0;jj < 20;jj++)
								for(int kk = 0;kk < 20;kk++)
									cube[ii][jj][kk] |= temp[ii][jj][kk];
					}	
				}

		if (flag == 0 && check(cube))
			return "Possible";
		return "Impossible";
	}
};
