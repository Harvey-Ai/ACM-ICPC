#include <string>
#include <vector>
#include <iostream>
using namespace std;
class ApplesAndPears {
	public:
	int getArea(vector <string> board, int K) {
		int rowNum = board.size();
		int columnNum = board[0].size();

		int pearSum[55][55];
		int appleSum[55][55];
		int emptySum[55][55];

		for(int i = 0;i < 55;i++)
		{
			pearSum[0][i] = appleSum[0][i] = emptySum[0][i] = 0;
			pearSum[i][0] = appleSum[i][0] = emptySum[i][0] = 0;
		}

		for(int i = 1;i <= rowNum;i++)
			for(int j = 1;j <= columnNum;j++)
			{
				int isPear = (board[i - 1][j - 1] == 'P') ? 1 : 0;
				int isApple = (board[i - 1][j - 1] == 'A') ? 1 : 0;
				int isEmpty = (board[i - 1][j - 1] == '.') ? 1 : 0;
				pearSum[i][j] = pearSum[i - 1][j] + pearSum[i][j - 1] - pearSum[i - 1][j - 1] + isPear;
				appleSum[i][j] = appleSum[i - 1][j] + appleSum[i][j - 1] - appleSum[i - 1][j - 1] + isApple;
				emptySum[i][j] = emptySum[i - 1][j] + emptySum[i][j - 1] - emptySum[i - 1][j - 1] + isEmpty;
			}
		
		int pearTotal = pearSum[rowNum][columnNum];
		int appleTotal = appleSum[rowNum][columnNum];
		int emptyTotal = emptySum[rowNum][columnNum];

		int res = 1;
		for(int i1 = 0;i1 < rowNum;i1++)
			for(int i2 = i1;i2 < rowNum;i2++)
				for(int j1 = 0;j1 < columnNum;j1++)
					for(int j2 = j1;j2 < columnNum;j2++)
					{
						int rectSize = (i2 - i1 + 1) * (j2 - j1 + 1);
						if (res > rectSize)
							continue;
						int pearIn = pearSum[i2 + 1][j2 + 1] - pearSum[i2 + 1][j1] - pearSum[i1][j2 + 1] + pearSum[i1][j1];
						int appleIn = appleSum[i2 + 1][j2 + 1] - appleSum[i2 + 1][j1] - appleSum[i1][j2 + 1] + appleSum[i1][j1];
						int emptyIn = emptySum[i2 + 1][j2 + 1] - emptySum[i2 + 1][j1] - emptySum[i1][j2 + 1] + emptySum[i1][j1];


						if (pearTotal >= rectSize && ((pearIn < rectSize && emptyTotal > 0) || (pearIn == rectSize)))
						{
							int moveTime = emptyIn + appleIn * 2;
							if (moveTime <= K)
								res = rectSize;
						}
						if (appleTotal >= rectSize && ((appleIn < rectSize && emptyTotal > 0) || (appleIn == rectSize)))
						{
							int moveTime = emptyIn + pearIn * 2;
							if (moveTime <= K)
								res = rectSize;
						}
						if (emptyTotal >= rectSize && (rectSize - emptyIn) <= K)
							res = rectSize;
					}
		return res;
	}
};
