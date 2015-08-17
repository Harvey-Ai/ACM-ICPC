#include <iostream>
using namespace std;

int main()
{
	int n, s;
	cin >> n >> s;

	int res = - 1;
	for(int i = 0;i < n;i++)
	{
		int a, b;
		cin >> a >> b;
		
		if (s > a)
		{
			int left = 100 - b;
			if (b == 0)
				left = 0;
			if (res < left)
				res = left;
		}
		else if (s == a && b == 0)
		{
			if (res < 0)
				res = 0;
		}
	}
	cout << res << endl;
	return 0;
}
