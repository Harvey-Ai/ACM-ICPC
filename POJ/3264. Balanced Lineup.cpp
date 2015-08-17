/*
Description

For the daily milking, Farmer John's N cows (1 ≤ N ≤ 50,000) always line up in the same order. One day Farmer John decides to organize a game of Ultimate Frisbee with some of the cows. To keep things simple, he will take a contiguous range of cows from the milking lineup to play the game. However, for all the cows to have fun they should not differ too much in height.

Farmer John has made a list of Q (1 ≤ Q ≤ 200,000) potential groups of cows and their heights (1 ≤ height ≤ 1,000,000). For each group, he wants your help to determine the difference in height between the shortest and the tallest cow in the group.

Input

Line 1: Two space-separated integers, N and Q. 
Lines 2..N+1: Line i+1 contains a single integer that is the height of cow i 
Lines N+2..N+Q+1: Two integers A and B (1 ≤ A ≤ B ≤ N), representing the range of cows from A to B inclusive.
Output

Lines 1..Q: Each line contains a single integer that is a response to a reply and indicates the difference in height between the tallest and shortest cow in the range.
Sample Input

6 3
1
7
3
4
2
5
1 5
4 6
2 2
Sample Output

6
3
0
*/

#include <stdio.h>
int min[50001][17],max[50001][17];
int mi(int x,int y)
{
	return x<y?x:y;
}

int ma(int x,int y)
{
	return x>y?x:y;
}
int main()
{
	int i,j,k,m,n,bg,ed,size;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&min[i][0]);
			max[i][0]=min[i][0];
		}
		for(size=2,j=1;size<=n;j++,size*=2)
			for(i=0;i+size<=n;i++)
			{
				min[i][j]=mi(min[i][j-1],min[i+size/2][j-1]);
				max[i][j]=ma(max[i][j-1],max[i+size/2][j-1]);
			}
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&bg,&ed);
			size=ed-bg+1;
			j=1;k=0;
			while(j*2<=size)
			{
				k++;
				j*=2;
			}
			printf("%d\n",ma(max[bg-1][k],max[ed-j][k])-mi(min[bg-1][k],min[ed-j][k]));
		}
	}
	return 0;
}
