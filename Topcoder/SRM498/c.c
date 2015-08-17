#include <string>
using namespace std;
class NinePuzzle
{
	public:
	int getMinimumCost(string init, string goal)
	{
		int flag[1000];
		int ans;
		int i, j;
		ans = 0;
		memset(flag, 0, sizeof(flag));
		for(i = 0;i < init.size();i++)
		{
			for(j = 0;j < goal.size();j++)
			{
				if (!flag[j] && init[i] == goal[j])
				{
					flag[j] = 1;
					break;
				}
			}
			if (j >= goal.size())
				ans++;
		}
		return ans;
	}
};

