/*
You all must know the puzzle named "The Towers of Hanoi". The puzzle has three pegs (peg 1, peg 2 and peg 3) and N disks of different radii. Initially all disks are located on the first peg, ordered by their radii - the largest at the bottom, the smallest at the top. In each turn you may take the topmost disc from any peg and move it to another peg, the only rule says that you may not place the disc atop any smaller disk. The problem is to move all disks to the last peg (peg 3). I use two different integers a (1 <= a <= 3) and b (1 <= b <= 3) to indicate a move. It means to move the topmost disk of peg a to the top of peg b. A move is valid if and only if there is at least one disk on peg a and the topmost disk of peg a can be moved on the peg b without breaking the former rule.

Give you some moves of a game, can you give out the result of the game?

Input

Standard input will contain multiple test cases. The first line of the input is a single integer T (1 <= T <= 55) which is the number of test cases. And it will be followed by T consecutive test cases.

The first line of each test case is a single line containing 2 integers n (1 <= n <= 10) and m (1 <= m <= 12000) which is the number of disks and the number of the moves. Then m lines of moves follow.

Output

For each test case, output an integer in a single line according to the result of the moves.
Note:
(1) If there is an invalid move before all disks being on peg 3 and the invalid move is the p-th move of this case (start from 1) , output the integer -p please and the moves after this move(if any) are ignored.
(2) If after the p-th move all disks are on peg 3 without any invalid move, output the integer p please and the moves after this move (if any) are ignored.
(3) Otherwise output the integer 0 please.

Sample Input

3
2 3
1 2
1 3
2 3
2 3
1 2
1 3
3 2
2 3
1 3
1 2
3 2
Sample Output

3
-3
0
*/

#include <stdio.h>
int main()
{
	int stack[3][12001];
	int i,N,a,b,m,n,top[3];
	stack[0][0]=stack[1][0]=stack[2][0]=15;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
			stack[0][i]=n-i;
		top[0]=n;
		top[1]=top[2]=0;
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&a,&b);
			if(top[a-1]&&(stack[b-1][top[b-1]]>stack[a-1][top[a-1]]))
			{
				top[a-1]--;
				top[b-1]++;
				stack[b-1][top[b-1]]=stack[a-1][top[a-1]+1];
				if(top[2]==n)
					break;
			}
			else
				break;
		}
		if(i<=m)
		{
			if(top[2]==n)	printf("%d\n",i);
			else	printf("-%d\n",i);
			i++;
			while(i<=m)
			{
				scanf("%d%d",&a,&b);
				i++;
			}
		}
		else
			printf("0\n");
	}
	return 0;
}
