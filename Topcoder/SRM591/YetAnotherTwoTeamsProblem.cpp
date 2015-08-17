#include <string>
#include <vector>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class YetAnotherTwoTeamsProblem {
	public:
	static bool cmp(int a, int b)
	{
		return a > b;
	}

	long long dp[60000 * 50 + 1];
	long long res = 0;

	long long count(vector <int> skill) {
		double sum = 0;
		for(int i = 0;i < 60000 * 50 + 1;i++)
			dp[i] = 0;
		for(int i = 0;i < skill.size();i++)
			sum += skill[i];
/*
		for(int i = 0;i < skill.size();i++)
			for(int j = 0;j < skill.size() - 1;j++)
				if (skill[j + 1] > skill[j])
				{
					int temp = skill[j + 1];
					skill[j + 1] = skill[j];
					skill[j] = temp;
				}
				*/
		sort(skill.begin(), skill.end(), cmp);
		dp[0] = 1;

		for(int i = 0;i < skill.size();i++)
			for(int j = sum;j >= 0;j--)
			{
				if (dp[j])
				{
					dp[j + skill[i]] += dp[j];
					if (j + skill[i] > sum - j - skill[i] && j < sum - j)
						res += dp[j];
				}
			}
		return (long long)res;
	}
};
