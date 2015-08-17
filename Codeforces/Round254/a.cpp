#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	char chess[105][105];
	char res[105][105];
	for(int i = 0;i < 105;i++)
	{
		if (i % 2)
			res[i][0] = 'B';
		else
			res[i][0] = 'W';
		for(int j = 1;j < 105;j++)
		{
			if (res[i][j - 1] == 'B')
				res[i][j] = 'W';
			else
				res[i][j] = 'B';
		}
	}
	int n, m;

	cin >> n >> m;
	for(int i = 0;i < n;i++)
		cin >> chess[i];

	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < m;j++)
			if (chess[i][j] == '-')
				putchar('-');
			else
				putchar(res[i][j]);
		cout << endl;
	}

	return 0;
}
