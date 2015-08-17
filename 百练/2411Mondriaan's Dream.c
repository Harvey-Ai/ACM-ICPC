#include <iostream>
using namespace std;


int work(int m, int n)
{
	int dp[2][2048];

	for(i = 0;i < 2048;i++)
		dp[0][i] = dp[1][i] = 0;
	dp[0][2047] = 1;
	
	int stateNum = pow(2, n);
	int now = 1, before = 0;
	for(i = 0;i < m;i++)
	{
		int temp = now;
		now = before;
		before = temp;

		for(j = 0;j < stateNum;j++)
		{
			beforeState = ~j;
			dp[now][j] = dp[before][beforeState];
			if (j == 2047)
			{
				if (n % 2 == 0)
					dp[now][j] += dp[before][0];
			}
		}

	}
	
}

int main()
{
	int m, n;
	while(cin >> m >> n, m != 0 && n != 0)
		cout << work(m, n) << endl;
	return 0;
}
