#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
class LittleElephantAndIntervalsDiv1 {
	public:
	long long getNumber(int M, vector <int> L, vector <int> R) {
		int flag[1001];
		for(int i = 0;i < 1001;i++)
			flag[i] = 0;
		int cIndex = 1;

		for(int i = 0;i < L.size();i++)
		{
			for(int j = L[i];j <= R[i];j++)
				flag[j] = cIndex;
			cIndex++;
		}

		set<int> colors;
		for(int i = 1;i <= M;i++)
			if (flag[i] != 0)
				colors.insert(flag[i]);

		long long res = 1;
		for(int i = 0;i < colors.size();i++)
			res *= 2;
		return res;
	}
};
