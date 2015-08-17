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

class MysteriousRestaurant
{
public:
int maxDays(vector <string> prices, int budget)
{
	int res = 0;
	int i, j, k;
	int min, temp;
	int sum[10];
	for(i = 0;i < 10;i++)
		sum[i] = 0;

	for(i = 0; i < prices.size();i++)
	{
		if (budget < 0)
			break;

		min = -1;
		// calc every type
		for(j = 0;j < prices[i].size();j++)
		{
			temp = 0;
			for(k = i % 7;k <= i;k += 7)
			{
				if (prices[k][j] >= '0' && prices[k][j] <= '9')
			//	{
		//			putchar('f');
					temp += prices[k][j] - '0';
		//		}
				else if (prices[k][j] >= 'A' && prices[k][j] <= 'Z')
					temp += prices[k][j] - 'A' + 10;
				else if (prices[k][j] >= 'a' && prices[k][j] <= 'z')
					temp += prices[k][j] - 'a' + 36;
			}
			if (temp < min || min == -1)
				min = temp;
		}
	//	printf("%d %d %d\n", min, min - sum[i % 7], budget);

		if (budget >= min - sum[i % 7])
		{
			budget -= min - sum[i % 7];
			sum[i % 7] = min;
			res++;
		}
		else
			break;
	}
	return res;
}
}; 
