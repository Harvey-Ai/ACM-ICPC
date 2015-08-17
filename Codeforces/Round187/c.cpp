#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

struct pp
{
	__int64 id, rating;
};
pp pps[200005];
int removed[200005];
int main()
{
	__int64 n;
	__int64 k;
	cin >> n >> k;
	for(int i = 0;i < n;i++)
	{
		cin >> pps[i].rating;
		pps[i].id = i + 1;
	}

	memset(removed, 0, sizeof(removed));
	int flag = 1;
	__int64 leftNum = n;
	int i = 0;
	int index=  0;
	__int64 sum = 0;
	while(flag)
	{
		flag = 0;
		for(;i < n;i++)
		{
			if (removed[i])
				continue;
			index++;
			if (index == 1)
				continue;

			__int64 d = sum - (leftNum - index) * (index - 1) * pps[i].rating;
			if (d < k)
			{
				printf("%d\n", i + 1);
				removed[i] = 1;
				flag = 1;
				index--;
				leftNum--;
				break;
			}
			else
				sum += pps[i].rating * (index - 1);

		}
	}
	return 0;
}
