/*
Description

You are given two pots, having the volume of A and B liters respectively. The following operations can be performed:

FILL(i)        fill the pot i (1 ≤ i ≤ 2) from the tap;
DROP(i)      empty the pot i to the drain;
POUR(i,j)    pour from pot i to pot j; after this operation either the pot j is full (and there may be some water left in the pot i), or the pot i is empty (and all its contents have been moved to the pot j).
Write a program to find the shortest possible sequence of these operations that will yield exactly C liters of water in one of the pots.

Input

On the first and only line are the numbers A, B, and C. These are all integers in the range from 1 to 100 and C≤max(A,B).

Output

The first line of the output must contain the length of the sequence of operations K. The following K lines must each describe one operation. If there are several sequences of minimal length, output any one of them. If the desired result can’t be achieved, the first and only line of the file must contain the word ‘impossible’.

Sample Input

3 5 4
Sample Output

6
FILL(2)
POUR(2,1)
DROP(1)
POUR(2,1)
FILL(2)
POUR(2,1)

*/

#include <stdio.h>
#include <string.h>
int Stats[105][105];
int Res, A, B, C;

struct queue
{
	int a, b, op, parent;
	void insert(int da,int db, int operation, int pr)
	{
		a = da;
		b = db;
		op = operation;
		parent = pr;
	}
};
struct queue line[10005];

void init()
{
	memset(Stats, 0, sizeof(Stats));
	Res = -1;
}
void read()
{
	scanf("%d %d %d", &A, &B, &C);
}
void bfs()
{
	int pt, num, ga, gb, op; 

	line[0].insert(0, 0, -1, -1);
	Stats[0][0] = 1;

	pt = 0;num = 1;
	while(pt < num)
	{
		if (line[pt].a == C || line[pt].b == C)
		{
			Res = pt;
			break;
		}
		ga = A;
		gb = line[pt].b;
		op = 1;
		if (!Stats[ga][gb])
		{
			Stats[ga][gb] = 1;
			line[num].insert(ga, gb, op, pt);
			num++;
		}
		ga = line[pt].a;
		gb = B;
		op = 2;
		if (!Stats[ga][gb])
		{
		 	Stats[ga][gb] = 1;
			line[num].insert(ga, gb, op, pt);
			num++;
		}
		op = 11;
		if (line[pt].a > B -line[pt].b)
		{
			ga = line[pt].a - B + line[pt].b;
			gb = B;
		}
		else
		{
			ga = 0;
			gb = line[pt].b + line[pt].a;
		}
		if (!Stats[ga][gb])
		{
			Stats[ga][gb] = 1;
			line[num].insert(ga, gb, op, pt);
			num++;
		}	
		op = 12; 
        if (line[pt].b > A -line[pt].a)
        {   
            ga = A;
            gb = line[pt].b - A + line[pt].a;
        }   
        else
        {   
            ga = line[pt].a + line[pt].b;
            gb = 0;
        }
        if (!Stats[ga][gb])
        {
			Stats[ga][gb] = 1;
            line[num].insert(ga, gb, op, pt);
            num++;
        }
		op = 21; 
		ga = 0;
		gb = line[pt].b;
        if (!Stats[ga][gb])
        {
			Stats[ga][gb] = 1;
            line[num].insert(ga, gb, op, pt);
            num++;
		}
		op = 22;
        ga = line[pt].a;
        gb = 0;
        if (!Stats[ga][gb])
        {
			Stats[ga][gb] = 1;
            line[num].insert(ga, gb, op, pt);
            num++;
        }
		pt++;
	}
}

void print()
{
	int pr = Res, i;
	int opSet[10005];
	if (Res == -1)	printf("impossible\n");
	for(i = 0;pr != 0;i++)
	{
		opSet[i] = line[pr].op;
		pr = line[pr].parent;
	}
	printf("%d\n", i);
	while(i--)
	{
		switch(opSet[i])
		{
			case 1:
				printf("FILL(1)\n");
				break;
			case 2:
				printf("FILL(2)\n");
				break;
			case 11:
				printf("POUR(1,2)\n");
				break;
			case 12:
				printf("POUR(2,1)\n");
				break;
			case 21:
                printf("DROP(1)\n");
				break;
			case 22:
				printf("DROP(2)\n");
				break;
		}
	}
}
int main()
{
	init();
	read();
	if (A&0x001 == 0 && B&0x0001 == 0 && C&0x0001)
		printf("impossible\n");
	bfs();
	print();
	return 0;
}
