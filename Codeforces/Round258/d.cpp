#include <iostream>
#include <string>
using namespace std;

int main()
{
	int a[2];
	int b[2];
	a[0] = a[1] = 0;
	b[0] = b[1] = 0;

	long long oddRes = 0, evenRes = 0;
	string str;
	cin >> str;
	for(int i = 0;i < str.size();i++)
	{
		if (i % 2 == 0)
		{
			if (str[i] == 'a')
			{
				a[0]++;
				oddRes += a[0];
			    evenRes += a[1];
			}
			else
			{
				b[0]++;
				oddRes += b[0];
				evenRes += b[1];
			}
		}
		else
		{
			if (str[i] == 'a')
			{
				a[1]++;
				oddRes += a[1];
			    evenRes += a[0];
			}
			else
			{
				b[1]++;
				oddRes += b[1];
				evenRes += b[0];
			}
		}
	}
	cout << evenRes << " " << oddRes << endl;
	return 0;
}
