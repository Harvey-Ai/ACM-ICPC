/*
Description

Consider the following 5 picture frames placed on an 9 x 8 array. 

........ ........ ........ ........ .CCC....

EEEEEE.. ........ ........ ..BBBB.. .C.C....

E....E.. DDDDDD.. ........ ..B..B.. .C.C....

E....E.. D....D.. ........ ..B..B.. .CCC....

E....E.. D....D.. ....AAAA ..B..B.. ........

E....E.. D....D.. ....A..A ..BBBB.. ........

E....E.. DDDDDD.. ....A..A ........ ........

E....E.. ........ ....AAAA ........ ........

EEEEEE.. ........ ........ ........ ........

    1        2        3        4        5   

Now place them on top of one another starting with 1 at the bottom and ending up with 5 on top. If any part of a frame covers another it hides that part of the frame below. 

Viewing the stack of 5 frames we see the following. 

.CCC....

ECBCBB..

DCBCDB..

DCCC.B..

D.B.ABAA

D.BBBB.A

DDDDAD.A

E...AAAA

EEEEEE..






In what order are the frames stacked from bottom to top? The answer is EDABC. 

Your problem is to determine the order in which the frames are stacked from bottom to top given a picture of the stacked frames. Here are the rules: 

1. The width of the frame is always exactly 1 character and the sides are never shorter than 3 characters. 

2. It is possible to see at least one part of each of the four sides of a frame. A corner shows two sides. 

3. The frames will be lettered with capital letters, and no two frames will be assigned the same letter.
Input

Each input block contains the height, h (h<=30) on the first line and the width w (w<=30) on the second. A picture of the stacked frames is then given as h strings with w characters each. 
Your input may contain multiple blocks of the format described above, without any blank lines in between. All blocks in the input must be processed sequentially.
Output

Write the solution to the standard output. Give the letters of the frames in the order they were stacked from bottom to top. If there are multiple possibilities for an ordering, list all such possibilities in alphabetical order, each one on a separate line. There will always be at least one legal ordering for each input block. List the output for all blocks in the input sequentially, without any blank lines (not even between blocks).
Sample Input

9
8
.CCC....
ECBCBB..
DCBCDB..
DCCC.B..
D.B.ABAA
D.BBBB.A
DDDDAD.A
E...AAAA
EEEEEE..
Sample Output

EDABC

*/



#include <stdio.h>
#include <memory.h>
char map[40][40], result[27];
int relation[27][27];
int edge[27][4], used[27], has_frm[27], frm[27];
int total;
void scan(int h, int w)
{
	int i, ii, jj;
	
	for(ii = 0;ii < 26;ii++)
		for(jj = 0;jj < 4;jj++)
			edge[ii][jj] = -1;

	for(ii = 0;ii < h;ii++)
		for(jj = 0;jj < w;jj++)
			if(map[ii][jj] != '.')
			{
				if(edge[map[ii][jj] - 'A'][0] > ii || edge[map[ii][jj] - 'A'][0] == -1)
					edge[map[ii][jj] - 'A'][0] = ii;
				if(edge[map[ii][jj] - 'A'][1] < ii || edge[map[ii][jj] - 'A'][1] == -1)
					edge[map[ii][jj] - 'A'][1] = ii;
				if(edge[map[ii][jj] - 'A'][2] > jj || edge[map[ii][jj] - 'A'][2] == -1)
                    			edge[map[ii][jj] - 'A'][2] = jj;
				if(edge[map[ii][jj] - 'A'][3] < jj || edge[map[ii][jj] - 'A'][3] == -1)
					edge[map[ii][jj] - 'A'][3] = jj;
			}
}
void get_relation()
{
	int i, k, ii, jj;
	for(k = 0;k < total;k++)
	{
		i = frm[k];
		for(jj = edge[i][2]; jj <= edge[i][3];jj++)
		{
			if(map[edge[i][0]][jj] - 'A' != i)
				relation[map[edge[i][0]][jj] - 'A'][i] = 1;
			if(map[edge[i][1]][jj] - 'A' != i)
				relation[map[edge[i][1]][jj] - 'A'][i] = 1;
		}
		for(ii = edge[i][0] + 1; ii < edge[i][1];ii++)
		{
			if(map[ii][edge[i][2]] - 'A' != i)
				relation[map[ii][edge[i][2]] - 'A'][i] = 1;
			if(map[ii][edge[i][3]] - 'A' != i)                 
				relation[map[ii][edge[i][3]] - 'A'][i] = 1;
		}
	}
}

void dfs(int layer)
{
	if (layer == total)
	{
		printf("%s\n",result);
		return;
	}
	int i, j, k;
	for(k = 0;k < total;k++)
	{
		i =frm[k];
		if(!used[i])
		{
			for(j = 0;j < layer;j++)
				if(relation[result[j] - 'A'][i])
					break;
			if(j >= layer)
			{
				result[layer] = i + 'A';
				used[i] = 1;
				dfs(layer + 1);
				used[i] = 0;
			}
		}
	}
	return;
}
	
int main()
{
	int i, j, w, h;

	while(scanf("%d %d",&h, &w) != EOF)
	{
		for(i = 0;i < h;i++)
			scanf("%s",map[i]);
		memset(has_frm, 0, sizeof(has_frm));
		for(i = 0;i < h;i++)
			for(j = 0;j < w;j++)
				if(has_frm[map[i][j] - 'A'] == 0)
					has_frm[map[i][j] - 'A'] = 1;
		for(i = 0, total = 0;i < 26;i++)
			if(has_frm[i])
				frm[total++] = i;
		memset(relation, 0, sizeof(relation));
		memset(used, 0, sizeof(used));
		scan(h, w);
		get_relation();
		result[total] = '\0';
		dfs(0);
	}
	return 0;
}
