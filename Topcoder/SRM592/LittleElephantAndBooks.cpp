#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool cmp(const int a, const int b)
{
	return a <= b ? 1 : 0;
}

class LittleElephantAndBooks {
	public:
	int getNumber(vector <int> pages, int number) {
		int len = pages.size();
		sort(&pages[0], &pages[len], cmp);

		int res = 0;

		for(int i = 0;i < number - 1;i++)
			res += pages[i];
		res += pages[number];
		return res;
	}
};
