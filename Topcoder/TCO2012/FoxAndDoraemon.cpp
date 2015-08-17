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
class FoxAndDoraemon
{
public:
int minTime(vector <int> workCost, int splitCost)
{
	int temp1[100];
	int len = workCost.size();
	int len1, i;
	sort(&workCost[0], &workCost[len]);

	for(i = 0;i < len;i++)
		temp1[i] = workCost[i];
	len1 = len;

	while(len1 != 1)
	{
		sort(&temp1[0], &temp1[len1]);
		temp1[1] = splitCost + temp1[1];
		for(i = 0;i < len1 - 1;i++)
			temp1[i] = temp1[i + 1];
		len1--;
	}
	return temp1[0];
}
}; 
