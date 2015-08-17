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
class FiveHundredEleven
{
	vector < int > cc;
	int state[55][550];
	int n;
public:
int isWin(int picked, int mem)
{
	if (mem == 511)
	{
		state[picked][mem] = 1;
		return 1;
	}

	if (picked == n)
	{
		state[picked][mem] = 0;
		return 0;
	}

	if (state[picked][mem] != -1)
		return state[picked][mem];
	
	int probN = n;
	for(int i = 0;i < n;i++)
		if ((mem | cc[i]) != mem)
		{
			probN--;
			if (!isWin(picked + 1, (mem | cc[i])))
			{
				state[picked][mem] = 1;
				return 1;
			}
		}

	if (probN > picked && !isWin(picked + 1, mem))
	{
		state[picked][mem] = 1;
		return 1;
	}

	state[picked][mem] = 0;
	return 0;
}
string theWinner(vector <int> cards)
{
	memset(state, -1, sizeof(state));
	cc = cards;
	n = cards.size();
	int res = isWin(0, 0);
	printf("%d\n", res);
	return res ? "Fox Ciel" : "Toastman";
}
}; 
