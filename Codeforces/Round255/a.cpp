#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int p, n;
	int flag[305];
	int res = -1;
	memset(flag, 0, sizeof(flag));

	cin >> p >> n;
	for(int i = 0;i < n;i++)
	{
		int a;
		cin >> a;
		a = a % p;
		if (!flag[a])
			flag[a] = 1;
		else if (res == -1)
			res = i + 1;
	}
	cout << res << endl;
	return 0;
}
