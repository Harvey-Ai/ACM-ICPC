/*
Description

Given three strings, you are to determine whether the third string can be formed by combining the characters in the first two strings. The first two strings can be mixed arbitrarily, but each must stay in its original order. 

For example, consider forming "tcraete" from "cat" and "tree": 

String A: cat 
String B: tree 
String C: tcraete 

As you can see, we can form the third string by alternating characters from the two strings. As a second example, consider forming "catrtee" from "cat" and "tree": 

String A: cat 
String B: tree 
String C: catrtee 

Finally, notice that it is impossible to form "cttaree" from "cat" and "tree". 
Input

The first line of input contains a single positive integer from 1 through 1000. It represents the number of data sets to follow. The processing for each data set is identical. The data sets appear on the following lines, one data set per line. 

For each data set, the line of input consists of three strings, separated by a single space. All strings are composed of upper and lower case letters only. The length of the third string is always the sum of the lengths of the first two strings. The first two strings will have lengths between 1 and 200 characters, inclusive. 
Output

For each data set, print: 

Data set n: yes 

if the third string can be formed from the first two, or 

Data set n: no 

if it cannot. Of course n should be replaced by the data set number. See the sample output below for an example. 
Sample Input

3
cat tree tcraete
cat tree catrtee
cat tree cttaree
Sample Output

Data set 1: yes
Data set 2: yes
Data set 3: no

*/


#include <stdio.h>
#include <string.h>
#define N 205
#define true 1
#define false 0

int dp[N][N];
int main()
{
	int i, j, l1, l2, icase, ncase;
	char s1[N], s2[N], ss[2*N];
	scanf("%d", &ncase);

	for(icase = 1;icase <= ncase;icase++)
	{
		scanf("%s %s %s", s1, s2, ss);
		l1 = strlen(s1);
		l2 = strlen(s2);

		memset(dp, false, sizeof(dp));
		dp[0][0] = true;
		for(i = 1;i <= l1;i++)
			if (dp[i-1][0] && s1[i-1] == ss[i-1])
				dp[i][0] = true;
			else
				dp[i][0] = false;

		for(i = 1;i <= l2;i++)
			if (dp[0][i-1] && s2[i-1] == ss[i-1])
				dp[0][i] = true;
			else
				dp[0][i] = false;

		for(i = 1;i <= l1;i++)
			for(j = 1;j <= l2;j++)
			{
				if ((dp[i-1][j] && s1[i-1] == ss[i+j-1])
					|| (dp[i][j-1] && s2[j-1] == ss[i+j-1]))
					dp[i][j] = true;
				else
					dp[i][j] = false;
			}

		if (dp[l1][l2])
			printf("Data set %d: yes\n", icase);
		else
			printf("Data set %d: no\n", icase);	
	}
	return 0;
}
