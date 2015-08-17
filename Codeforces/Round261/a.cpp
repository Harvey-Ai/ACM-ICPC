#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	if (x1 > x2)
	{
		swap(x1, x2);
		swap(y1, y2);
	}

	if (x1 != x2 && y1 != y2)
	{
		if (abs(x1 - x2) != abs(y1 - y2))
			cout << -1 << endl;
		else
			cout << x1 << " " << y2 << " " << x2 << " " << y1 << endl;
	}
	else
	{
		if (x1 == x2)
			cout << x1 + abs(y2 - y1) << " " <<  y1 << " " << x1 + abs(y2 - y1) << " " << y2 << endl;
		else
			cout << x1 << " " << y1 + abs(x2 - x1) << " " << x2 << " " << y2 + abs(x2 - x1) << endl;
	}
	return 0;
}
