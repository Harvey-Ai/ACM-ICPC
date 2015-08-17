// BEGIN CUT HERE

// END CUT HERE
#line 5 "CarrotBoxesEasy.cpp"
#include <string>
#include <vector>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std ;
class CarrotBoxesEasy {
	public:
	int theIndex(vector <int> carrots, int k) {
		int n = carrots.size();
		int i, j;
		int num = 0, max = 0;

		for(i = 0;i < k;i++)
		{
			num = -1;
			max = 0;
			for(j = 0;j < n;j++)
				if (carrots[j] > max)
				{
					num = j;
					max = carrots[j];
				}
			carrots[num]--;
		}
		return num;
	}
};
