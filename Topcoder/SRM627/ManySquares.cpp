#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class ManySquares {
	public:
	int howManySquares(vector <int> sticks) {
		sort(sticks.begin(), sticks.end());

		int res = 0;
		int sn = 1;
		for(int i = 1;i < sticks.size();i++)
		{
			if (sticks[i] == sticks[i - 1])
				sn++;
			else
			{
				res += sn / 4;
				sn = 1;
			}
		}
		res += sn / 4;
		return res;
	}
};
