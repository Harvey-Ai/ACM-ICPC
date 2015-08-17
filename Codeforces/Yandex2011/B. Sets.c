#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;

int gg[202][202];
int flag[202];
int has[202];
vector< set <int> > res;

void out()
{
	int i;
	for(i = 0;i < res.size();i++)
	{
		printf("%d", res[i].size());
		set <int>::iterator it;
		for(it = res[i].begin();it != res[i].end();it++)
			printf(" %d", *it);
		putchar('\n');
	}
}

int main()
{
	int n;
	int i, j, k;
	int N, K;
	int arr[202];
	set <int> temp;
	
	memset(gg, 0, sizeof(gg));
	scanf("%d", &n);
	N = n * (n - 1) / 2;

	memset(has, 0, sizeof(has));
	for(i = 0;i < N;i++)
	{
		scanf("%d", &K);
		for(j = 0;j < K;j++)
		{
			scanf("%d", &arr[j]);
			has[arr[j]] = 1;
		}

		for(k = 0;k < 202;k++)
			flag[k] = -1;
		for(k = 0;k < K;k++)
			flag[arr[k]] = 1;

		for(j = 0;j < K;j++)
			for(k = 0;k < 202;k++)
			{
				if (flag[k] == -1)
					gg[arr[j]][k] = gg[k][arr[j]] = -1;
				else if (gg[arr[j]][k] != -1 && gg[k][arr[j]] != -1)
						gg[arr[j]][k] = 1;
			}
	}

	if (n <= 2)
	{
		temp.clear();
		for(i = 1;i < 202;i++)
			if (has[i])
			{
				temp.insert(i);
				res.push_back(temp);
				i++;
				break;
			}
	
		temp.clear();
		for(;i < 202;i++)
			if (has[i])
				temp.insert(i);
		res.push_back(temp);
		out();
		return 0;
	}

	for(i = 1;i < 202;i++)
	{
		if (!has[i])
			continue;

		has[i] = 0;
		temp.clear();
		temp.insert(i);
		
		for(j = 1;j < 202;j++)
			if (gg[i][j] == 1 && has[j])
			{
				has[j] = 0;
				temp.insert(j);
			}
		res.push_back(temp);
	}

	out();
	return 0;
}
