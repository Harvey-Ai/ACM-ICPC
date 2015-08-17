/*
Description

The police office in Tadu City decides to say ends to the chaos, as launch actions to root up the TWO gangs in the city, Gang Dragon and Gang Snake. However, the police first needs to identify which gang a criminal belongs to. The present question is, given two criminals; do they belong to a same clan? You must give your judgment based on incomplete information. (Since the gangsters are always acting secretly.) 

Assume N (N <= 10^5) criminals are currently in Tadu City, numbered from 1 to N. And of course, at least one of them belongs to Gang Dragon, and the same for Gang Snake. You will be given M (M <= 10^5) messages in sequence, which are in the following two kinds: 

1. D [a] [b] 
where [a] and [b] are the numbers of two criminals, and they belong to different gangs. 

2. A [a] [b] 
where [a] and [b] are the numbers of two criminals. This requires you to decide whether a and b belong to a same gang. 
Input

The first line of the input contains a single integer T (1 <= T <= 20), the number of test cases. Then T cases follow. Each test case begins with a line with two integers N and M, followed by M lines each containing one message as described above.
Output

For each message "A [a] [b]" in each case, your program should give the judgment based on the information got before. The answers might be one of "In the same gang.", "In different gangs." and "Not sure yet."
Sample Input

1
5 5
A 1 2
D 1 2
A 1 2
D 2 4
A 1 4
Sample Output

Not sure yet.
In different gangs.
In the same gang.
*/


#include <stdio.h>
#include <string.h>
#define N 100005
int set[N];

void makeSet()
{
	memset(set, -1, sizeof(set));
}

int getF(int id)
{
	int father = id;
	while(set[id] >= 0)
	{
		id = set[id];
		father = id;
	}
	return father;
}

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
	char c;
	int ncase, i, a, b, m, n;
	int oppos[N];

	scanf("%d", &ncase);

	while(ncase--)
	{
		makeSet();
		memset(oppos, -1, sizeof(oppos));
		scanf("%d %d", &n, &m);
		for(i = 0;i < m;i++)
		{
			getchar();
			scanf("%c %d %d", &c, &a, &b);
			if(c == 'A')
			{
				if (oppos[a] == -1 || oppos[b] == -1)
					printf("Not sure yet.\n");
				else if (getF(a) == getF(b))
					printf("In the same gang.\n");
				else if (getF(a) == getF(oppos[b]) || getF(b) == getF(oppos[a]))
					printf("In different gangs.\n");
				else
					printf("Not sure yet.\n");
			}
			else
			{
				if (oppos[a] == -1)
					oppos[a] = b;
				if (oppos[b] == -1)
					oppos[b] = a;
				Union(a, oppos[b]);
				Union(b, oppos[a]);
			}
		}
	}
	return 0;
}

