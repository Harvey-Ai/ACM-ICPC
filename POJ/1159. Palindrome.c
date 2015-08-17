/*
Description

A palindrome is a symmetrical string, that is, a string read identically from left to right as well as from right to left. You are to write a program which, given a string, determines the minimal number of characters to be inserted into the string in order to obtain a palindrome. 

As an example, by inserting 2 characters, the string "Ab3bd" can be transformed into a palindrome ("dAb3bAd" or "Adb3bdA"). However, inserting fewer than 2 characters does not produce a palindrome. 
Input

Your program is to read from standard input. The first line contains one integer: the length of the input string N, 3 <= N <= 5000. The second line contains one string with length N. The string is formed from uppercase letters from 'A' to 'Z', lowercase letters from 'a' to 'z' and digits from '0' to '9'. Uppercase and lowercase letters are to be considered distinct.
Output

Your program is to write to standard output. The first line contains one integer, which is the desired minimal number.
Sample Input

5
Ab3bd
Sample Output

2
*/


#include <stdio.h>
#include <string.h>
#define N 5005
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int dp[2][N];
int reverse(char *s1, int l, char *s2)
{
	int i;
	for(i = 0;i < l;i++)
		s2[l-1-i] = s1[i];
	return 1;
}
int main()
{
	char s1[N], s2[N];
	int i, j, l, pre, now, temp;

	scanf("%d", &l);
	scanf("%s", s1);

	reverse(s1, l, s2);

	memset(dp, 0, sizeof(dp));
	pre = 0;
	now = 1;

	for(i = 1;i <= l;i++)
	{
		for(j = 1;j <= l;j++)
		{
			if (s1[i -1] == s2[j - 1])
				temp = dp[pre][j - 1] + 1;
			else
				temp = dp[pre][j - 1];

			temp = MAX(temp, MAX(dp[pre][j], dp[now][j - 1]));
			dp[now][j] = temp;
		}
		temp = pre;
		pre = now;
		now = temp;
	}

	printf("%d\n", l-dp[pre][l]);
	return 0;
}
