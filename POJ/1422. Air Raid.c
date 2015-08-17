/*
Description

Consider a town where all the streets are one-way and each street leads from one intersection to another. It is also known that starting from an intersection and walking through town's streets you can never reach the same intersection i.e. the town's streets form no cycles. 

With these assumptions your task is to write a program that finds the minimum number of paratroopers that can descend on the town and visit all the intersections of this town in such a way that more than one paratrooper visits no intersection. Each paratrooper lands at an intersection and can visit other intersections following the town streets. There are no restrictions about the starting intersection for each paratrooper. 
Input

Your program should read sets of data. The first line of the input file contains the number of the data sets. Each data set specifies the structure of a town and has the format: 

no_of_intersections 
no_of_streets 
S1 E1 
S2 E2 
...... 
Sno_of_streets Eno_of_streets 

The first line of each data set contains a positive integer no_of_intersections (greater than 0 and less or equal to 120), which is the number of intersections in the town. The second line contains a positive integer no_of_streets, which is the number of streets in the town. The next no_of_streets lines, one for each street in the town, are randomly ordered and represent the town's streets. The line corresponding to street k (k <= no_of_streets) consists of two positive integers, separated by one blank: Sk (1 <= Sk <= no_of_intersections) - the number of the intersection that is the start of the street, and Ek (1 <= Ek <= no_of_intersections) - the number of the intersection that is the end of the street. Intersections are represented by integers from 1 to no_of_intersections. 

There are no blank lines between consecutive sets of data. Input data are correct. 
Output

The result of the program is on standard output. For each input data set the program prints on a single line, starting from the beginning of the line, one integer: the minimum number of paratroopers required to visit all the intersections in the town. 
Sample Input

2
4
3
3 4
1 3
2 3
3
3
1 3
1 2
2 3
Sample Output

2
1
*/


#include <stdio.h>
#include <string.h>
#define N 130

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
	int i;
	int nc, nr;
	int ncase;
	int a, b;
	scanf("%d", &ncase);
	while(ncase--)
	{
		memset(g, 0, sizeof(g));
		scanf("%d %d", &nc, &nr);
		for(i = 0;i < nr;i++)
		{
			scanf("%d %d", &a, &b);
			g[a - 1][b - 1] = 1;
		}
		printf("%d\n", (nc - match(nc, nc)));
	}
	return 0;
}
