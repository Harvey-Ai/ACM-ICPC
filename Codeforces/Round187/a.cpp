#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;


int main()
{
	int n;
	int arr[105], brr[105];
	cin >> n;
	for(int i = 0;i < n;i++)
		cin >> arr[i] >> brr[i];

	int flag[105] = {0};
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
		{
			if (i == j)
				continue;
			if (arr[j] == brr[i])
				flag[j] = 1;
		}

	int res = n;
	for(int i = 0;i < n;i++)
		res -= flag[i];
	printf("%d\n", res);
	return 0;
}


