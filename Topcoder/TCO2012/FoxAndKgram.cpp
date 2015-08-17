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

class FoxAndKgram
{
public:
int maxK(vector <int> len)
{
	int lg = len.size();
	int i, j, k;
	int flag[1000];

	for(i = lg;i >= 1;i--)
	{
		memset(flag, 0, sizeof(flag));
		int rowNum = 0;
		for(j = 0;j < lg;j++)
		{
			if (flag[j])
				continue;
			if (len[j] == i)
			{
				flag[j] = 1;
				rowNum++;
				continue;
			}
			for(k = j + 1;k < lg;k++)
				if (!flag[k])
				{
					if (len[j] + len[k] + 1 == i)
					{
						flag[j] = flag[k] = 1;
						rowNum++;
						break;
					}
				}
		}
		if (rowNum >= i)
			return i;
	}
	return 0;
}
}; 
