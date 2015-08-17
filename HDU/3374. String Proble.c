/*
Problem Description
Give you a string with length N, you can generate N strings by left shifts. For example let consider the string “SKYLONG”, we can generate seven strings:
String Rank 
SKYLONG 1
KYLONGS 2
YLONGSK 3
LONGSKY 4
ONGSKYL 5
NGSKYLO 6
GSKYLON 7
and lexicographically first of them is GSKYLON, lexicographically last is YLONGSK, both of them appear only once.
  Your task is easy, calculate the lexicographically fisrt string’s Rank (if there are multiple answers, choose the smallest one), its times, lexicographically last string’s Rank (if there are multiple answers, choose the smallest one), and its times also.
 

Input
  Each line contains one line the string S with length N (N <= 1000000) formed by lower case letters.
 

Output
Output four integers separated by one space, lexicographically fisrt string’s Rank (if there are multiple answers, choose the smallest one), the string’s times in the N generated strings, lexicographically last string’s Rank (if there are multiple answers, choose the smallest one), and its times also.
 

Sample Input
abcder
aaaaaa
ababab
 

Sample Output
1 1 6 1
1 6 1 6
1 3 2 3

*/


#include <stdio.h>
#include <string.h>
#define N 1000005
int p[N];
char sstr[N], stemp[N], ss[2*N];

void pre(char *str, int len)
{
	int i, k = 0;
	p[0] = 0;
	for(i = 1;i < len;i++)
	{
		while(k > 0 && str[i] != str[k])
			k = p[k-1];
		if (str[k] == str[i])
			k++;
		p[i] = k;
	}
}
int kmp(char *mStr, int mLen, char *str, int len)
{
	int i, k = 0, count = 0;
	pre(str, len);
	for(i = 0;i < mLen;i++)
	{
		while(k > 0 && mStr[i] != str[k])
			k = p[k-1];
		if (str[k] == mStr[i])
		{	
			k++;
			if (k == len)
			{
				count++;
				k = p[k-1];
			}
		}
	}
	return count;
}

int findMin(char *s, int len, int subLen)
{
	int k, p1, p2;
	p1 = 0;
	p2 = 1;

	while(1)
	{
		for(k = 0;k < subLen;k++)
			if ( s[p1+k] != s[p2+k])
				break;
		if (k == subLen)
			break;
		else
		{
			if (s[p1+k] > s[p2+k])
			{
				p1 += k+1;
				if (p1 == p2)	p1++;
			}
			else
			{
				p2 += k+1;
				if (p1 == p2)	p2++;
			}
		}
		if (p1 >= subLen || p2 >= subLen)
			break;
	}
	return p1 > p2 ? p2 : p1;
}

int findMax(char *s, int len, int subLen)
{
	int k, p1, p2;
	p1 = 0;
	p2 = 1;

	while(1)
	{
		for(k = 0;k < subLen;k++)
			if ( s[p1+k] != s[p2+k])
				break;
		if (k == subLen)
			break;
		else
		{
			if (s[p1+k] < s[p2+k])
			{
				p1 += k+1;
				if (p1 == p2)	p1++;
			}
			else
			{
				p2 += k+1;
				if (p1 == p2)	p2++;
			}
		}
		if (p1 >= len || p2 >= len)
			break;
	}
	return p1 > p2 ? p2 : p1;
}
int main()
{
	int len, pos, num;
	while(scanf("%s", sstr) != EOF)
	{
		len = strlen(sstr);
		memcpy(ss, sstr, len);
		memcpy(ss + len, sstr, len - 1);
		ss[2*len-1] = '\0';
		//caclulate min
		pos = findMin(ss, len * 2 - 1, len);
		printf("%d ", pos + 1);
		memcpy(stemp, ss + pos, len);
		stemp[len] = '\0';
		num = kmp(ss, 2 * len - 1, stemp, len);
		printf("%d ", num);
		//caclulate max
		pos = findMax(ss, len * 2 - 1, len);
		printf("%d ", pos + 1);
		memcpy(stemp, ss + pos, len);
		stemp[len] = '\0';
		num = kmp(ss, 2 * len - 1, stemp, len);
		printf("%d\n", num);
	}
	return 0;
}
