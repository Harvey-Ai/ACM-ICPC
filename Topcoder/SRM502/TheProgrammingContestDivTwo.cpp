#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
class TheProgrammingContestDivTwo
{
	public:
	vector <int> find(int T, vector <int> requiredTime)
	{
		int score, penalty;
		int i;
		int time;
		vector <int> res;
		sort(&requiredTime[0], &requiredTime[requiredTime.size()]);

		score = 0;
		penalty = 0;

		time = 0;
		i = 0;
		while(time <= T && i < requiredTime.size())
		{
			time += requiredTime[i];
			i++;
			if (time > T)
				break;

			score++;
			penalty += time;
		}
		res.push_back(score);
		res.push_back(penalty);
		return res;
	}
}; 
