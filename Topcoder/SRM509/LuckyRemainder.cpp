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
class LuckyRemainder
{
public:
int C[55][55];
void pre()
{
	int i, j;
//	memset(C, 0, sizeof(C));
	C[1][1] = 1;
	C[0][0] = 1;
	C[0][1] = 0;
	for(i = 1;i < 55;i++)
	{
		C[i - 1][0] = 1;
		for(j = 1;j <= i;j++)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % 9;
	}
}
int getLuckyRemainder(string X)
{
	int size = X.size();
	int res = 0;
	int i, j1, j2;
	pre();
	for(i = 0;i < size;i++)
		for(j1 = 0;j1 <= i;j1++)
			for(j2 = 0;j2 <= size - 1 - i;j2++)
			{
				res += ((C[i][j1] * C[size - 1 - i][j2]) * (X[i] - '0')) % 9;
				res %= 9;
			//	printf("%d\n", res);
			}

	printf("%d\n", res % 9);
	return res % 9;
}
}; 

