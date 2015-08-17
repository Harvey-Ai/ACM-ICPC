// BEGIN CUT HERE

// END CUT HERE
#line 5 "PrimeContainers.cpp"
#include <string>
#include <vector>
using namespace std;

class PrimeContainers {
	public:
	int isPrime(int a)
	{
		int i;
		if (a == 1)
			return 0;
		for(i = 2;i * i <= a;i++)
			if (a % i == 0)
				return 0;
		return 1;
	}
	int containerSize(int N) {
		int res = 0;
		while(N)
		{
			if (isPrime(N))
				res++;
			N /= 2;
		}
		return res;
	}
};

// BEGIN CUT HERE
int main()
{
        PrimeContainers ___test;
        ___test.run_test(-1);

		system("pause");

        return 0;
}
// END CUT HERE
