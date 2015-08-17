#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	int day = 1;
	while(n)
	{
		n--;
		if (day % m == 0)
			n++;
		day++;
	}
	cout << day - 1 << endl;
	return 0;
}
