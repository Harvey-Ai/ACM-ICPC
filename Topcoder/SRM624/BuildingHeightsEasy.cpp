#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;
class BuildingHeightsEasy {
	public:
		int base_floors;
		bool cmp(int a, int b)
		{
			if (a <= base_floors && b <= base_floors)
			{
				if (abs(a - base_floors) < abs(b - base_floors))
					return 1;
				else
					return 0;
			}
			else if (a <= base_floors && b > base_floors)
				return 1;
			else
				return 0;
		}
		int minimum(int M, vector <int> heights) {
			vector<int> bds;
			for(int i = 0;i < heights.size();i++)
				bds.push_back(heights[i]);

			sort(heights.begin(), heights.end());
			bool (*p)(int a, int b);
			p = cmp;
			int ans = -1;
			for(int i = M - 1;i < heights.size();i++)
			{
				int sol = 0;
				base_floors = heights[i];
				sort(bds.begin(), bds.end(), p);
				for(int j = 0;j < M;j++)
					sol += abs(bds[j] - base_floors);
				if (sol < ans || ans == -1)
					ans = sol;
			}
			return ans;
		}
};

int main()
{
	return 0;
}
