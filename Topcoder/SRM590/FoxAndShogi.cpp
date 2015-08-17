#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <cstring>
#include <string>
using namespace std;

const long long MOD = 1000000007;

class FoxAndShogi {
	public:
	int m, n;
	vector<pair<int, int>> line;
	long long dp[100][100];

	long long calc(int ind, int pos)
	{
		int possiblePos = pos + 1 > line[ind].first ? pos + 1 : line[ind].first;
		long long temp = 0;
		if (ind >= line.size())
			return 1;
		if (possiblePos > line[ind].first && line[ind].second == -1)
			return 0;

		for(int j = possiblePos;j > pos && j < m;j += line[ind].second)
		{
			if (dp[ind + 1][j] == -1)
				dp[ind + 1][j] = calc(ind + 1, j) % MOD;
			temp += dp[ind + 1][j];
			temp %= MOD;
		}
		
		return temp % MOD;
	}

	int differentOutcomes(vector <string> board) {
		m = board.size();
		n = board[0].size();

		long long ret = 1;
		for(int i = 0;i < n;i++)
		{
			line.clear();
			memset(dp, -1, sizeof(dp));
			for(int j = 0;j < m;j++)
				if (board[j][i] == 'U')
					line.push_back(make_pair(j, -1));
				else if (board[j][i] == 'D')
					line.push_back(make_pair(j, 1));
			if (line.size() == 0)
				continue;
			ret *= calc(0, -1);
			ret %= MOD;
		}
		return ret;
	}
};
