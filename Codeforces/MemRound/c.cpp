#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	double base = n * m * (n * m );

	double zi = (m * n) * ((m - 1) * n);

	double res = zi / base;

	res = 1 - res;
	printf("%.7lf\n", res);
	return 0;
}
