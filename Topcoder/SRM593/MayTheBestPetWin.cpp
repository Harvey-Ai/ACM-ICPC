#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

int dp[2][10000 * 50 * 2 + 5];
int base = 10000 * 50;

class MayTheBestPetWin {
	public:
	int calc(vector <int> A, vector <int> B) {
		memset(dp[0], 0, sizeof(dp[0]));
		memset(dp[1], 0, sizeof(dp[1]));

		int sumB = 0, sumA = 0;
		for(int i = 0;i < A.size();i++)
			sumA += A[i];
		for(int i = 0;i < B.size();i++)
			sumB += B[i];

		int oldI = 0, newI = 1;
		dp[oldI][A[0] + base] = 1;
		dp[oldI][-B[0] + base] = 1;
		for(int i = 1;i < A.size();i++)
		{
			memset(dp[newI], 0, sizeof(dp[newI]));
			for(int j = -10000 * 50;j <= 10000 * 50;j++)
				if (dp[oldI][j + base])
				{
					dp[newI][j + A[i] + base] = 1;
					dp[newI][j - B[i] + base] = 1;
				}
			swap(oldI, newI);
		}
		
		int res = - 1;
		for(int i = -10000 * 50;i <= 10000 * 50;i++)
		{
			if (!dp[oldI][i + base])
				continue;
			int temp =  fabs(sumB - sumA + i);
			if (temp < fabs(i))
				temp = fabs(i);
			if (temp < res || res == -1)
				res = temp;
		}
		return res;
	}
};
