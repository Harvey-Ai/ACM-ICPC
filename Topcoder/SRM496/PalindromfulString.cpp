// BEGIN CUT HERE

// END CUT HERE
#line 5 "PalindromfulString.cpp"
#include <string>
#include <vector>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std ;
class PalindromfulString {
	int mm, kk;
	long long ans;
	int nn;
	public:
	void dfs(char *str, int ii)
	{
		int i, j;
		int bg, ed;
		long long temp, cc;
		int big;
		int hw;
	
		if (ii >= nn)
		{
			temp = 1;
			hw = 0;
			for(i = mm - 1;i < nn;i++)
			{
				for(bg = i - mm + 1, ed = i;bg < ed;bg++, ed--)
					if (str[bg] != str[ed])
						break;
				if (bg >= ed)
					hw++;
			}
			if (hw >= kk)
				for(i = 1;i < nn;i++)
				{
					for(j = 0;j < i;j++)
						if (str[i] == str[j])
							break;
					if (j >= i)
						temp++;
				}
			else
				return;

			cc = 1;
			for(i = 26;temp >= 1;temp--, i--)
				cc *= i;
			ans += cc;
			return;
		}
	
		big = 0;
		for(i = 0;i < ii;i++)
			if (big < str[i] - 'A')
				big = str[i] - 'A';

		if (ii != 0)
		{
			str[ii] = big + 1 + 'A';
			dfs(str, ii + 1);
		}
		for(i = 0;i <= big;i++)
		{
			str[ii] = i + 'A';
			dfs(str, ii + 1);
		}
	}
	long long count(int N, int M, int K) {
		char str[20];

		mm = M;
		kk = K;
		nn = N;
		ans = 0;
		if (kk - 1 > nn - mm)
			return 0;
		dfs(str, 0);
		return ans;
	}
};
