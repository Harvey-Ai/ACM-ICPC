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
class FoxProgression
{
public:
int theCount(vector <int> seq)
{
	int ap1, ap2;
	int i;
	int d, g, dis, div;
	int len = seq.size();

	if (len < 2)
		return -1;

	d = 1;
	dis = seq[1] - seq[0];
	if (seq[0] == 0 || seq[1] % seq[0] != 0)
	{
		div = 1;
		g = 0;
	}
	else
	{
		g = 1;
		div = seq[1] / seq[0];
	}
	for(i = 2;i < len;i++)
	{
		if (seq[i] - seq[i - 1] != dis)
			d = 0;

		if (seq[i - 1] == 0 || seq[i] != seq[i - 1] * div)
			g = 0;
	}
	if (seq[len - 1] == 0)
		g = 0;

	ap1 = ap2 = 1;
	if (d == 1)
		ap1 = seq[len - 1] + dis;
	if (g == 1)
		ap2 = seq[len - 1] * div;

	if (d == 1 && g == 1)
		return d + g - (ap1 == ap2 ? 1 : 0);
	else
		return d + g;
}
}; 
