/*
Problem Description
Recognizing junk mails is a tough task. The method used here consists of two steps:
1) Extract the common characteristics from the incoming email.
2) Use a filter matching the set of common characteristics extracted to determine whether the email is a spam.

We want to extract the set of common characteristics from the N sample junk emails available at the moment, and thus having a handy data-analyzing tool would be helpful. The tool should support the following kinds of operations:

a) “M X Y”, meaning that we think that the characteristics of spam X and Y are the same. Note that the relationship defined here is transitive, so
relationships (other than the one between X and Y) need to be created if they are not present at the moment.

b) “S X”, meaning that we think spam X had been misidentified. Your tool should remove all relationships that spam X has when this command is received; after that, spam X will become an isolated node in the relationship graph.

Initially no relationships exist between any pair of the junk emails, so the number of distinct characteristics at that time is N.
Please help us keep track of any necessary information to solve our problem.
 

Input
There are multiple test cases in the input file.
Each test case starts with two integers, N and M (1 ≤ N ≤ 105 , 1 ≤ M ≤ 106), the number of email samples and the number of operations. M lines follow, each line is one of the two formats described above.
Two successive test cases are separated by a blank line. A case with N = 0 and M = 0 indicates the end of the input file, and should not be processed by your program.
 

Output
For each test case, please print a single integer, the number of distinct common characteristics, to the console. Follow the format as indicated in the sample below.
 

Sample Input
5 6
M 0 1
M 1 2
M 1 3
S 1
M 1 2
S 3

3 1
M 1 2

0 0
 

Sample Output
Case #1: 3
Case #2: 2
*/


#include <stdio.h>
#include <string.h>
#define N 1100005
#define Num 100005
int set[N];
int idx[Num];
int f[N];


/* init the set. all will be set a value -1 */
void makeSet(int n)
{
	memset(set, -1, sizeof(int)*n);
}

/* find operation. return the id's root num */
int getF(int id)
{
	int father = id;
	int temp = id;
	while(set[father] >= 0)
		father = set[father];

	while(set[id] >= 0)
	{
		temp = set[id];
		set[id] = father;
		id =temp;
	}
	return father;
}

/* union operation. union the sets who containt element id1, id2 */
void Union(int id1, int id2)
{
	int fA, fB;
	fA = getF(id1);
	fB = getF(id2);

	if (fA == fB)
		return;
	if (set[fA] < set[fB])
	{
		set[fA] += set[fB];
		set[fB] = fA;
	}
	else
	{
		set[fB] += set[fA];
		set[fA] = fB;
	}
}

int main()
{
	int i, res, a, b, n, m, ncase = 1;
	int newNode;
	char c[1];
	while(scanf("%d %d", &n, &m), m || n)
	{
		newNode = n;
		for(i = 0;i < n;i++)
			idx[i] = i;
		makeSet(m + n);

		while(m--)
		{
			printf("new::%d\n", newNode);
			scanf("%s", c);

			printf("ccc%d\n", c[1]);
			if (c[0] == 'M')
			{
				scanf("%d %d", &a, &b);
				//Union(idx[a], idx[b]);
			}
			else
			{
				scanf("%d", &a);
				//idx[a] = newNode++;
			}
		}
		
		res = 0;
		memset(f, 0, sizeof(f));
		for(i = 0;i < n;i++)
		{
			int temp = getF(idx[i]);
			if(!f[temp])
			{
				f[temp] = 1;
				res++;
			}
		}
		printf("Case #%d: %d\n", ncase++, res);
	}
	return 0;
}
