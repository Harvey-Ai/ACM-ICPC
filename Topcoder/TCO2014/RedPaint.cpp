#include <string>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
class RedPaint {
	public:
	double status1[505][505];
	double status2[505][505];
	double expectedCells(int N) {
		memset(status1, 0, sizeof(status1));
		status1[0][1] = 1;

		for(int i = 0;i < N;i++)
		{
			memset(status2, 0, sizeof(status2));
			for(int j = 0; j < 500;j++)			// pos
				for(int k = j + 1;k < 505;k++)	// len
				{
					double left = 0, right = 0;
					if (j > 0)
					{
						left = status1[j - 1][k] * 0.5;
						if (j - 1 + 1 == k - 1)
							left += status1[j - 1][k - 1] * 0.5;
					}
					
					right = status1[j + 1][k] * 0.5;
					if (j == 0)
						right += status1[0][k - 1] * 0.5;
					status2[j][k] = left + right;
				}
			
			for(int j = 0;j < 505;j++)
				for(int k = 0;k < 505;k++)
					status1[j][k] = status2[j][k];
		}

		double res = 0;
		for(int i = 0;i < 500;i++)
			for(int j = 1;j <= 500;j++)
				res += status1[i][j] * j;
		return res;
	}
};
