/*
Description

Sudoku is a very simple task. A square table with 9 rows and 9 columns is divided to 9 smaller squares 3x3 as shown on the Figure. In some of the cells are written decimal digits from 1 to 9. The other cells are empty. The goal is to fill the empty cells with decimal digits from 1 to 9, one digit per cell, in such way that in each row, in each column and in each marked 3x3 subsquare, all the digits from 1 to 9 to appear. Write a program to solve a given Sudoku-task. 

Input

The input data will start with the number of the test cases. For each test case, 9 lines follow, corresponding to the rows of the table. On each line a string of exactly 9 decimal digits is given, corresponding to the cells in this line. If a cell is empty it is represented by 0.
Output

For each test case your program should print the solution in the same format as the input data. The empty cells have to be filled according to the rules. If solutions is not unique, then the program may print any one of them.
Sample Input

1
103000509
002109400
000704000
300502006
060000050
700803004
000401000
009205800
804000107
Sample Output

143628579
572139468
986754231
391542786
468917352
725863914
237481695
619275843
854396127
*/


#include <stdio.h>
#include <string.h>
int ok,ss[10][10],ll[10][10],tt[10][10];
char arr[10][10];
void dfs(int a,int b)
{
	int i,t,r,c;
	if(ok)
		return;
	if(a==9)
	{
		for(i=0;i<9;i++)
			printf("%s\n",arr[i]);
		ok=1;
		return;
	}
	if(b==8)
	{
		r=a+1;
		c=0;
	}
	else
	{
		r=a;
		c=b+1;
	}
	t=(a/3)*3+b/3;
	if(arr[a][b]=='0')
	{
		for(i=1;i<10;i++)
		{
			if(ll[a][i]==0&&ss[b][i]==0&&tt[t][i]==0)
			{
				tt[t][i]=1;
				ll[a][i]=1;
				ss[b][i]=1;
				arr[a][b]=i+'0';
				dfs(r,c);
				if(ok)
					return;
				arr[a][b]='0';
				ll[a][i]=0;
				ss[b][i]=0;
				tt[t][i]=0;
			}
		}
	}
	else
		dfs(r,c);
}
int main()
{
	int i,j,ncase;
	scanf("%d",&ncase);
	while(ncase--)
	{
		memset(ss,0,sizeof(ss));
		memset(ll,0,sizeof(ll));
		memset(tt,0,sizeof(tt));
		for(i=0;i<9;i++)
			scanf("%s",arr[i]);
		for(i=0;i<9;i++)
			for(j=0;j<9;j++)
				if(arr[i][j]!='0')
				{
					ll[i][arr[i][j]-'0']=1;
					ss[j][arr[i][j]-'0']=1;
					tt[(i/3)*3+j/3][arr[i][j]-'0']=1;
				}
		ok=0;
		dfs(0,0);
	}
	return 0;
}
