/*
Description

In a few months the European Currency Union will become a reality. However, to join the club, the Maastricht criteria must be fulfilled, and this is not a trivial task for the countries (maybe except for Luxembourg). To enforce that Germany will fulfill the criteria, our government has so many wonderful options (raise taxes, sell stocks, revalue the gold reserves,...) that it is really hard to choose what to do. 

Therefore the German government requires a program for the following task: 
Two politicians each enter their proposal of what to do. The computer then outputs the longest common subsequence of words that occurs in both proposals. As you can see, this is a totally fair compromise (after all, a common sequence of words is something what both people have in mind). 

Your country needs this program, so your job is to write it for us.
Input

The input will contain several test cases. 
Each test case consists of two texts. Each text is given as a sequence of lower-case words, separated by whitespace, but with no punctuation. Words will be less than 30 characters long. Both texts will contain less than 100 words and will be terminated by a line containing a single '#'. 
Input is terminated by end of file.
Output

For each test case, print the longest common subsequence of words occuring in the two texts. If there is more than one such sequence, any one is acceptable. Separate the words by one blank. After the last word, output a newline character.
Sample Input

die einkommen der landwirte
sind fuer die abgeordneten ein buch mit sieben siegeln
um dem abzuhelfen
muessen dringend alle subventionsgesetze verbessert werden
#
die steuern auf vermoegen und einkommen
sollten nach meinung der abgeordneten
nachdruecklich erhoben werden
dazu muessen die kontrollbefugnisse der finanzbehoerden
dringend verbessert werden
#
Sample Output

die einkommen der abgeordneten muessen dringend verbessert werden
*/


#include <stdio.h>
#define N 105
#define MaxL 35
int dp[N][N], drect[N][N],res[N];
char s1[N][MaxL], s2[N][MaxL];

int main()
{
	int i, j, k, l1, l2, direction, temp;
	while(scanf("%s", s1[0]) != EOF)
	{
		for(l1 = 1;strcmp(s1[l1-1], "#");l1++)
			scanf("%s", s1[l1]);
		l1--;

		scanf("%s", s2[0]);
		for(l2 = 1;strcmp(s2[l2-1], "#");l2++)
			scanf("%s", s2[l2]);
		l2--;

		memset(dp, 0, sizeof(dp));

		for(i = 1;i <= l1;i++)
			for(j = 1;j <= l2;j++)
			{
				if (strcmp(s1[i -1], s2[j - 1]) == 0)
				{
					temp = dp[i - 1][j - 1] + 1;
					direction = 0;
				}
				else
				{
					temp = dp[i - 1][j - 1];
					direction = 3;
				}
				
				if (dp[i - 1][j] > temp)
				{
					temp = dp[i - 1][j];
					direction = 1;
				}
				if (dp[i][j - 1] > temp)
				{
					temp = dp[i][j - 1];
					direction = 2;
				}
				dp[i][j] = temp;
				drect[i][j] = direction;
			}

		for(k = 0,i = l1, j = l2;i && j;)
			if(drect[i][j] == 0)
			{
				res[k++] = i;
				i--;j--;
			}
			else
			{
				if (drect[i][j] == 1) i--;
				else if (drect[i][j] == 2) j--;
				else
				{
					i--;
					j--;
				}
			}

		while(--k)
			printf("%s ", s1[res[k] - 1]);

		if(k == 0)
			printf("%s", s1[res[0] -1]);
		putchar('\n');
	}
	return 0;
}

