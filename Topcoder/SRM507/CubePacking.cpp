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
class CubePacking
{
public:
int getMinimumVolume(int Ns, int Nb, int L)
{
	long long a, b;
	long long res = -1;
	long long baseLNum, heighLNum;
	long long left;
	long long volume;

	for(a = L;a * a * a <= Ns + Nb * L * L * L + L * L;a++)
		for(b = a;a * b * b <= Ns + Nb * L * L * L + L * L;b++)
		{
			baseLNum = (a / L) * (b / L);
			heighLNum = (Nb + (baseLNum - 1)) / baseLNum;

			volume = a * b * heighLNum * L;
			left = Ns - (volume - Nb * L * L * L);

			if (left > 0)
				volume += (left + (a * b) - 1) / (a * b) * (a * b);

			if (res == -1 || volume < res)
				res = volume;
		}

	return (int)res;
}
};
