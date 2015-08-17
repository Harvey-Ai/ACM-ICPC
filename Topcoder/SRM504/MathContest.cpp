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

const int MAX = 100005;
class MathContest
{
public:
int countBlack(string ballSequence, int repetitions)
{
	int seq[MAX];
	char ball;
	int head, tail, inv, invP, res;
	int i, j, k;

	for(k = 0, i = 0;i < repetitions;i++)
		for(j = 0;j < ballSequence.size();j++)
			seq[k++] = ballSequence[j];

	inv = 0; //0 no rev, 1 rev
	invP = 0; //0 head, 1 tail
	head = 0;
	tail = k - 1;
	res = 0;

	while(head <= tail)
	{
		if (invP == 0)
			ball = seq[head++];
		else
			ball = seq[tail--];

		if (ball == 'B' && inv == 0 || ball == 'W' && inv == 1)
		{
			res++;
			inv ^= 1;
		}
		else
			invP ^= 1;
	}
	return res;
}
}; 

