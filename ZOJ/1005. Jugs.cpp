/*
In the movie "Die Hard 3", Bruce Willis and Samuel L. Jackson were confronted with the following puzzle. They were given a 3-gallon jug and a 5-gallon jug and were asked to fill the 5-gallon jug with exactly 4 gallons. This problem generalizes that puzzle.

You have two jugs, A and B, and an infinite supply of water. There are three types of actions that you can use: (1) you can fill a jug, (2) you can empty a jug, and (3) you can pour from one jug to the other. Pouring from one jug to the other stops when the first jug is empty or the second jug is full, whichever comes first. For example, if A has 5 gallons and B has 6 gallons and a capacity of 8, then pouring from A to B leaves B full and 3 gallons in A.

A problem is given by a triple (Ca,Cb,N), where Ca and Cb are the capacities of the jugs A and B, respectively, and N is the goal. A solution is a sequence of steps that leaves exactly N gallons in jug B. The possible steps are

fill A 
fill B 
empty A 
empty B 
pour A B 
pour B A 
success

where "pour A B" means "pour the contents of jug A into jug B", and "success" means that the goal has been accomplished.

You may assume that the input you are given does have a solution.

Input

Input to your program consists of a series of input lines each defining one puzzle. Input for each puzzle is a single line of three positive integers: Ca, Cb, and N. Ca and Cb are the capacities of jugs A and B, and N is the goal. You can assume 0 < Ca <= Cb and N <= Cb <=1000 and that A and B are relatively prime to one another.

Output

Output from your program will consist of a series of instructions from the list of the potential output lines which will result in either of the jugs containing exactly N gallons of water. The last line of output for each puzzle should be the line "success". Output lines start in column 1 and there should be no empty lines nor any trailing spaces.

Sample Input

3 5 4
5 7 3

Sample Output

fill B
pour B A
empty A
pour B A
fill B
pour B A
success
fill A
pour A B
fill A
pour A B
empty B
pour A B
success
*/

#include <stdio.h>

int x, y;

void solve(int a, int b, int c)
{
	for(y = 0;;y++)
	{
		for(x = 0;a * x <= b * y;x++) 
			if (b * y - a * x == c)
				break;
		if (b * y - a * x == c)
			break;
	}
}

int main()
{
	int ca, cb, ta;
	int in, out;
	int w1, w2;

	while(scanf("%d %d %d", &ca, &cb, &ta) != EOF)
	{
		solve(ca, cb, ta);
		if (cb * y - ca * x != ta)
			while(1);
		in = out = 0;
		w1 = w2 = 0;
		while(w1 != ta && w2 != ta)
		{
			if (w1 + w2 >= ca && out < x)
			{
				if (w1 < ca)
				{
					printf("pour B A\n");
					w2 -= ca - w1;
				}
				printf("empty A\n");
				w1 = 0;
				out++;
			}
			if (w1 + w2 <= ca && in < y)
			{
				if (w2 > 0)
				{
					printf("pour B A\n");
					w1 += w2;
				}
				printf("fill B\n");
				w2 = cb;
				in++;
			}
		}
		printf("success\n");
	}
	return 0;
}
