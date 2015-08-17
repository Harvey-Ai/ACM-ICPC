/*
Description

It is well known that it is not easy to select courses in the college, for there is usually conflict among the time of the courses. Li Ming is a student who loves study every much, and at the beginning of each term, he always wants to select courses as more as possible. Of course there should be no conflict among the courses he selects. 

There are 12 classes every day, and 7 days every week. There are hundreds of courses in the college, and teaching a course needs one class each week. To give students more convenience, though teaching a course needs only one class, a course will be taught several times in a week. For example, a course may be taught both at the 7-th class on Tuesday and 12-th class on Wednesday, you should assume that there is no difference between the two classes, and that students can select any class to go. At the different weeks, a student can even go to different class as his wish. Because there are so many courses in the college, selecting courses is not an easy job for Li Ming. As his good friends, can you help him? 
Input

The input contains several cases. For each case, the first line contains an integer n (1 <= n <= 300), the number of courses in Li Ming's college. The following n lines represent n different courses. In each line, the first number is an integer t (1 <= t <= 7*12), the different time when students can go to study the course. Then come t pairs of integers p (1 <= p <= 7) and q (1 <= q <= 12), which mean that the course will be taught at the q-th class on the p-th day of a week.
Output

For each test case, output one integer, which is the maximum number of courses Li Ming can select.
Sample Input

5
1 1 1
2 1 1 2 2
1 2 2
2 3 2 3 3
1 3 3
Sample Output

4
*/

#include <stdio.h>
#include <string.h>
#define N 305
#define MAXT (7 * 12)

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

int lession[N][N];
int main()
{
	int i, j, k, l;
	int n;
	int res;

	while(scanf("%d", &n) != EOF)
	{
		memset(g, 0, sizeof(g));
		for(i = 0;i < n;i++)
		{
			scanf("%d", &lession[i][0]);
			for(j = 1;j <= lession[i][0] * 2;j += 2)
			{
				scanf("%d %d", &lession[i][j], &lession[i][j + 1]);
				g[i][(lession[i][j] - 1) * 12 + lession[i][j + 1] - 1] = 1;
			}
		}

		res = match(n, MAXT);
//	if (res < n - res)
//		res = n - res;
		printf("%d\n", res);
	}

	return 0;
}
