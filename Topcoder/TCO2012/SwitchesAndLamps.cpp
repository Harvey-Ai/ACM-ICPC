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
class SwitchesAndLamps
{
public:
int theMin(vector <string> switches, vector <string> lamps)
{
	int Num = switches.size();
	int size = switches[0].size();
	int i, j;
	
	map<string, int> v1, v2;
	for(i = 0;i < size;i++)
	{
		string ss, ll;
		for(j = 0;j < Num;j++)
		{
			ss += switches[j][i];
			ll += lamps[j][i];
		}
		v1[ss]++;
		v2[ll]++;
	}

	map<string, int>::iterator it;
	int max = 0;
	for(it = v1.begin();it != v1.end();it++)
	{
		if (it->second != v2[it->first])
			return -1;
		if (it->second > max)
			max = it->second;
	}

	int count = 1;
	int res = 0;
	while(count < max)
	{
		count *= 2;
		res++;
	}
	return res;
}
};
