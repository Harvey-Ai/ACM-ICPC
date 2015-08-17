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
class Zoo
{
public:
long long theCount(vector <int> answers)
{
	if (answers.size() == 1)
	{
		if (answers[0] == 0)
			return 2;
		else
			return 0;
	}

	long long res = 1;
	int num = answers.size();
	int i;
	int flag[100];
	memset(flag, 0, sizeof(flag));
	for(i = 0;i< answers.size();i++)
		flag[answers[i]]++;

	for(i = 0;i <= 40;i++)
		if (flag[i] == 2)
		{
			res *= 2;
			num -= 2;
		}
		else
			break;

	if (num > 0)
		res *= 2;

	for(;i <= 40;i++)
		if (flag[i] != 1 && num)
			return 0;
		else
		{
			if (num > 0)
				num--;
		}

	return res;
}
}; 
