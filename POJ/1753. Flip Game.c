/*
Description

Flip game is played on a rectangular 4x4 field with two-sided pieces placed on each of its 16 squares. One side of each piece is white and the other one is black and each piece is lying either it's black or white side up. Each round you flip 3 to 5 pieces, thus changing the color of their upper side from black to white and vice versa. The pieces to be flipped are chosen every round according to the following rules: 
Choose any one of the 16 pieces. 
Flip the chosen piece and also all adjacent pieces to the left, to the right, to the top, and to the bottom of the chosen piece (if there are any).

Consider the following position as an example: 

bwbw 
wwww 
bbwb 
bwwb 
Here "b" denotes pieces lying their black side up and "w" denotes pieces lying their white side up. If we choose to flip the 1st piece from the 3rd row (this choice is shown at the picture), then the field will become: 

bwbw 
bwww 
wwwb 
wwwb 
The goal of the game is to flip either all pieces white side up or all pieces black side up. You are to write a program that will search for the minimum number of rounds needed to achieve this goal. 
Input

The input consists of 4 lines with 4 characters "w" or "b" each that denote game field position.
Output

Write to the output file a single integer number - the minimum number of rounds needed to achieve the goal of the game from the given position. If the goal is initially achieved, then write 0. If it's impossible to achieve the goal, then write the word "Impossible" (without quotes).
Sample Input

bwwb
bbwb
bwwb
bwww
Sample Output

4
*/



#include <stdio.h>
int adj[16][7]={{3,0,1,4},{4,0,1,2,5},{4,1,2,3,6},{3,2,3,7},{4,0,4,5,8},{5,1,4,5,6,9},{5,2,5,6,7,10},{4,3,6,7,11},
{4,4,8,9,12},{5,5,8,9,10,13},{5,6,9,10,11,14},{4,7,10,11,15},{3,8,12,13},{4,9,12,13,14},{4,10,13,14,15},{3,11,14,15}};
int jie[20],line[65539],layer[65539],tag[65539];
int main()
{
	int i,j,temp,head,tail;
	char state[10];
	jie[0]=1;
	for(i=1;i<17;i++)
		jie[i]=jie[i-1]*2;
	line[0]=0;
	temp=1;
	for(i=0;i<4;i++)
	{
		scanf("%s",state);
		for(j=0;j<4;j++)
		{
			if(state[j]=='w')
				line[0]+=temp;
			temp<<=1;
		}
	}
	layer[0]=0;tag[line[0]]=1;
	head=0;tail=1;
	while(head<tail)
	{
		if(line[head]==0||line[head]==jie[16]-1)
			break;
		for(i=0;i<16;i++)
		{
			temp=line[head];
			for(j=1;j<=adj[i][0];j++)
				temp^=jie[adj[i][j]];
			if(tag[temp]==0)
			{
				layer[tail]=layer[head]+1;
				line[tail++]=temp;
				tag[temp]=1;
			}
		}
		head++;
	}
	if(head<tail)
		printf("%d\n",layer[head]);
	else
		printf("Impossible\n");
	return 0;
}
