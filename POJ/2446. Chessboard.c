/*
Description

Alice and Bob often play games on chessboard. One day, Alice draws a board with size M * N. She wants Bob to use a lot of cards with size 1 * 2 to cover the board. However, she thinks it too easy to bob, so she makes some holes on the board (as shown in the figure below). 


We call a grid, which doesn’t contain a hole, a normal grid. Bob has to follow the rules below: 
1. Any normal grid should be covered with exactly one card. 
2. One card should cover exactly 2 normal adjacent grids. 

Some examples are given in the figures below: 
 
A VALID solution.

 
An invalid solution, because the hole of red color is covered with a card.

 
An invalid solution, because there exists a grid, which is not covered.

Your task is to help Bob to decide whether or not the chessboard can be covered according to the rules above.
Input

There are 3 integers in the first line: m, n, k (0 < m, n <= 32, 0 <= K < m * n), the number of rows, column and holes. In the next k lines, there is a pair of integers (x, y) in each line, which represents a hole in the y-th row, the x-th column.
Output

If the board can be covered, output "YES". Otherwise, output "NO".
Sample Input

4 3 2
2 1
3 3
Sample Output

YES
Hint

 
A possible solution for the sample input.
*/

#include <stdio.h>
#include <string.h>
#define N 1100

int g[N][N], q[N], pv[N], ma[N], mb[N];
int match(int nva, int nvb)     // nva: |X|, nvb: |Y|
{
	int i, j, x, qs, qe, res = 0;
	memset(ma, -1, sizeof(ma));
	memset(mb, -1, sizeof(mb));
	for (i = 0; i < nva; i++) { // vertex: 0 ~ n-1
		qs = qe = 0;
		for (j = 0; j < nvb; j++) pv[j] = -2;
		for (j = 0; j < nvb; j++) if (g[i][j]) {
            pv[j] = -1; q[qe++] = j;
		}
		while (qs < qe) {
			if (-1 == mb[x = q[qs]]) break;
			for (qs++, j = 0; j < nvb; j++)
				if(-2 == pv[j] && g[ mb[x] ][j]) {
					pv[j] = x; q[qe++] = j;
				}
		}
		if (qs == qe) continue;
		while (pv[x] > -1) {
			ma[ mb[ pv[x] ] ] = x;
			mb[x] = mb[ pv[x] ];
			x = pv[x];
		}
		mb[x] = i; ma[i] = x; res++;
	}
	return res;
}

int main()
{
	int m, n, k;
	int i, jw, jb, a, b;
	memset(g, 0, sizeof(g));
	scanf("%d %d %d", &m ,&n, &k);
	
	if ((m * n - k) % 2)
	{
		printf("NO\n");
		return 0;
	}
	for(i = 0;i < m;i++)
	{
		if (i % 2)
		{
			jw = 1;
			jb = 0;
		}
		else
		{
			jw = 0;
			jb = 1;
		}
		for(;jw < n;jw += 2)
		{
			if (i)
				g[i * n + jw][(i - 1) * n + jw] = 1;
			if (jw)
				g[i * n + jw][i * n + jw - 1] = 1;
			if (i + 1 < m)
				g[i * n + jw][(i + 1) * n + jw] = 1;
			if (jw + 1 < n)
				g[i * n + jw][i * n + jw + 1] = 1;
		}
		for(;jb < n;jb += 2)
		{
			if (i)
				g[(i - 1) * n + jb][i * n + jb] = 1;
			if (jb)
				g[i * n + jb - 1][i * n + jb] = 1;
			if (i + 1 < m)
				g[(i + 1) * n + jb][i * n + jb] = 1;
			if (jb + 1 < n)
				g[i * n + jb + 1][i * n + jb] = 1;
		}
	}
	for(i = 0;i < k;i++)
	{
		scanf("%d %d", &b, &a);
		if (b > 1)
			g[(a - 1) * n + b - 2][(a - 1) * n + b - 1] = g[(a - 1) * n + b - 1][(a - 1) * n + b - 2] = 0;
		if (a > 1)
			g[(a - 2) * n + b - 1][(a - 1) * n + b - 1] = g[(a - 1) * n + b - 1][(a - 2) * n + b - 1] = 0;
		if (a < m)
			g[(a - 1) * n + b - 1][a * n + b - 1] = g[a * n + b - 1][(a - 1) * n + b - 1] = 0;
		if (b < n)
			g[(a - 1) * n + b - 1][(a - 1) * n + b] = g[(a - 1) * n + b][(a - 1) * n + b - 1] = 0;
	}
	if (match(m * n, m * n) == (n * m - k) / 2)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
