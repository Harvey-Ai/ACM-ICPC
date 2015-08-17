#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class IncrementingSequence {
	public:
	string canItBeDone(int k, vector <int> A) {
		vector<int> flag(52);
		for(int i = 0;i < 52;i++)
			flag[i] = 0;
		sort(A.begin(), A.end());

		for(int i = 0;i < A.size();i++)
		{
			int next = A[i];
			while(next <= 50 && flag[next])
				next += k;

			if (next <= 50)
				flag[next] = 1;
		}

		for(int i = 1;i <= A.size();i++)
			if (flag[i] == 0)
				return "IMPOSSIBLE";

		return "POSSIBLE";
	}
};
