#include <string>
#include <vector>
#include <iostream>
using namespace std;
class BigFatInteger2 {
	private:
		int primesNum;
		int primes[1000000];

	public:
	void getPrime()
	{
		primes[0] = 2;
		primesNum = 1;
		for(int i = 3;i < 100000;i++)
		{
			int j;
			for(j = 0;j < primesNum;j++)
				if (i % primes[j] == 0)
					break;
			if (j >= primesNum)
			{
				primes[primesNum] = i;
				primesNum++;
			}
		}		
	}
	string isDivisible(int A, int B, int C, int D) {
		int i = 0;

		int factorANum = 0;
		int factorBNum = 0;
		getPrime();
		while((A > 1 && C > 1) &&  i < primesNum)
		{
			factorANum = 0;
			while(A % primes[i] == 0)
			{
				factorANum ++;
				A /= primes[i];
			}

			factorBNum = 0;
			while(C % primes[i] == 0)
			{
				factorBNum++;
				C /= primes[i];
			}
			long long AD = (long long)factorANum * B;
			long long CD = (long long)factorBNum * D;
			if (AD < CD)
				return "not divisible";
			i++;
		}
		cout << "aaaaaaaaaa" << endl;
		if (C != 1 && A == 1)
			return "not divisible";
		else if (C != 1 && A != 1)
		{
			if (C != A)
				return "not divisible";
			else if (D > B)
				return "not divisible";
		}
		return "divisible";
	}
};
