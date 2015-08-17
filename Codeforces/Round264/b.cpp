#include <iostream>
using namespace std;

int main()
{
	int n;
	int max = 0;
	cin >> n;
	for(int i = 0;i < n;i++)
	{
		int a;
		cin >> a;
		if (a > max)
			max = a;
	}
	cout << max << endl;
	
	return 0;
}
