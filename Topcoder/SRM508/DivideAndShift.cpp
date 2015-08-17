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
class DivideAndShift
{
public:
int prime[1000005];

void getP()
{
	int i, j;
	for(i = 0;i < 1000005;i++)
		prime[i] = 1;
	for(i = 2;i * i < 1000005;i++)
		for(j = i;i * j < 1000005;j++)
			prime[i * j] = 0;
}


int pro(int N, int M)
{
	int i;
	int min = (N  + 1 - M) > (M - 1) ? (M - 1) : (N + 1 - M); 
	int begin;
	int b, bn;
	int temp;

	for(i = 2;i <= N;i++)
		if (N % i == 0 && prime[i])
		{
			bn = N / i;
			b = (M - 1) / bn;
			begin = b * bn + 1;
			temp = pro(bn, M - begin + 1) + 1;
			if (min > temp)
				min = temp;

		}
	return min;
}
int getLeast(int N, int M)
{
	getP();
	return pro(N, M);
}
}; 
