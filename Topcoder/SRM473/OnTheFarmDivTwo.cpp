// BEGIN CUT HERE

// END CUT HERE
#line 5 "OnTheFarmDivTwo.cpp"
#include <string>
#include <vector>
using namespace std;

class OnTheFarmDivTwo {
	public:
	vector <int> animals(int heads, int legs) {
		int ch, cow;
		vector<int> res;
		res.clear();
		cow = (legs - 2 * heads) / 2;
		ch = heads - cow;
		if (cow >= 0 && ch >= 0 &&
			cow + ch == heads &&
			4 * cow + 2 * ch == legs)
		{
			res.push_back(ch);
			res.push_back(cow);
		}
		return res;
	}
};

// BEGIN CUT HERE
int main()
{
        OnTheFarmDivTwo ___test;
        ___test.run_test(-1);

           system("pause");

        return 0;
}
// END CUT HERE
