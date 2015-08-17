#include <string>
#include <vector>
#include <iostream>
using namespace std;
class TheShuttles {
	public:
	int getLeastCost(vector <int> cnt, int baseCost, int seatCost) {
		
		int res = -1;
		int seatNum;

		for(int i = 1;i < 101;i++)
		{
			seatNum = i;
			int temp = 0;
			for(int j = 0;j < cnt.size();j++)
			{
				int carNum = (cnt[j] + seatNum - 1) / seatNum;
				temp += carNum * baseCost;
				temp += carNum * seatNum * seatCost;
			}
			if (temp < res || res == -1)
				res = temp;
		}
		return res;
	}
};
