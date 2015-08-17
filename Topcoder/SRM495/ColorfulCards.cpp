// BEGIN CUT HERE

// END CUT HERE
#line 5 "ColorfulCards.cpp"
#include <string>
#include <vector>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std ;

int pp[1005], pprime[1005];
int cl[1005];
int primeNum;
int ll[1005], rr[1005];

void getPrime()
{
	int i, j;
	memset(pp, 0, sizeof(pp));
	pp[2] = 1;
	pprime[0] = 2;
	primeNum = 1;

	for(i = 3;i < 1005;i++)
	{
		for(j = 2;j * j <= i;j++)
			if (i % j ==0)
				break;
		if (j * j > i)
		{
			pp[i] = 1;
			pprime[primeNum++] = i;
		}
	}
}

class ColorfulCards {
	public:
	vector <int> theCards(int N, string colors) {
		int i;
		int pos;
		int ssize = colors.size();
		vector <int> ans;
		getPrime();
		for(i = 0;i < ssize;i++)
			if (colors[i] == 'R')
				cl[i] = 1;
			else
				cl[i] = 0;

		pos = 1;
		for(i = 0;i < ssize;i++)
		{
			while (pp[pos] != cl[i])
				pos++;
			ll[i] = pos;
			pos++;
		}

		pos = N;
		for(i = ssize - 1;i >= 0;i--)
		{
			while (pp[pos] != cl[i])
				pos--;
			rr[i] = pos;
			pos--;
		}
		
		ans.clear();
		for(i = 0;i < ssize;i++)
			if (ll[i] != rr[i])
				ans.push_back(-1);
			else
				ans.push_back(ll[i]);
		return ans;
	}
};
