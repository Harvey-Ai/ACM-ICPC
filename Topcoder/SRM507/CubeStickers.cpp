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
class CubeStickers
{
public:
string isPossible(vector <string> sticker)
{
	int size = sticker.size();
	int i;
	int num;
	int oneN;

	sort(&sticker[0], &sticker[size]);

	num = 0;
	oneN = 1;

	for(i = 1;i < size;i++)
		if (sticker[i] != sticker[i - 1])
		{
			num += oneN > 2 ? 2 : oneN;
			oneN = 1;
		}
		else
			oneN++;

	num += oneN > 2 ? 2 : oneN;

	if (num >= 6)
		return "YES";
	else
		return "NO";
}
}; 
