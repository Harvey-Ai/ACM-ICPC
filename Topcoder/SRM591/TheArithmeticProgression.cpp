#line 65 "TheArithmeticProgression.cpp"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class TheArithmeticProgression {
	public:
	double minimumChange(int a, int b, int c) {
		
		double res = 2 * b - a - c;
		if (res < 0)
			res = -res;
		return res / 2;
	}
};
