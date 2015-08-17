#include <vector>
#include <algorithm>

class TheMoviesLevelTwoDivTwo
{
	public:
		int arr[10][10];
		int used[10];
		vector <int> ans;
		vector <int> temp;
		int cnt;
		int ansN;
		vector <int> find(vector <int> length, vector <int> scary);
		void dfs(int depth, int scary);
};

void TheMoviesLevelTwoDivTwo::dfs(int depth, int scary)
{
	vector<int>::interator it, last;
	int i, midScary, endScary;
	if (depth == 7)
	{
		int num;
		if (scary < 0)
		{
			last = TheMoviesLevelTwoDivTwo::temp.end() - 1;
			num = 6;
		}
		else
		{
			last = TheMoviesLevelTwoDivTwo::temp.end();
			num = 7;
		}
		if (TheMoviesLevelTwoDivTwo::ansN < num)
		{
			TheMoviesLevelTwoDivTwo::ansN = num;
			TheMoviesLevelTwoDivTwo::ans.clear();
			for(it = TheMoviesLevelTwoDivTwo::temp.begin();it != last;it++)
				TheMoviesLevelTwoDivTwo::ans.push_back(*it);
		}
		return;
	}

	for(i = 0;i < TheMoviesLevelTwoDivTwo::cnt;i++)
		if (!TheMoviesLevelTwoDivTwo::used[i])
		{
			TheMoviesLevelTwoDivTwo::uesd[i] = 1;
			midScary = scary - TheMoviesLevelTwoDivTwo::arr[i][1];
			endScary = scary - TheMoviesLevelTwoDivTwo::arr[i][0] + 47;
			if (midScary >=0 && endScary >= 0)
			{
				TheMoviesLevelTwoDivTwo::temp.push_back(i);
				dfs(depth + 1, endScary);
				TheMoviesLevelTwoDivTwo::temp.pop_back(i);
			}
			else
			{
				last = TheMoviesLevelTwoDivTwo::temp.begin() - 1;
				if (TheMoviesLevelTwoDivTwo::ansN < depth)
				{
					TheMoviesLevelTwoDivTwo::ansN = depth;
					TheMoviesLevelTwoDivTwo::ans.clear();
					for(it = TheMoviesLevelTwoDivTwo::temp.begin();it != last;it++)
						TheMoviesLevelTwoDivTwo::ans.push_back(*it);
				}
			}
			TheMoviesLevelTwoDivTwo::used[i] = 0;
		}
}

vector <int> TheMoviesLevelTwoDivTwo::find(vector <int> length, vector <int> scary)
{
	vector<int>::interator it1, it2;
	
	TheMoviesLevelTwoDivTwo::cnt = 0;
	for(it1 = length.begin(), it2 = scary.begin();it1 != length.end();it1++, it2++)
	{
		TheMoviesLevelTwoDivTwo::arr[cnt][0] = *it1;
		TheMoviesLevelTwoDivTwo::arr[cnt++][1] = *it2;
	}

	memset(TheMoviesLevelTwoDivTwo::used, 0, sizeof(TheMoviesLevelTwoDivTwo::used));
	TheMoviesLevelTwoDivTwo::ansN = 0;
	TheMoviesLevelTwoDivTwo::ans.clear();
	TheMoviesLevelTwoDivTwo::temp.clear();
	dfs(0, 74);
	return TheMoviesLevelTwoDivTwo::ans;
}
