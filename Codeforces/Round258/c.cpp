#include <iostream>
using namespace std;

int main()
{
	int caseNum;
	cin >> caseNum;
	while(caseNum--)
	{
		long long k, n, d1, d2;

		cin >> n >> k >> d1 >> d2;
		long long minW, midW, maxW;
		
		if (n % 3 != 0)
		{
			cout << "no" << endl;
			continue;
		}

		if ((k - d1 * 2 - d2) >= 0 &&
			(k - d1 * 2 - d2) % 3 == 0)
		{
			minW = (k - d1 * 2 - d2) / 3;
			midW = minW + d1;
			maxW = midW + d2;
			if (maxW <= n / 3)
			{
				cout << "yes" << endl;
				continue;
			}
		}

		if ((k - d2 * 2 - d1) >= 0 &&
			(k - d2 * 2 - d1) % 3 == 0)
		{
			minW = (k - d2 * 2 - d1) / 3;
			midW = minW + d2;
			maxW = midW + d1;
			
			if (maxW <= n / 3)
			{
				cout << "yes" << endl;
				continue;
			}
		}
		if ((k - d1 - d2) >= 0 &&
			(k - d2 - d1) % 3 == 0)
		{
			minW = (k - d2 - d1) / 3;
			midW = minW + d2;
			maxW = minW + d1;
			
			if (maxW <= n / 3 && midW <= n / 3)
			{
				cout << "yes" << endl;
				continue;
			}
		}
		if ((k + d2 + d1) % 3 == 0)
		{
			maxW = (k + d2 + d1) / 3;
			midW = maxW - d1;
			minW = maxW - d2;
			
			if (midW >= 0 && minW >= 0 && maxW <= n / 3)
			{
				cout << "yes" << endl;
				continue;
			}
		}
		cout << "no" << endl;
	}
	return 0;
}
