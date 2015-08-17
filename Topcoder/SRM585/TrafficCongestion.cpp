#include <string>
#include <vector>
class TrafficCongestion {
	public:
	int theMinCars(int treeHeight) {

		long long res = 0;
		if (treeHeight % 2)
		{
			long long temp = 1;
			for(int i = 0;i < treeHeight;i += 2)
			{
				res += temp;
				while(res >= 1000000007)
					res -= 1000000007;
				temp *= 4;
				while(temp >= 1000000007)
					temp -= 1000000007;
			}
			return res;
		}
		else
		{	
			long long temp = 2;
			for(int i = 1;i < treeHeight;i += 2)
			{
				res += temp;
				while(res >= 1000000007)
					res -= 1000000007;
				temp *= 4;
				while(temp >= 1000000007)
					temp -= 1000000007;
			}
			res = (res + 1) % 1000000007;
			return res;

		}

	}
};
