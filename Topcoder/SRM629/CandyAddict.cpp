#line 98 "CandyAddict.cpp"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class CandyAddict {
	public:
	
	vector<long long> solve(vector <int> X, vector <int> Y, vector <int> Z) {
		vector<long long> res;
		
		for(int i = 0;i < X.size();i++)
		{
			if (X[i] == Y[i])
			{
				res.push_back(0);
				continue;
			}

			if (X[i] >= Y[i] * 2)
			{
				long long day = 1;
				long long money = X[i];

				while(day <= Z[i])
				{
					long long candyNum = money / Y[i];
					money %= Y[i];

					if (candyNum - 1 + day >= Z[i])
					{
						money += X[i] * (Z[i] - day);
						day = Z[i] + 1;
					}
					else
					{
						day += candyNum;
						money += candyNum * X[i];
					}
				}
				res.push_back(money);
			}
			else
			{
				long long duration = 1;
				long long oneSave = X[i] - Y[i];
				long long day = 1;
				long long leftMoney = 0;	
				
				while(day <= Z[i])
				{
					long long cir = (Y[i] - (leftMoney + X[i] - duration * Y[i]) + duration * oneSave - 1) / (duration * oneSave);

					if (duration * cir + day > Z[i])
					{
						long long leftCandy = duration - ((long long)Z[i] - day) % duration - 1;
						res.push_back((long long)Z[i] * ((long long)X[i] - (long long)Y[i]) - leftCandy * Y[i]);
						break;
					}
					else
					{
						day += duration * cir;
						duration = (day * (X[i] - Y[i]) + Y[i]) / Y[i];
						leftMoney = (day - 1) * (X[i] - Y[i]);
					}
				}
			}
		}

		return res;
	}
};
