#include <string>
#include <vector>
#include <iostream>
using namespace std;
class BigFatInteger {
	
	int primes[10005];
	int primesNum;
	void getP()
	{
		primesNum = 1;
		primes[0] = 2;
		for(int i = 3;i < 10005;i += 2)
		{
			int j;
			for(j = 2;j * j <= i;j++)
				if (i % j == 0)
					break;
			if (j * j > i)
				primes[primesNum++] = i;
		}
	}
	public:
	int minOperations(int A, int B) {
		getP();

		int maxSameF = 1;
		int factorN = 0;
		for(int i = 0;i < primesNum && A > 1;i++)	
		{
			int temp = 0;
			while(A % primes[i] == 0)
			{
				temp++;
				A /= primes[i];
			}
			if (temp > 0)
				factorN++;
			if (temp > maxSameF)
				maxSameF = temp;
		}
		int res = factorN;
		if (A > 1)
			res++;
		int temp = 1;
		while(temp < maxSameF * B)
		{
			temp *= 2;
			res++;
		}
		return res;
	}
};
