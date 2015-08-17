#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int arr[105];
	for(int i = 0;i < n;i++)
		cin >> arr[i];

	int maxRound = 0;
	int res = -1;
	for(int i = 0;i < n;i++)
		if (maxRound <= (arr[i] + m - 1) / m)
		{
			maxRound = (arr[i] + m - 1) / m;
			res = i + 1;
		}
	cout << res << endl;
	return 0;
}
