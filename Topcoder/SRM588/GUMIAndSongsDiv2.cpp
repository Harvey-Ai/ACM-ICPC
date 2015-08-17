#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
struct song
{
	int du, tone;
};
int cmp(const song &a, const song &b)
{
	if (a.tone > b.tone)
		return 0;
	else
		return 1;
}

class GUMIAndSongsDiv2 {
	public:
		song songs[20];
		int res;
		int songNum;
		int fullTime;
		void dfs(int k, int time, int singNum)
		{
			if (k >= songNum - 1 || time > fullTime)
			{
				printf("%d %d, sing%d\n", time, k,singNum);
				if (time > fullTime)
					singNum--;
				if (singNum > res)
					res = singNum;
				return;
			}

			for(int i = k + 1;i < songNum;i++)
				if (singNum == 0)
					dfs(i, time + songs[i].du, singNum + 1);
				else
					dfs(i, time + songs[i].du + abs(songs[k].tone - songs[i].tone), singNum + 1);
		}	
		int maxSongs(vector <int> duration, vector <int> tone, int T) {
			for(int i = 0;i < duration.size();i++)
			{
				songs[i].du = duration[i];
				songs[i].tone = tone[i];
			
			}
			fullTime = T;
			songNum = duration.size();
			sort(songs, songs + duration.size(), cmp);
			for(int i = 0;i < duration.size();i++)
				printf("%d %d\n", songs[i].du, songs[i].tone);
			res = 0;
			dfs(-1, 0, 0);
			return res;
		}
};

int main()
{
	vector<int> a, b;
	int time = 17;
	a.push_back(3);
	a.push_back(5);
   	a.push_back(4);
   	a.push_back(11);
	b.push_back(2);
   	b.push_back(1);
	b.push_back(3);
   	b.push_back(1);
	GUMIAndSongsDiv2 cc;
	printf("%d\n", cc.maxSongs(a, b, time));
}
