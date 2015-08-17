#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class LittleElephantAndPermutationDiv2 {
	public:
		int check(vector<int> &p)
		{
			int temp = 0;
			for(int i = 0;i < p.size();i++)
				temp += p[i] > (i + 1) ? p[i] : (i + 1);
			return temp;
		}

		long long getNumber(int N, int K) {
			long long res = 0;
			int permunationNum = 1;
			for(int i = 1;i <= N;i++)
				permunationNum *= i;

			vector<int> permunation;
			for(int i = 0;i < N;i++)
				permunation.push_back(i + 1);
			do
			{
				if (check(permunation) >= K)
					res += permunationNum;
			}while (next_permutation(permunation.begin(), permunation.end()));
			return res;
		}
};
