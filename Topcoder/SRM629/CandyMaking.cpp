#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
class CandyMaking {
	public:
	double findSuitableDensity(vector <int> containerVolume, vector <int> desiredWeight) {
		double res = -1;
		for(int i = 0;i < containerVolume.size();i++)
		{
			double temp = 0;
			for(int j = 0;j < containerVolume.size();j++)
			{
				if (j == i)
					continue;
				temp += fabs((1.0 * desiredWeight[i] * containerVolume[j]) / containerVolume[i] - desiredWeight[j]);
			}
			if (res == -1 || res > temp)
				res = temp;
		}
		return res;
	}
};
