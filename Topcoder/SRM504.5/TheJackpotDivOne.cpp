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
class TheJackpotDivOne
{
public:
vector<long long> find(vector<long long> money, long long jackpot)
{
	int flag = 1;
	long long add;
	long long a, b;
	int size;
	int i;
	long long avg;

	vector<long long> res;

	if (money.size() == 1)
	{
		money[0] += jackpot;
		res = money;
		return res;
	}

	size = money.size();

	while(flag)
	{
		if (jackpot <= 0)
			break;

		sort(&money[0], &money[money.size()]);
		a = b = 0;
		for(i = 0;i < size;i++)
		{
			a += money[i] / size;
			b += money[i] % size;
		}

		avg = a + b / size + 1; 
		add = avg - money[0];
		if (jackpot < add)
			add = jackpot;

		money[0] += add;
		jackpot -= add;

		flag = 0;
		for(i = 1;i < size - 1;i++)
			if (money[i] != money[i - 1])
			{
				flag = 1;
				break;
			}
	}

	if (jackpot > 0)
	{
		add = jackpot / size;
		for(i = 0;i < size;i++)
			money[i] += add;
		jackpot -= add * size;

		for(i = 0;i < size && jackpot > 0;i++)
		{
			money[i]++;
			jackpot--;
		}
	}

	sort(&money[0], &money[money.size()]);
	res = money;
	return res;
}
}; 
