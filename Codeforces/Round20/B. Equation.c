#include <stdio.h>
#include <math.h>

int main()
{
	double a, b, c;
	double res1, res2;

	scanf("%lf %lf %lf", &a, &b, &c);

	if (a == 0)
	{
		if (b == 0)
		{
			if (c == 0)
				printf("-1\n");
			else
				printf("0\n");
		}
		else
		{
			printf("1\n");
			printf("%.10lf\n", (-c) * 1.0 / b);
		}
	}
	else
	{
		if (b * b - 4 * a * c < 0)
			printf("0\n");
		else if (b * b - 4 * a * c == 0)
		{
			res1 = (-b) * 1.0 / (2 * a);
			printf("1\n");
			printf("%.10lf\n\n", res1);
		}
		else
		{
			res1 = (-b + sqrt(b * b - 4 * a * c)) * 1.0 / (2 * a);	
			res2 = (-b - sqrt(b * b - 4 * a * c)) * 1.0 / (2 * a);
			printf("2\n");
			if (res1 > res2)
				printf("%.10lf\n%.10lf\n", res2, res1);
			else
				printf("%.10lf\n%.10lf\n", res1, res2);
		}
	}
	return 0;
}
