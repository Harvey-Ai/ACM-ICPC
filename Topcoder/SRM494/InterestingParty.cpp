// BEGIN CUT HERE

// END CUT HERE
#line 5 "InterestingParty.cpp"
#include <string>
#include <vector>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std ;
class InterestingParty {
	public:
	int bestInvitation(vector <string> first, vector <string> second) {
		map<string, int> interst;
		vector<string>::iterator it1, it2;
		int res;
		interst.clear();
		for(it1 = first.begin(), it2 = second.begin();it1 != first.end();it1++, it2++)
		{
			interst[*it1]++;
			interst[*it2]++;
			
		}
		res = 0;
		for(it1 = first.begin(), it2 = second.begin();it1 != first.end();it1++, it2++)
		{
			if (interst[*it1] >= res)
				res = interst[*it1];
			if (interst[*it2] >= res)
				res = interst[*it2];
		}
		return res;
	}
};
