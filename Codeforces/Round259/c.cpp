#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n, m;
	cin >> m >> n;

	double oneExp = 0;
	for(int i = 1;i <= m;i++)
		oneExp += i;
	oneExp /= m;

	printf("%.5lf\n", oneExp * n);
	return 0;
}
