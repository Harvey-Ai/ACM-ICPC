#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	if (m == 0)
	{
		cout << "1 0" << endl;
		cout << n << " " << 0 << endl;
		cout << "0 0" << endl;
		cout << n - 1 << " " << 0 << endl;
		return 0;
	}
	if (n == 0)
	{
		cout << "0 1" << endl;
		cout << 0 << " " << m << endl;
		cout << "0 0" << endl;
		cout << 0 << " " << m - 1 << endl;
		return 0;
	}
	
	int res1 = (n * n + (m - 1) * (m - 1)) * 2;
	int res2 = (m * m + (n - 1) * (n - 1)) * 2;
	int res12 = n * n + (m - 1) * (m - 1) + n * n + (m - 2) * (m - 2);
	int res22 = m * m + (n - 1) * (n - 1) + m * m + (n - 2) * (n - 2);

	if (res1 >= res2 && res1 >= res12 && res1 >= res22)
	{
		cout << "0 1" << endl;
		cout << n << " " << m << endl;
		cout << "0 0" << endl;
		cout << n << " " << m - 1 << endl;
	}
	else if (res2 >= res1 && res2 >= res12 && res2 >= res22)
	{
		cout << "1 0" << endl;
		cout << n << " " << m << endl;
		cout << "0 0" << endl;
		cout << n - 1 << " " << m << endl;
	}
	else if (res12 >= res1 && res12 >= res2 && res12 >= res22)
	{
		cout << "0 0" << endl;
		cout << n << " " << m << endl;
		cout << "0 1" << endl;
		cout << n << " " << m - 1 << endl;
	}
	else if (res22 >= res1 && res22 >= res2 && res22 >= res12)
	{
		cout << "0 0" << endl;
		cout << n << " " << m << endl;
		cout << "1 0" << endl;
		cout << n - 1 << " " << m << endl;
	
	}
	return 0;

}
