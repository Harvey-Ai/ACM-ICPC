/*
Description

When a radio station is broadcasting over a very large area, repeaters are used to retransmit the signal so that every receiver has a strong signal. However, the channels used by each repeater must be carefully chosen so that nearby repeaters do not interfere with one another. This condition is satisfied if adjacent repeaters use different channels. 

Since the radio frequency spectrum is a precious resource, the number of channels required by a given network of repeaters should be minimised. You have to write a program that reads in a description of a repeater network and determines the minimum number of channels required.
Input

The input consists of a number of maps of repeater networks. Each map begins with a line containing the number of repeaters. This is between 1 and 26, and the repeaters are referred to by consecutive upper-case letters of the alphabet starting with A. For example, ten repeaters would have the names A,B,C,...,I and J. A network with zero repeaters indicates the end of input. 

Following the number of repeaters is a list of adjacency relationships. Each line has the form: 

A:BCDH 

which indicates that the repeaters B, C, D and H are adjacent to the repeater A. The first line describes those adjacent to repeater A, the second those adjacent to B, and so on for all of the repeaters. If a repeater is not adjacent to any other, its line has the form 

A: 

The repeaters are listed in alphabetical order. 

Note that the adjacency is a symmetric relationship; if A is adjacent to B, then B is necessarily adjacent to A. Also, since the repeaters lie in a plane, the graph formed by connecting adjacent repeaters does not have any line segments that cross. 
Output

For each map (except the final one with no repeaters), print a line containing the minumum number of channels needed so that no adjacent channels interfere. The sample output shows the format of this line. Take care that channels is in the singular form when only one channel is required.
Sample Input

2
A:
B:
4
A:BC
B:ACD
C:ABD
D:BC
4
A:BCD
B:ACD
C:ABD
D:ABC
0
Sample Output

1 channel needed.
3 channels needed.
4 channels needed. 

*/


#include <stdio.h>
#include <string.h>
int cl[26],g[26][26];
int ok,n;
void dfs(int p,int cc)
{
	if(ok)
		return;
	if(p==n)
	{
		ok=1;
		return;
	}
	int used[26];
	int i;
	memset(used,0,sizeof(used));
	for(i=0;i<p;i++)
		if(g[i][p])
			used[cl[i]]=1;
	for(i=0;i<cc;i++)
		if(!used[i])
		{
			cl[p]=i;
			dfs(p+1,cc);
		}
}
int main()
{
	int i,a;
	char c;
	while(scanf("%d",&n),n)
	{
		getchar();
		memset(g,0,sizeof(g));
		for(i=0;i<n;i++)
		{
			getchar();
			getchar();
			c=getchar();
			while(c!='\n')
			{
				a=c-'A';
				g[a][i]=g[i][a]=1;
				c=getchar();
			}
		}
		ok=0;
		for(i=1;i<=n;i++)
		{
			dfs(0,i);
			if(ok)
				break;
		}
		if(i==1)
			printf("1 channel needed.\n");
		else
			printf("%d channels needed.\n",i);
	}
	return 0;
}
