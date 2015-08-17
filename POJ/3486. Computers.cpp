/*
Description

Everybody is fond of computers, but buying a new one is always a money challenge. Fortunately, there is always a convenient way to deal with. You can replace your computer and get a brand new one, thus saving some maintenance cost. Of course, you must pay a fixed cost for each new computer you get.

Suppose you are considering an n year period over which you want to have a computer. Suppose you buy a new computer in year y, 1<=y<=n Then you have to pay a fixed cost c, in the year y, and a maintenance cost m(y,z) each year you own that computer, starting from year y through the year z, z<=n, when you plan to buy - eventually - another computer.

Write a program that computes the minimum cost of having a computer over the n year period.

Input

The program input is from a text file. Each data set in the file stands for a particular set of costs. A data set starts with the cost c for getting a new computer. Follows the number n of years, and the maintenance costs m(y,z), y=1..n, z=y..n. The program prints the minimum cost of having a computer throughout the n year period.

White spaces can occur freely in the input. The input data are correct and terminate with an end of file.

Output

For each set of data the program prints the result to the standard output from the beginning of a line.

Sample Input

3
3
5 7 50
6 8
10
Sample Output

19
Hint

An input/output sample is shown above. There is a single data set. The cost for getting a new computer is c=3. The time period n is n=3 years, and the maintenance costs are:

For the first computer, which is certainly bought: m(1,1)=5, m(1,2)=7, m(1,3)=50,
For the second computer, in the event the current computer is replaced: m(2,2)=6, m(2,3)=8,
For the third computer, in the event the current computer is replaced: m(3,3)=10.

*/


#include <stdio.h>
int dp[1000][1000];
int main()
{
	int i,j,m,n,c,min;
	while(scanf("%d",&c)!=EOF)
	{
		scanf("%d",&n);
		for(j=1;j<=n;j++)
		{
			scanf("%d",&m);
			dp[1][j]=c+m;
		}
		for(i=2;i<=n;i++)
		{
			min=100000;
			for(j=i-1;j>0;j--)
			{
				if(dp[j][i-1]+c<min)
					min=dp[j][i-1]+c;
			}
			for(j=i;j<=n;j++)
			{
				scanf("%d",&m);
				dp[i][j]=min+m;
			}
		}
		min=100000;
		for(i=1;i<=n;i++)
			if(dp[i][n]<min)
				min=dp[i][n];
		printf("%d\n",min);
	}
	return 0;
}
