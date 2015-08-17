/*
In the television program "Shopping Street" of CCTV-2, two people, A and B are guessing price of a given item. You are asked to decide whose price is closer to the real price.

Input

There are multiple test cases. The first line of input is an integer T (T <= 10) indicating the number of test cases.

Each case contains three integers in one line: P, PA, PB (0 <= PA, PB <= P <= 100, PA != PB), indicating the real price, the price A guesses and the price B guesses.

Output

For each case, output "A" or "B" according to whose price is closer to the real price.

Sample Input

3
10 8 7
20 20 19
100 9 50
Sample Output

A
A
B
*/

#include <stdio.h>
#include <math.h>

int main()
{
	int n, p1, p2, p, dis1, dis2;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d %d %d", &p, &p1, &p2);
		dis1 = fabs(p - p1);
		dis2 = fabs(p - p2);

		dis1 < dis2 ? printf("A\n") : printf("B\n");
	}
	return 0;
}
