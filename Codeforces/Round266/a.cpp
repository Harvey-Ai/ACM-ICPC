#include <iostream>
using namespace std;

int main()
{
	int n, m, a, b;
	cin >> n >> m >> a >> b;

	if (a * m > b)
	{
		int res = (int)(n / m) * b + (n % m) * a;
		if (res > ((n + m - 1) / m) * b)
			res = ((n + m - 1) / m) * b;
		cout << res << endl;
	}
	else
		cout << a * n << endl;
	
	return 0;
}
