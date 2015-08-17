#include <string>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;
class LittleElephantAndXor {
	int bitA[50], bitB[50], bitC[50];
	long long dp[41][2][2][2];

	public:
	void getBit(int k, int arr[50])
	{
		for(int i = 0;k;i++)
		{
			arr[i] = k & 0x01;
			k >>= 1;
		}
	}
	long long F(int t, int eqA, int eqB, int eqC)
	{
		long long res = 0;
		if (t == -1)
			return 1;
		else
		{
			if (dp[t][eqA][eqB][eqC] != -1)
				return dp[t][eqA][eqB][eqC];
			for(int a = 0;a < 2;a++)
				for(int b = 0;b < 2;b++)
				{
					int c = a ^ b;
					if ((a <= bitA[t] || !eqA) &&
						(b <= bitB[t] || !eqB) &&
						(c <= bitC[t] || !eqC))
						res += F(t - 1, eqA && (a == bitA[t]), eqB && (b == bitB[t]), eqC && (c == bitC[t]));
				}
		}
		dp[t][eqA][eqB][eqC] = res;
		return res;		
	}

	long long getNumber(int A, int B, int C) {
		memset(bitA, 0, sizeof(bitA));
		memset(bitB, 0, sizeof(bitB));
		memset(bitC, 0, sizeof(bitC));
		getBit(A, bitA);
		getBit(B, bitB);
		getBit(C, bitC);
		memset(dp, -1, sizeof(dp));
		return F(40, 1, 1, 1);
	}
};
