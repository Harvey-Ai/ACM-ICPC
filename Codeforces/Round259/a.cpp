#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n;
	cin >> n;
	char arr[105][105];

	int SNum = (n - 1) / 2;
	for(int i = 0;i < n / 2;i++)
	{
		for(int j = 0;j < SNum;j++)
			arr[i][j] = '*';
		for(int j = SNum;j < n - SNum;j++)
			arr[i][j] = 'D';
		for(int j = n - SNum;j < n;j++)
			arr[i][j] = '*';
		arr[i][n] = '\0';
		SNum--;
	}
	SNum = 0;
	for(int i = n / 2;i < n;i++)
	{
		for(int j = 0;j < SNum;j++)
			arr[i][j] = '*';
		for(int j = SNum;j < n - SNum;j++)
			arr[i][j] = 'D';
		for(int j = n - SNum;j < n;j++)
			arr[i][j] = '*';
		arr[i][n] = '\0';
		SNum++;
	}
	for(int i = 0;i < n;i++)
		printf("%s\n", arr[i]);
	return 0;
}
