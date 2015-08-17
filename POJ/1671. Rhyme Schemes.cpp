/*
Description

The rhyme scheme for a poem (or stanza of a longer poem) tells which lines of the poem rhyme with which other lines. For example, a limerick such as If computers that you build are quantum 
Then spies of all factions will want 'em 
Our codes will all fail 
And they'll read our email 
`Til we've crypto that's quantum and daunt 'em 

Jennifer and Peter Shor (http://www.research.att.com/~shor/notapoet.html) 

Has a rhyme scheme of aabba, indicating that the first, second and fifth lines rhyme and the third and fourth lines rhyme. 
For a poem or stanza of four lines, there are 15 possible rhyme schemes: 
aaaa, aaab, aaba, aabb, aabc, abaa, abab, abac, abba, abbb, abbc, abca, a bcb, abcc, and abcd. 
Write a program to compute the number of rhyme schemes for a poem or stanza of N lines where N is an input value.
Input

Input will consist of a sequence of integers N, one per line, ending with a 0 (zero) to indicate the end of the data. N is the number of lines in a poem.
Output

For each input integer N, your program should output the value of N, followed by a space, followed by the number of rhyme schemes for a poem with N lines as a decimal integer with at least 12 correct significant digits (use double precision floating point for your computations).
Sample Input

1
2
3
4
20
30
10
0
Sample Output

1 1
2 2
3 5
4 15
20 51724158235372
30 846749014511809120000000
10 115975
*/



#include <stdio.h>
#include <math.h>
int main()
{
	double dp[50][50],rel;
	int i,j,n;
	for(i=0;i<50;i++)
	{
		dp[i][0]=1;
		for(j=1;j<50;j++)
			dp[i][j]=0;
	}
	for(i=1;i<50;i++)
		for(j=1;j<=i;j++)
			dp[i][j]=dp[i-1][j-1]+dp[i-1][j]*(j+1);

	while(scanf("%d",&n),n)
	{
		for(rel=0,i=0;i<=n-1;i++)
			rel+=dp[n-1][i];
		printf("%d %.0lf\n",n,rel);
	}
	return 0;
}
