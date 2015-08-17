/*
Description

Clickomania is a puzzle in which one starts with a rectangular grid of cells of different colours. In each step, a player selects ("clicks") a cell. All connected cells of the same colour as the selected cell (including itself) are removed if the selected cell is connected to at least one other cell of the same colour. The resulting "hole" is filled in by adjacent cells based on some rule, and the object of the game is to remove all cells in the grid. 

In this problem, we are interested in the one-dimensional version of the problem. The starting point of the puzzle is a string of colours (each represented by an uppercase letter). At any point, one may select (click) a letter provided that the same letter occurs before or after the one selected. The substring of the same letter containing the selected letter is removed, and the string is shortened to remove the hole created. To solve the puzzle, the player has to remove all letters and obtain the empty string. If the player obtains a non-empty string in which no letter can be selected, then the player loses. 

For example, if one starts with the string "ABBAABBAAB", selecting the first "B" gives "AAABBAAB". Next, selecting the last "A" gives "AAABBB". Selecting an "A" followed by a "B" gives the empty string. On the other hand, if one selects the third "B" first, the string "ABBAAAAB" is obtained. One may verify that regardless of the next selections, we obtain either the string "A" or the string "B" in which no letter can be selected. Thus, one must be careful in the sequence of selections chosen in order to solve a puzzle. Furthermore, there are some puzzles that cannot be solved regardless of the choice of selections. For example, "ABBAAAAB" is not a solvable puzzle. 

Some facts are known about solvable puzzles: 
The empty string is solvable. 
If x and y are solvable puzzles, so are xy, AxA, and AxAyA for any uppercase letter A. 
All other puzzles not covered by the rules above are unsolvable. 

Given a puzzle, your task is to determine whether it can be solved or not.
Input

Each case of input is specified by a single line. Each line contains a string of uppercase letters. Each string has at least one but no more than 150 characters. The input is terminated by the end of file.
Output

For each input case, print solvable on a single line if there is a sequence of selections that solves the puzzle. Otherwise, print unsolvable on a line.
Sample Input

ABBAABBAAB
ABBAAAAB
Sample Output

solvable
unsolvable

*/

#include <stdio.h>
#include <string.h>

char str[155];
int dp[155][155];

int solve(int from, int to)
{
	int res, i;
	int b, e;
	if (from > to)
		return 2;
	if (dp[from][to])
		return dp[from][to];

	res = 1;

	if (str[from] == str[to] && to > from)
	{
		for(b = from;b < to && str[b] == str[from];b++);
		for(e = to;e > from && str[e] == str[to];e--);
		res = solve(b, e);
		if (b < e)
			for (i = b;i <= e;i++)
				if (str[i] == str[from] && solve(b, i - 1) == 2 && solve(i + 1, e) == 2)
				{
					res = 2;
					break;
				}
	}

	for(i = from;i < to;i++)
		if (solve(from, i) == 2 && solve(i + 1, to) == 2)
		{
			res = 2;
			break;
		}
	dp[from][to] = res;
	return dp[from][to];
}

int main()
{
	while(scanf("%s", str) != EOF)
	{
		memset(dp, 0, sizeof(dp));
		if (solve(0, strlen(str) - 1) == 2)
			printf("solvable\n");
		else
			printf("unsolvable\n");	
	}
	return 0;
}
