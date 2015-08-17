#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	long long n, m;
	long long k;
	cin >> n >> m >> k;

	long long l, r;
	l = 1;r = n * m;

	while(l <= r)
	{
		long long mid = (l + r) / 2;

		long long lessNum = 0;
		for(long long i = 1;i <= n;i++)
			lessNum += (mid / i) < m ? (mid / i) : m;
		if (lessNum >= k)
			r = mid - 1;
		else
			l = mid + 1;
	}
	cout << r + 1 << endl;
	return 0;
}
