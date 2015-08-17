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
class TheLotteryBothDivs
{
	vector <string> flip(vector <string> suf)
	{
		int i, j, k;
		vector <string> vv;

		sort(&suf[0], &suf[suf.size()]);

		for(i = 0;i < suf.size();i++)
		{
			for(j = 0;j < i;j++)
			{
				for(k = 0;k < suf[j].size();k++)
					if (suf[i][k] != suf[j][k])
						break;
				if (k >= suf[j].size())
					break;
			}
			if (j >= i)
				vv.push_back(suf[i]);
		}
		return vv;
	}
	public:
	double find(vector <string> goodSuffixes)
	{
		int i;
		double prob[100];
		vector <string> real;
		double res;

		for(i = 0;i < goodSuffixes.size();i++)
			reverse(goodSuffixes[i].begin(), goodSuffixes[i].end());
		real = flip(goodSuffixes);

		prob[0] = 1;
		for(i = 1;i < 20;i++)
			prob[i] = prob[i - 1] * 0.1;
	
		res = 0;
		for(i = 0;i < real.size();i++)
			res += prob[real[i].size()];

		return res;
	}
}; 
