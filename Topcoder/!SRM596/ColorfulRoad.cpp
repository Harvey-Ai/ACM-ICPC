#include <string>
#include <vector>
#include <iostream>
using namespace std;
class ColorfulRoad {
	public:
	int getMin(string road) {
		int dp[20];
		dp[0] = 0;

		for(int i = 1;i < road.size();i++)
		{
			dp[i] = -1;
			for(int j = 0;j < i;j++)
				if (dp[j] != -1 && ((road[i] == 'R' && road[j] == 'B') ||
					(road[i] == 'G' && road[j] == 'R') ||
					(road[i] == 'B' && road[j] == 'G')))
				{
					if (dp[i] == -1 || dp[i] > dp[j] + (i - j) * (i - j))
						dp[i] = dp[j] + (i - j) * (i - j);
				}
		}
		return dp[road.size() - 1];
	}
};
