#include <string>
#include <vector>
using namespace std;
class StringWeightDiv2 {
	public:
	long long C[100][100];
	int calc()
	{
		for(int i = 0;i < 100;i++)
			C[i][0] = 1;

		C[1][1] = 1;
		for(int i = 2;i <= 26;i++)
		{
			C[i][i] = 1;
			for(int j = 1;j <= i - 1;j++)
				C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % 1000000009;
		}
		return 0;
	}
	int countMinimums(int L) {
		if (L < 26)
		{
			long long res = 26;
			for(int i = 1;i < L;i++)
			{
				res *= 25;
				res %= 1000000009;
			}
			return res; 
		}

		long long base = 26;
		for(int i = 1;i < L;i++)
		{
			base *= 25;
			base %= 1000000009;
		}
		int av = L / 26;
		int left = L - av * 26;
		calc();
		printf("%lld\n", C[26][left]);
		return (C[26][left] * base) % 1000000009;
	}
};
