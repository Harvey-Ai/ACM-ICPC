/*
You are given a regular n-gon. Your task is to calculate two values: the number of its diagonals that are parallel to at least one of its other diagonals, and the number of its diagonals that are perpendicular to at least one of its diagonals. A diagonal is a segment connecting two non-adjacent polygon vertices.
Input
The only line contains an integer n (4 ≤ n ≤ 105).
Output
Output two required numbers.

Sample Input
input
4
output
0 2

*/

#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
    long long sum = 180 * n;
    int flag = 0;
    if (sum % 360 == 0 && sum / 360 >= 2 && sum / 360 <= n)
        flag = 1;
    long long a = 0, b = 0;
	for (int i = 2;i <= n / 2;i++)
	{
		int num = n;
		if (i * 2 == n)
			num = n / 2;
        if (i + 3 < n)
            a += num;
		if (flag)
			b += num;
        
        sum += 2 * (n - 2) * 180;
        if (sum % 360 == 0 && sum / 360 >= 2 && sum / 360 <= n)
            flag = 1;
	}

	printf("%lld %lld\n", a, b);
	return 0;
}
