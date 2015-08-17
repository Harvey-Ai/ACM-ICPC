#include <iostream>
using namespace std;

int mmin[100005][26];
char arr[200005];

int main()
{
	int i, j;
	int n, len;
	int ll;
	int minl;
	long long ff;
	cin>>n>>len;
	cin>>arr;

	for(j = 0;j < 26;j++)
		if (j == arr[0] - 'a')
			mmin[0][j] = 0;
		else
			mmin[0][j] = -1;
	for(i = 1;i < len;i++)
	{
		for(j = 0;j < 26;j++)
			if (j == arr[i] - 'a')
				mmin[i][j] = 0;
			else
			{
				if (mmin[i - 1][j] != -1)
					mmin[i][j] = mmin[i - 1][j] + 1;
				else
					mmin[i][j] = -1;
			}
	}

	mmin[len - 1][arr[len - 1] - 'a'] = 0;
	for(i = len - 2;i >= 0;i--)
	{
		for(j = 0;j < 26;j++)
			if (j == arr[i] - 'a')
				mmin[i][j] = 0;
			else
			{
				if (mmin[i + 1][j] != -1)
				{
					if (mmin[i][j] > mmin[i + 1][j] + 1 || mmin[i][j] == -1)
						mmin[i][j] = mmin[i + 1][j] + 1;
				}
			}
	}

//	printf("ss%d\n", min[1]['o' - 'a']);
	for(i = 0;i < n;i++)
	{
		cin>>arr;
		ll = strlen(arr);
		if (len < ll)
			minl = len;
		else
			minl = ll;

		ff = 0;
		for(j = 0;j < minl;j++)
		{
//			printf("%d\n", min[j][arr[j] - 'a']);
			if (mmin[j][arr[j] - 'a'] != -1)
				ff += mmin[j][arr[j] - 'a'];
			else
				ff += ll;
		}
		for(j = len;j < ll;j++)
		{
			if (mmin[len - 1][arr[j] - 'a'] != -1)
				ff += mmin[len - 1][arr[j] - 'a'] + j - len + 1;
			else
				ff += ll;
		}
		cout<<ff<<endl;
	}
	return 0;
}
