/*
You have been hired by the quality control division of a world famous board game company. Their creative and design division comes up, on a daily basis, with great ideas for board games, but sometimes the scoring of the proposed games does not match the story board or leads the player to impossible or undesirable situations.

Most of the games this company produces can be described loosely as race games. Race games are games where the players need to go from an initial square to a final square, performing along the way, a series of moves, gaining or losing score points for each of those moves. Moves can be influenced by player's decisions, drawing of cards, rolling of dices, etc.

Your task is to check the description of a given game, stating the lowest possible score, or if it can lead to an infinitely high (there's no way the player can win the game), or to an infinitely low score.

Input

A positive integer P in a single line followed by a sequence of P game descriptions. The first line of the game description contains a positive integer N not greater than 300, indicating the number of squares in the game. The second line contains two non-negative integers, I and F, defining the initial and final squares for this game, where I and F are lesser than N. The third line contains an integer M, indicating the number of possible moves of the game. The following M lines describe all the possible moves of the game. Each line, describing one possible move, consists of three integers, respectively, the initial square and final square of the move, in the range [0, N-1],and the corresponding score.

Output

The output consists of a single line with an integer, indicating the lowest possible score for the proposed game. If the scores are infinitely high or low then your program should output infinity.

Sample Input

2
4
0 3
4
0 1 5
0 2 7
2 1 -3
1 3 2
4
0 3
3
0 1 5
0 2 7
2 1 -3
Sample Output

6
infinity
*/


#include <stdio.h>
#define max 1000000000
double dist[305];
int edge[100005][3];
int relax (int u, int v, int c)
{
	if (dist[v] > dist[u] + c) 
	{
		dist[v] = dist[u] + c;
		return 1;
	}
	return 0;
}
int main()
{
	int i,j,m,n,start,end,ncase;
	scanf("%d",&ncase);
	while(ncase--)
	{
		scanf("%d",&n);
		scanf("%d%d",&start,&end);
		scanf("%d",&m);
		for(i=0;i<m;i++)
			scanf("%d%d%d",&edge[i][0],&edge[i][1],&edge[i][2]);
		if(start<0||start>=n||end>=n||end<0)
		{
			printf("infinity\n");
			continue;
		}
		for(i=0;i<n;i++)
			dist[i]=max;
		dist[start]=0;
		for (i=1; i<n; ++i) 
			for (j=0; j<m; ++j)
				relax(edge[j][0], edge[j][1], edge[j][2]);
		for (j=0; j<m; ++j)
			if (1 == relax(edge[j][0], edge[j][1], edge[j][2]))
				break;
		if(j>=m&&dist[end]<max)
			printf("%.0lf\n",dist[end]);
		else
			printf("infinity\n");
	}
	return 0;
}
