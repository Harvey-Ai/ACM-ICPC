/*
Description

As we all know, machine scheduling is a very classical problem in computer science and has been studied for a very long history. Scheduling problems differ widely in the nature of the constraints that must be satisfied and the type of schedule desired. Here we consider a 2-machine scheduling problem. 

There are two machines A and B. Machine A has n kinds of working modes, which is called mode_0, mode_1, ..., mode_n-1, likewise machine B has m kinds of working modes, mode_0, mode_1, ... , mode_m-1. At the beginning they are both work at mode_0. 

For k jobs given, each of them can be processed in either one of the two machines in particular mode. For example, job 0 can either be processed in machine A at mode_3 or in machine B at mode_4, job 1 can either be processed in machine A at mode_2 or in machine B at mode_4, and so on. Thus, for job i, the constraint can be represent as a triple (i, x, y), which means it can be processed either in machine A at mode_x, or in machine B at mode_y. 

Obviously, to accomplish all the jobs, we need to change the machine's working mode from time to time, but unfortunately, the machine's working mode can only be changed by restarting it manually. By changing the sequence of the jobs and assigning each job to a suitable machine, please write a program to minimize the times of restarting machines. 
Input

The input file for this program consists of several configurations. The first line of one configuration contains three positive integers: n, m (n, m < 100) and k (k < 1000). The following k lines give the constrains of the k jobs, each line is a triple: i, x, y. 

The input will be terminated by a line containing a single zero. 
Output

The output should be one integer per line, which means the minimal times of restarting machine.
Sample Input

5 5 10
0 1 1
1 1 2
2 1 3
3 1 4
4 2 1
5 2 2
6 2 3
7 2 4
8 3 3
9 4 3
0
Sample Output

3
*/


#include <stdio.h>
#include <string.h>
#define N 105

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
	int m, n, constraint;
	int no, a, b;
	memset(g, 0, sizeof(g));
	
	while(scanf("%d", &n), n)
	{
		scanf("%d %d", &m, &constraint);

		memset(g, 0, sizeof(g));
		for(i = 0;i < constraint; i++)
		{
			scanf("%d %d %d", &no, &a, &b);
			g[a - 1][b - 1] = 1;
		}

		printf("%d\n", match(n, m));
	}
	return 0;
}
