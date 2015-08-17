/*
Description

Let us define a regular brackets sequence in the following way: 

1. Empty sequence is a regular sequence. 
2. If S is a regular sequence, then (S) and [S] are both regular sequences. 
3. If A and B are regular sequences, then AB is a regular sequence. 

For example, all of the following sequences of characters are regular brackets sequences: 

(), [], (()), ([]), ()[], ()[()] 

And all of the following character sequences are not: 

(, [, ), )(, ([)], ([(] 

Some sequence of characters '(', ')', '[', and ']' is given. You are to find the shortest possible regular brackets sequence, that contains the given character sequence as a subsequence. Here, a string a1 a2 ... an is called a subsequence of the string b1 b2 ... bm, if there exist such indices 1 = i1 < i2 < ... < in = m, that aj = bij for all 1 = j = n.
Input

The input file contains at most 100 brackets (characters '(', ')', '[' and ']') that are situated on a single line without any other characters among them.
Output

Write to the output file a single line that contains some regular brackets sequence that has the minimal possible length and contains the given sequence as a subsequence.
Sample Input

([(]
Sample Output

()[()]
*/


#include <iostream>
#include <string.h>
using namespace std;
int tag[101][101],dp[101][101];
char str[101];
void dfs(int h,int t)
{
	if(h>t)
		return;
	if(h==t)
	{
		if(str[h]=='('||str[t]==')')
			printf("()");
		else
			printf("[]");
	}
	else
	{
		if(tag[h][t]==-1)
		{
			if(str[h]=='(')
			{
				putchar('(');
				dfs(h+1,t-1);
				putchar(')');
			}
			else
			{
				putchar('[');
				dfs(h+1,t-1);
				putchar(']');
			}
		}
		else
		{
			dfs(h,tag[h][t]);
			dfs(tag[h][t]+1,t);
		}
	}
}
int main()
{
	int i,j,k,n,min,pos;
	memset(dp,0,sizeof(dp));
	for(i=0;i<101;i++)
		dp[i][i]=1;
	while(cin.getline(str,101))
	{
		n=strlen(str);
		if(n==0)
		{
			putchar('\n');
			continue;
		}
		for(i=2;i<=n;i++)
			for(j=0;j+i-1<n;j++)
			{
				min=1000;pos=-1;
				if(str[j]=='('&&str[i+j-1]==')'||str[j]=='['&&str[i+j-1]==']')
				{
					dp[j][i+j-1]=dp[j+1][i+j-2];
					min=dp[j+1][i+j-2];
				}
				for(k=j;k<j+i-1;k++)
					if(dp[j][k]+dp[k+1][i+j-1]<min)
					{
						pos=k;
						min=dp[j][k]+dp[k+1][i+j-1];
					}
				tag[j][i+j-1]=pos;
				dp[j][i+j-1]=min;
			}
		dfs(0,n-1);
		putchar('\n');
	}
	return 0;
}
