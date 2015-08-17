#include <string>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;
class ChocolateDividingEasy {
	public:
	int sum[100][100];
	int findBest(vector <string> chocolate) {
		int row = chocolate.size();
		int column = chocolate[0].size();
		memset(sum, 0, sizeof(sum));
		
		for(int i = 1;i <= row;i++)
			for(int j = 1;j <= column;j++)	
				sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + chocolate[i - 1][j - 1] - '0'; 

		int res = 0;
		for(int i = 1;i < row - 1;i++)
			for(int j = i + 1;j < row;j++)
			{
				for(int k = 1;k < column - 1;k++)
					for(int l = k + 1;l < column;l++)
					{
						int minValue = sum[i][k];
						minValue = min(sum[i][l] - sum[i][k], minValue);
						minValue = min(sum[i][column] - sum[i][l], minValue);

						minValue = min(sum[j][k] - sum[i][k], minValue);
						minValue = min(sum[j][l] - sum[j][k] - sum[i][l] + sum[i][k], minValue);
						minValue = min(sum[j][column] - sum[j][l] - sum[i][column] + sum[i][l], minValue);
						
						minValue = min(sum[row][k] - sum[j][k], minValue);
						minValue = min(sum[row][l] - sum[row][k] - sum[j][l] + sum[j][k], minValue);
						minValue = min(sum[row][column] - sum[row][l] - sum[j][column] + sum[j][l], minValue);

						if (minValue > res)
							res = minValue;
					}
			}

		return res;
	}
};
