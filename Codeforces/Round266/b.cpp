#include <iostream>
using namespace std;

int main()
{
	long long a, b, n;
	cin >> n >> a >> b;
	if (a * b >= 6 * n)
	{
		cout << a * b << endl;
		cout << a << " " << b << endl;
		return 0;
	}

	long long res = -1;
	long long newA, newB;
	for(long long i = 1;i * i <= 6 * n;i++)
	{
		long long edge1 = i;
		long long edge2 = (6 * n + i - 1) / i;

		if (res > edge1 * edge2 || res == -1)
		{
			if (a <= b)
			{
				if (edge1 >= a && edge2 >= b)
				{
					newA = edge1;
					newB = edge2;
					res = edge1 * edge2;
				}
			}
			else
			{
				if (edge1 >= b && edge2 >= a)
				{
					newB = edge1;
					newA = edge2;
					res = edge1 * edge2;
				}

			}
		}
	}

	cout << res << endl;
	cout << newA << " " << newB << endl;
	return 0;
}
