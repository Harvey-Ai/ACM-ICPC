#include <stdio.h>
#include <algorithm>
using namespace std;

struct ventor
{
	int lo;
	int num;
}pp[205];


bool cmp(const ventor &a, const ventor &b)
{
	if (a.lo < b.lo)
		return 1;
	else
		return 0;
}

int main()
{
	int ncase;
	int icase;
	int left, right, ld, rd;
	int center;
	int i, j;
	int ln, rn;
	double max, temp;
	double cp;
	int num;
	int d, c;

	scanf("%d", &ncase);

	for(icase = 1;icase <= ncase;icase++)
	{
		scanf("%d %d", &c, &d);
		for(i = 0;i < c;i++)
			scanf("%d %d", &pp[i].lo, &pp[i].num);

		sort(&pp[0], &&pp[c], cmp);

		sum = 0;
		num = 0;
		for(i = 0;i < c;i++)
		{
			sum += pp[i].num * pp[i].lo;
			num + pp[i].num;
		}

		cp = sum / num;
	
		for(center = 0;center < c;center++)
		{
			ln = (pp[center].num - 1) / 2;

			for(j = center - 1;j >= 0;j--)
				ln += pp[j].num;
			left = cp - ln * d;
			for(j = 0;j >= center - 1;j++)
			{
				if (pp[center].lo <= left)
					temp = (pp[j] / 2) * d;
				else
				{
					rd = left + pp[j].num * d;
					temp = pp[j].lo - left;
					if (temp < abs(pp[j].lo - rd))
						temp = abs(pp[j].lo - rd);
				}
				if (temp > max)
					max = temp;
				left = left - pp[j].num * d;
			}

			rn = pp[center].num - 1 - ln;
			for(j = center + 1;j < n;j++)
				rn += pp[j].num;
			left = pp[center].lo + rn * d;
			for(j = center + 1;j < n;j++)
			{
				if (pp[center].lo >= right)
					temp = (pp[j] / 2) * d;
				else
				{
					ld = right - pp[j].num * d;
					temp = right - pp[j].lo;
					if (temp < abs(pp[j].lo - ld))
						temp = abs(pp[j].lo - ld);
				}
				if (temp > max)
					max = temp;
				right += pp[j].num * d;
			}

			//
			ln = (pp[center].num) / 2;
			for(j = center - 1;j >= 0;j--)
				ln += pp[j].num;

			max = 0;
			left = cp - ln * d;
			for(j = 0;j >= center - 1;j++)
			{
				if (pp[center].lo <= left)
					temp = (pp[j] / 2) * d;
				else
				{
					rd = left + pp[j].num * d;
					temp = pp[j].lo - left;
					if (temp < abs(pp[j].lo - rd))
						temp = abs(pp[j].lo - rd);
				}
				if (temp > max)
					max = temp;
				left = left - pp[j].num * d;
			}

			rn = pp[center].num - 1 - ln;
			for(j = center + 1;j < n;j++)
				rn += pp[j].num;
			left = pp[center].lo + rn * d;
			for(j = center + 1;j < n;j++)
			{
				if (pp[center].lo >= right)
					temp = (pp[j] / 2) * d;
				else
				{
					ld = right - pp[j].num * d;
					temp = right - pp[j].lo;
					if (temp < abs(pp[j].lo - ld))
						temp = abs(pp[j].lo - ld);
				}
				if (temp > max)
					max = temp;
				right += pp[j].num * d;
			}
		}
		printf("Case #%d: %.6g\n", icase, max);
	}
	return 0;
}
