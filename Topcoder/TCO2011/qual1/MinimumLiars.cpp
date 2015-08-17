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
class MinimumLiars
{
public:
int getMinimum(vector <int> claim)
{
	int size = claim.size();
	int i, j, flag;
	int lN;

	flag = 0;
	for(i = 0;i <= 51;i++)
	{
		lN = 0;
		for(j = 0;j < size;j++)
			if (claim[j] > i)
				lN++;
	
	//	printf("%d %d\n", i, lN);
		if (lN == i)
		{
			flag = 1;
			break;
		}
	}
	
	if (flag)
		return lN;
	else
		return -1;
}
}; 
