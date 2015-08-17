/*
Problem Description

A regular brackets sequence is defined in the following way:
1.Empty sequence is a regular sequence.

2.If S is a regular sequence, then (S) is also a regular sequence.

3.if a and b are regular brackets sequences, then ab is a regular brackets sequence.

4.no other sequence is a regular brackets sequence

Now you will be given a brackets sequence S consist of '(' and ')'. You are required to produce a regular sequence with it.

You can make some changes on the sequence. Each time you can choose a position x and switch the character S[x] to the opposite(ie,from '(' to ')' and vice versa) with a cost of C[x].

What's the minicost to obtain a regular sequence?

 Input

There are multiple cases, for each case,
the first line is the sequence string S (1 <= SIZE(S) <= 1000)

Then following SIZE(S) integers (C[1],C[2],...,C[N]) 0 <= C[i] <= 1000.

There maybe one or more lines between each case.

 Output

For each case,
if you can obtain a regular sequence,output the minicost,or output -1 instead.

 Sample Input

()(
33 78 84 

())(
63 73 55 18 
 Sample Output

-1
73
*/


#include <stdio.h>
#include <string.h>
#define MIN(a,b) (a == -1) ? (b) : ((b == -1) ? (a) : ((a) <(b) ? (a) : (b)))
int cost[1005];
char s[1005];
int res;
void proc()
{
	int i, j, l;
	int now[505], pre[505];
	char *p;
	int * pn, * pp, * temp;

	p = &s[0];
	l = strlen(s);
	memset(pre, -1, sizeof(pre));
	memset(now, -1, sizeof(now));

	if (l%2)
	{
		res = -1;
		return;
	};

	pn = now;
	pp = pre;

	for (pp[0] = 0, i = 0;i < l;i++, p++)
	{
		if (*p == ')')
		{
			if (pp[1] != -1)
				pn[0] = pp[1];
			else
				pn[0] = -1;
			for(j = 1;j < l/2;j++)
			{
				if(pp[j+1] != -1)
					pn[j] = MIN(pp[j-1] + cost[i], pp[j+1]);
				else
					pn[j] = pp[j+1];
			}
			if (pp[l/2-1] != -1)
				pn[l/2] = pp[l/2-1] + cost[i];
			else
				pn[l/2] = -1;
		}
		else
		{
			if (pp[1] != -1)
				pn[0] = pp[1] + cost[i];
			else
				pn[0] = -1;
			for(j = 1;j < l/2;j++)
			{
				if(pp[j+1] != -1)
					pn[j] = MIN(pp[j-1], pp[j+1] + cost[i]);
				else
					pn[j] = pp[j-1];
			}
			if (pp[l/2-1] != -1)
				pn[l/2] = pp[l/2-1];
			else
				pn[l/2] = -1;
		}
		temp = pp;
		pp = pn;
		pn = temp;
	}
	res = pp[0];
}
void out()
{
	printf("%d\n", res);
	if (strlen(s)%2 == 0 && res == -1)
		while(1);
}
int main()
{
	int i, l;
	while(scanf("%s", s) != EOF)
	{
		l = strlen(s);
		for(i = 0;i < l;i++)
			scanf("%d", &cost[i]);
		proc();
		out();
	}
	return 0;
}
