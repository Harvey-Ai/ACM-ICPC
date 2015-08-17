#include <string>
#include <vector>
#include <iostream>
using namespace std;
class AddMultiply {
	public:
	vector <int> makeExpression(int y) {
		vector<int> res(3);

		for(res[0] = -1000;res[0] <= 1000;res[0]++)
			for(res[1] = -1000;res[1] <= 1000;res[1]++)
				for(res[2] = -1000;res[2] <= 1000;res[2]++)
				{
					if (res[0] == 0 || res[1] == 0 || res[2] == 0 ||
						res[0] == 1 || res[1] == 1 || res[2] == 1)
						continue;
					if (res[0] * res[1] + res[2] == y)
						return res;
				}
		return res;
	}

};
