#include <iostream>
#include <cstdio>
using namespace std;

int arr[100005];
int main()
{
	int n;
	cin >> n;
	for(int i = 0;i < n;i++)
		scanf("%d", &arr[i]);

	int dropDown = 0;
	int dropIndex = n;
	for(int i = n - 2;i >= 0;i--)
		if (arr[i] > arr[i + 1])
		{
			dropDown = 1;
			dropIndex = i + 1;
			break;
		}

	int ok = 1;
	if (dropDown)
	{
		for(int i = 1;i < dropIndex;i++)
			if (arr[i] < arr[i - 1])
			{
				ok = 0;
				break;
			}
		for(int i = dropIndex;i < n - 1;i++)
			if (arr[i] > arr[i + 1])
			{
				ok = 0;
				break;
			}
		if (arr[n - 1] > arr[0])
			ok = 0;
	}
	else
	{
		for(int i = 0;i < n - 1;i++)
			if (arr[i] > arr[i + 1])
			{
				ok = 0;
				break;
			}
	}

	if (ok)
		printf("%d\n", n - dropIndex);
	else
		printf("-1\n");
	return  0;
}
