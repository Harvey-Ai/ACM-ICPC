#include <iostream>
using namespace std;

int arr[100005];
int main()
{
	int n;
	cin >> n;
	for(int i = 0;i < n;i++)
		cin >> arr[i];

	int begin = -1, end = -1;
	int flag = 0;
	int ok = 1;

	for(int i = 1;i < n;i++)
	{
		if (arr[i] < arr[i - 1])
		{
			if (begin == -1)
			{
				begin = i - 1;
				end = i;
			}
			else
			{
				if (flag)
				{
					ok = 0;
					break;
				}
				end = i;
			}
		}
		else if (arr[i] > arr[i - 1])
		{
			if (begin != -1)
				flag = 1;
		}
	}

	if (begin > 0 && arr[begin - 1] > arr[end])
		ok = 0;
	if (end < n - 1 && arr[end + 1] < arr[begin])
		ok = 0;	

	if (ok)
	{
		cout << "yes" << endl;	
		if (begin == -1)
			cout << 1 << " " << 1<< endl;
		else
			cout << begin + 1 << " " << end + 1 <<  endl;
	}
	else
		cout << "no" << endl;

	return 0;
}
