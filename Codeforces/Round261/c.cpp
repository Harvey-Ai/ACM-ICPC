#include <iostream>
using namespace std;

int sit[1005][1005];
int main()
{
	
	int n, d;
	long long k;
	
	long long temp = n;
	for(int i = 0;i < d;i++)
	{
		temp /= k;
		
	}
	if (temp >= 2)
	{
		cout << -1 << endl;
		return 0;
	}
	
	for(int i = 1;i < n;i++)
		sit[0][i] = 1;

	int flag[1005];
	memset(flag, 0, sizeof(flag));
	flag[0] = 1;
	flag[n + 1] = 1;
	int cir = n;
	for(int i = 1;i <= d;i++)
	{
		for(int j = 0;j
	}

	return 0;
}
