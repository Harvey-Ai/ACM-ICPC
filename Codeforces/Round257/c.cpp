#include <iostream>
using namespace std;

int main()
{
	long long m, n, k;
	cin >> n >> m >> k;

	if (k > m - 1 + n - 1)
	{
		cout << -1 << endl;
		return 0;
	}

	long long res = -1;
	if (k > m - 1)
	{
		if (res == -1 || res < 1 * (n / (k - (m - 1) + 1)))
			res = 1 * (n / (k - (m - 1) + 1));
	}
	else
	{
		if (res == -1 || res < (m / (k + 1)) * n)
			res = (m / (k + 1)) * n;
	}
	
	if (k > n - 1)
	{
		if (res == -1 || res < 1 * (m / (k - (n - 1) + 1)))
			res = 1 * (m / (k - (n - 1) + 1));
	}
	else
	{
		if (res == -1 || res < (n / (k + 1)) * m)
			res = (n / (k + 1)) * m;
	}

	cout << res << endl;

	return 0;
}
