#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
class DivisorsPower {
	public:
	long long getDivNum(long long a)
	{
		long long num = 0;
		long long i;
		for(i = 1;i * i < a;i++)
			if (a % i == 0)
				num += 2;

		if (i * i == a)
			num++;
		return num;
	}

	long long foundX(long long power, long long n)
	{
		long long low = 1;
		long long high = ceil(sqrt(n));
		while(low <= high)
		{
			long long mid = (low + high) / 2;
			long long powV = 1;
			for(int i = 0;i < power;i++)
			{
				if (n / mid >= powV)
					powV *= mid;
				else
				{
					powV = n + 1;
					break;
				}
			}
			if (powV > n)
				high = mid - 1;
			else if (powV < n)
				low = mid + 1;
			else
				return mid;
		}
		return -1;
	}

	long long findArgument(long long n) {
		for(int power = 2;power <= 60;power++)
		{
			long long x = foundX(power, n);
			if (x != -1 && getDivNum(x) == power)
				return x;
		}
		return -1;
	}
};
