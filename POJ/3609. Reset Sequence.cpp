/*
Description

A reset sequence is a series of commands which, when issued, brings a chip to the ready state. When a chip is powered on or encounters an error, it may be in an arbitrary state. The reset sequence ensures that the chip is appropriately (re-)initialized for subsequent tasks.

The state control of a chip is typically modeled after a finite automaton. (Please refer to Problem 3599 Pumping Lemma for an informal description of finite automata.) When it receives a command, the chip transits from its current state to another state as its control logic dictates.

Given the description of the control logic of a chip, compute the shortest reset sequence.

Input

The input consists of a single test case. The first line contains two integers n and m (2 ≤ n ≤ 8, 1 ≤ m ≤ 16), which are the numbers of states and different commands. The states are numbered 0 through n − 1. State 0 is the only ready state. The commands are denoted by hexadecimal digits 0 through f.

Immediately following the first line comes an n × m matrix Δ = {δij}n×m with zero-based indices. Each element δij (0 ≤ δij ≤ n − 1) indicates that when the chip receives command j in state i, it transits to state δij .

Output

Output the shortest reset sequence using its representation by hexadecimal digits. If there are multiple such sequences, output any one. If there are no such sequences, output an asterisk (“*”).

Sample Input

3 4
2 1 1 2
1 0 0 0
0 0 0 1
Sample Output

101
*/


#include <stdio.h>
#include <string.h>
int tag[1000],line[1000],f[1000],g[17][17],rel[1000],s[1000];
int main()
{
	int n,m,i,j,k,t,temp,sum,head,tail;
	scanf("%d%d",&n,&m);
	temp=1;
	temp=(temp<<=n)-1;
	for(i=0;i<=temp;i++)
		tag[i]=-1;
	tag[temp]=1;
	line[0]=temp;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&g[i][j]);
	head=0;tail=1;t=1;
	while(tag[1]==-1)
	{
		for(i=head;i<tail;i++)
		{
			for(j=0;j<m;j++)
			{
				temp=1;
				memset(s,0,sizeof(s));
				for(k=0;k<n;k++)
				{
					if(temp&line[i])
						s[g[k][j]]=1;
					temp<<=1;
				}
				temp=1;sum=0;
				for(k=0;k<n;k++)
				{
					if(s[k])
						sum+=temp;
					temp<<=1;
				}
				if(tag[sum]==-1)
				{
					tag[sum]=j;
					f[sum]=line[i];
					line[t++]=sum;
				}
			}
		}
		head=tail;tail=t;
		if(head==tail)
			break;
	}
	if(tag[1]==-1)
	{
		putchar('*');
		putchar('\n');
		return 0;
	}
	temp=1;
	temp=(temp<<=n)-1;
	for(k=0,i=1;i!=temp;i=f[i],k++)
		rel[k]=tag[i];
	for(i=k-1;i>=0;i--)
	{
		if(rel[i]<=9)
			printf("%d",rel[i]);
		else
			printf("%c",rel[i]-10+97);
	}
	putchar('\n');
	return 0;
}
