#include <stdio.h>
#include <stdlib.h>
#define N 110000

struct card
{
	int ind;
	int bg, len;
};

struct card cd[N];
int dp[N];
int res[N];

int cmp(const void *a, const void *b)
{
	struct card *aa = (struct card *)a;
	struct card *bb = (struct card *)b;
	return aa->bg - bb->bg;
}


int main()
{
	int i, j;
	int n;
	int end;
	scanf("%d", &n);
	for(i = 0;i < n;i++)
	{
		scanf("%d %d", &cd[i].bg, &cd[i].len);
		cd[i].ind = i;
	}

	qsort(cd, n, sizeof(cd[0]), cmp);


	dp[n - 1] = n - 1;
	res[cd[n - 1].ind] = 1;

	for(i = n - 2;i >= 0;i--)
	{
		end = cd[i].bg + cd[i].len;
		for(j = i + 1;j < n;j++)
			if (end <= cd[j].bg)
			{
				dp[i] = j - 1;
				break;
			}
			else
			{
				// must the first over-segment one
				if (cd[j].bg + cd[j].len >= end)
				{
					dp[i] = dp[j];
					break;
				}
				j = dp[j];
			}
		// caution!
		if (j >= n)
			dp[i] = n - 1;

		res[cd[i].ind] = dp[i] - i + 1;
	}

	for(i = 0;i < n - 1;i++)
		printf("%d ", res[i]);
	printf("%d\n", res[n - 1]);

	return 0;
}
