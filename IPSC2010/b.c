#include <stdio.h>
#include <math.h>
#define ESP 10E-10
#define DIS(a1, b1, a2, b2) sqrt(((a1) - (a2)) * ((a1) - (a2)) + ((b1) - (b2)) * ((b1) - (b2)))

int main()
{
	double x1, y1, x2, y2;
	double p, q, r;
	double min, temp;
	double interP[10][2];
	double dist[10];
	int hasP[10];

	int interN;
	int ncase;
	int i, j;

	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	scanf("%d", &ncase);

	while(ncase--)
	{
		scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
		scanf("%lf %lf %lf", &p, &q, &r);

		interN = 0;
		memset(hasP, 0, sizeof(hasP));
	
		if (q - 0 > ESP || q - 0 < -ESP)
		{
			interP[interN][0] = x1;
			interP[interN][1] = (r - p * x1) / q;
			dist[interN] = fabs(y1 - interP[interN][1]);
			hasP[interN] = 1;
			interN++;

		}
		if (p - 0 > ESP || p - 0 < -ESP)
		{
			interP[interN][0] = (r - q * y1) / p;
			interP[interN][1] = y1;
			dist[interN] = fabs(x1 - interP[interN][0]);
			hasP[interN] = 1;
			interN++;
		}

		if (q - 0 > ESP || q - 0 < -ESP)
		{
			interP[interN][0] = x2;
			interP[interN][1] = (r - p * x2) / q;
			dist[interN] = fabs(y2 - interP[interN][1]);
			hasP[interN] = 1;
			interN++;
		}
		if (p - 0 > ESP || p - 0 < -ESP)
		{
			interP[interN][0] = (r - q * y2) / p;
			interP[interN][1] = y2;
			dist[interN] = fabs(x2 - interP[interN][0]);
			hasP[interN] = 1;
			interN++;
		}

		min = -1;
		for(i = 0;i < 2;i++)
			for(j = 2;j < 4;j++)
				if (hasP[i] && hasP[j])
				{
					temp = DIS(interP[i][0], interP[i][1], interP[j][0], interP[j][1]) + dist[i] + dist[j];
					if (temp < min || min == -1)
						min = temp;
				}
		if (min - fabs(x1 - x2) - fabs(y1 - y2) > ESP)
			min = fabs(x1 - x2) + fabs(y1 - y2);
		printf("%0.10lf\n", min);
	}
	return 0;
}
