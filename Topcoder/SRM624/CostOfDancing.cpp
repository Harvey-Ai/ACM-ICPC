#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class CostOfDancing {
	public:
	int minimum(int K, vector <int> danceCost) {
		int res = 0;
		sort(danceCost.begin(), danceCost.end());
		for(int i = 0;i < K;i++)
			res += danceCost[i];
		return res;
	}
};
