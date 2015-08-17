/*
Description

An earthquake takes place in Southeast Asia. The ACM (Asia Cooperated Medical team) have set up a wireless network with the lap computers, but an unexpected aftershock attacked, all computers in the network were all broken. The computers are repaired one by one, and the network gradually began to work again. Because of the hardware restricts, each computer can only directly communicate with the computers that are not farther than d meters from it. But every computer can be regarded as the intermediary of the communication between two other computers, that is to say computer A and computer B can communicate if computer A and computer B can communicate directly or there is a computer C that can communicate with both A and B. 

In the process of repairing the network, workers can take two kinds of operations at every moment, repairing a computer, or testing if two computers can communicate. Your job is to answer all the testing operations. 
Input

The first line contains two integers N and d (1 <= N <= 1001, 0 <= d <= 20000). Here N is the number of computers, which are numbered from 1 to N, and D is the maximum distance two computers can communicate directly. In the next N lines, each contains two integers xi, yi (0 <= xi, yi <= 10000), which is the coordinate of N computers. From the (N+1)-th line to the end of input, there are operations, which are carried out one by one. Each line contains an operation in one of following two formats: 
1.	"O p" (1 <= p <= N), which means repairing computer p. 
2.	"S p q" (1 <= p, q <= N), which means testing whether computer p and q can communicate. 

The input will not exceed 300000 lines. 
Output

For each Testing operation, print "SUCCESS" if the two computers can communicate, or "FAIL" if not.
Sample Input

4 1
0 1
0 2
0 3
0 4
O 1
O 2
O 4
S 1 4
O 3
S 1 4
Sample Output

FAIL
SUCCESS

*/


#include <stdio.h>
#include <string.h>
#define N 1005
int set[N];
int work[N];
int map[N][N];
int x[N], y[N];


void makeSet()
{
    memset(set, -1, sizeof(set));
}

int getF(int id)
{
	int father = id;
	int temp = id;
	while(set[father] >= 0)
		father = set[father];

	while(id >= 0)
	{
		temp = set[id];
		set[id] = father;
		id =temp;
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


void pre(int n, int limit)
{
    int i, j;
    makeSet();
    memset(map, 0, sizeof(map));
    memset(work, 0, sizeof(work));

    for(i = 0;i < n;i++)
        for(j = 0;j < n;j++)
        {
            if (i == j)
                continue;
            else
            {
                if((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) <= limit*limit)
                    map[i][j] = map[j][i] = 1;
            }
        }
}

void pro(int n)
{
    char op;
    int i, p, q;
    getchar();

    while(scanf("%c",&op) != EOF)
    {
        if (op == 'O')
        {
            scanf("%d", &p);
            for(i = 0;i < n;i++)
                if (map[i][p-1] && work[i])
                    Union(i, p-1);
            work[p-1] = 1;
        }
        else
        {
            scanf("%d %d", &p, &q);
            if (getF(p-1) == getF(q-1))
                printf("SUCCESS\n");
            else
                printf("FAIL\n");
        }
		getchar();
    }
}
int main()
{
    int i, n, limit;
    scanf("%d %d", &n, &limit);

    for(i = 0;i < n;i++)
        scanf("%d %d", &x[i], &y[i]);

    pre(n, limit);
    pro(n);
    return 0;
}
