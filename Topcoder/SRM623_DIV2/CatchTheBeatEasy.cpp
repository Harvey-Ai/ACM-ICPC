#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

class CatchTheBeatEasy {
	
	public:
		struct ballType
		{
			int x, y;
		};
	static bool cmp(const ballType a, const ballType b)
	{
		if (a.y <= b.y)
			return 1;
		else
			return 0;
	}

	string ableToCatchAll(vector <int> x, vector <int> y) {
		vector<ballType> balls;
		ballType oneBall;

		oneBall.x = 0;
		oneBall.y = 0;
		balls.push_back(oneBall);
		for(int i = 0;i < x.size();i++)
		{
			oneBall.x = x[i];
			oneBall.y = y[i];
			balls.push_back(oneBall);
		}
		sort(balls.begin(), balls.end(), cmp);

		for(int i = 0;i < balls.size() - 1;i++)
		{
			if (fabs(balls[i + 1].y - balls[i].y) < fabs(balls[i + 1].x - balls[i].x))
				return "Not able to catch";
		}
		return "Able to catch";
	}
};
