/*
Description

There are so many different religions in the world today that it is difficult to keep track of them all. You are interested in finding out how many different religions students in your university believe in. 

You know that there are n students in your university (0 < n <= 50000). It is infeasible for you to ask every student their religious beliefs. Furthermore, many students are not comfortable expressing their beliefs. One way to avoid these problems is to ask m (0 <= m <= n(n-1)/2) pairs of students and ask them whether they believe in the same religion (e.g. they may know if they both attend the same church). From this data, you may not know what each person believes in, but you can get an idea of the upper bound of how many different religions can be possibly represented on campus. You may assume that each student subscribes to at most one religion.
Input

The input consists of a number of cases. Each case starts with a line specifying the integers n and m. The next m lines each consists of two integers i and j, specifying that students i and j believe in the same religion. The students are numbered 1 to n. The end of input is specified by a line in which n = m = 0.
Output

For each test case, print on a single line the case number (starting with 1) followed by the maximum number of different religions that the students in the university believe in.
Sample Input

10 9
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10
10 4
2 3
4 5
4 8
5 8
0 0
Sample Output

Case 1: 1
Case 2: 7
*/


#include <stdio.h>
#include <string.h>

int students[50005];
int getF(int id)
{
	int father = id;
	while(students[id] >= 0)
	{
		id = students[id];
		father = id;
	}
	return father;
}

void uion(int id1, int id2)
{
	int fA, fB;
	fA = getF(id1);
	fB = getF(id2);

	if (fA == fB)
		return;
	if (students[fA] < students[fB])
	{
		students[fA] += students[fB];
		students[fB] = fA;
	}
	else
	{
		students[fB] += students[fA];
		students[fA] = fB;
	}
}
int main()
{
	int i, a, b, m, n, res, ncase = 1;

	while(scanf("%d %d", &n, &m), m || n)
	{
		memset(students, -1, sizeof(students));

		for(i = 0;i < m;i++)
		{
			scanf("%d %d", &a, &b);
			uion(a, b);
		}

		res = 0;
		for(i = 1;i <= n;i++)
			if(students[i] < 0)
				res++;
		printf("Case %d: %d\n", ncase++, res);
	}
	return 0;
}
