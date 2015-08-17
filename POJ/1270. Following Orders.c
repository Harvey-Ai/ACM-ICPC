/*
Description

Order is an important concept in mathematics and in computer science. For example, Zorn's Lemma states: ``a partially ordered set in which every chain has an upper bound contains a maximal element.'' Order is also important in reasoning about the fix-point semantics of programs. 


This problem involves neither Zorn's Lemma nor fix-point semantics, but does involve order. 
Given a list of variable constraints of the form x < y, you are to write a program that prints all orderings of the variables that are consistent with the constraints. 


For example, given the constraints x < y and x < z there are two orderings of the variables x, y, and z that are consistent with these constraints: x y z and x z y. 
Input

The input consists of a sequence of constraint specifications. A specification consists of two lines: a list of variables on one line followed by a list of contraints on the next line. A constraint is given by a pair of variables, where x y indicates that x < y. 


All variables are single character, lower-case letters. There will be at least two variables, and no more than 20 variables in a specification. There will be at least one constraint, and no more than 50 constraints in a specification. There will be at least one, and no more than 300 orderings consistent with the contraints in a specification. 


Input is terminated by end-of-file. 
Output

For each constraint specification, all orderings consistent with the constraints should be printed. Orderings are printed in lexicographical (alphabetical) order, one per line. 


Output for different constraint specifications is separated by a blank line. 
Sample Input

a b f g
a b b f
v w x y z
v y x v z v w v
Sample Output

abfg
abgf
agbf
gabf

wxzvy
wzxvy
xwzvy
xzwvy
zwxvy
zxwvy

*/



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int num;
char arr[30], res[30], buf[400];
int constraints[30][30], used[30];
int cmp(const void *a, const void *b)
{
	return *(char *)a - *(char *)b;
}
void read()
{
	int i, j, k, len;
	char c, a1, a2;

	memset(constraints, 0, sizeof(constraints));

	len = strlen(buf);
	for(i = 0, num = 0;i < len;i+=2, num++)
		arr[num] = buf[i];

	qsort(arr, num, sizeof(arr[0]), cmp);

	gets(buf);

	len = strlen(buf);
	for(i = 0;i < len;i += 4)
	{
		a1 = buf[i];
		a2 = buf[i + 2];
		constraints[a2 - 'a'][a1 - 'a'] = 1;
	}

	for(k = 0;k < 26;k++)
		for(i = 0;i < 26;i++)
			for(j = 0;j < 26;j++)
			{
				if(constraints[i][k] && constraints[k][j])
					constraints[i][j] = 1;
			}
}

void dfs(int depth)
{
	int i, j;
	if(depth == num)
	{
		res[depth] = '\0';
		printf("%s\n", res);
		return;
	}
	for(i = 0;i < num;i++)
	{
		if(!used[i])
		{
			for(j = 0;j < depth;j++)
				if(constraints[res[j] - 'a'][arr[i] - 'a'])
					break;
			if(j < depth)	continue;
			else
			{
				used[i] = 1;
				res[depth] = arr[i];
				dfs(depth + 1);
				used[i] = 0;
			}
		}
	}
}

int main()
{
	while(gets(buf))
	{
		memset(used, 0, sizeof(used));
		read();
		dfs(0);
		putchar('\n');
	}
	return 0;
}
