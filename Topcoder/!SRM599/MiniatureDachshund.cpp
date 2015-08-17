#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class MiniatureDachshund {
	public:
	int maxMikan(vector <int> mikan, int weight) {
		int leftW = 5000 - weight;
		sort(&mikan[0], &mikan[mikan.size()]);
		int i = 0;
		for(i = 0;i < mikan.size();i++)
			if (leftW - mikan[i] >= 0)
				leftW -= mikan[i];
			else
				break;
		return i;
	}
};
