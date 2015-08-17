#include <iostream>
using namespace std;

int main()
{
	long long l, r, k;
	cin >> l >> r >> k;

	if (k == 1)
	{
		cout << l << endl;
		cout << 1 << endl;
		cout << l << endl;
		return 0;
	}
	if (k == 2)
	{
		if (l == 1)
		{
			cout << 0 << endl;
			cout << 1 << endl;
			cout << 1 << endl;
		}
		else
		{
			cout << 1 << endl;
			cout << 2 << endl;
			cout << l << " " << l + 1 << endl;
		}
		return 0;
	}
	if (k == 3)
	{
		if (l == 1)
		{
			cout << 0 << endl;
			cout << 3 << endl;
			cout << 1 << " " << 2 << " " << 3 << endl;
		}
		else
		{
			cout << 1 << endl;
			cout << 2 << endl;
			cout << l << " " << l + 1 << endl;
		}
		return 0;
	}
	else
	{
		cout << 0 << endl;
		if (l > 1)
		{
			cout << 4 << endl;
			cout << l << " " << l + 1 << " " << l + 2 << " " << l + 3 << endl;
		}
		else
		{
			cout << 3 << endl;
			cout << "1 2 3" << endl;
		}
	}
	return 0;
}
