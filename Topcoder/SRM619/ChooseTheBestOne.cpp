#include <string>
#include <vector>
#include <iostream>
using namespace std;
class ChooseTheBestOne {
	public:
	int countNumber(int N) {
		int qu[5005];
		
		for(int i = 0;i < N;i++)
			qu[i] = i + 1;

		long long pos = 0;
		for(long long i = 1;i < N;i++)
		{
		
			long long newPos =  ((long long)(pos + i * i * i - 1)) % (long long)(N - i + 1);
			for(int j = newPos;j < N - i;j++)
				qu[j] = qu[j + 1];
			if (newPos == N - i)
				pos = 0;
			else
				pos = newPos;
		}
		return qu[0];
	}
};
