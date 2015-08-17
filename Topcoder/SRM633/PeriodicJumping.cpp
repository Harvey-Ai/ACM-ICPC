#include <string>
#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;
class PeriodicJumping {
	public:
	int minimalTime(int x, vector <int> jumpLengths) {
		long long oneCirSum = 0;
		for(int i = 0;i < jumpLengths.size();i++)
			oneCirSum += jumpLengths[i];

		long long target = abs(x);
		long long minTime = (target / oneCirSum) * jumpLengths.size();
		long long sum = (minTime / jumpLengths.size()) * oneCirSum;
		long long big = -1;

		if (minTime)
		{
			for(int i = 0;i < jumpLengths.size();i++)
				if (big < jumpLengths[i])
					big = jumpLengths[i];
		}

		for(int i = 0;sum < target || (sum - big + target < big);i++)
		{
			if (i == jumpLengths.size())
				i = 0;
			sum += jumpLengths[i];

			if (big < jumpLengths[i])
				big = jumpLengths[i];
			minTime++;
		}

		return minTime;
	
	}
};
