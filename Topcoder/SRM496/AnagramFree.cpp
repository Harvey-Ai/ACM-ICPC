// BEGIN CUT HERE

// END CUT HERE
#line 5 "AnagramFree.cpp"
#include <string>
#include <vector>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std ;
bool cmmp(const string &a, const string &b)
{
	if (a.compare(b) > 0)
		return 1;
	else
		return 0;
}
class AnagramFree {
	public:

	int getMaximumSubset(vector <string> S) {
		int i = 0;
		int ans;
		for(i = 0;i < S.size();i++)
			sort(&(S[i][0]), &S[i][S[i].size()]);

		sort(S.begin(), S.end(), cmmp);
 
		ans = 1;
		for(i = 1;i < S.size();i++)
			if (S[i] != S[i - 1])
				ans++;
		return ans;
	}
};
