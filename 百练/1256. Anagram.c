/*
描述
You are to write a program that has to generate all possible words from a given set of letters. 
Example: Given the word "abc", your program should - by exploring all different combination of the three letters - output the words "abc", "acb", "bac", "bca", "cab" and "cba". 
In the word taken from the input file, some letters may appear more than once. For a given word, your program should not produce the same word more than once, and the words should be output in alphabetically ascending order. 
输入
The input consists of several words. The first line contains a number giving the number of words to follow. Each following line contains one word. A word consists of uppercase or lowercase letters from A to Z. Uppercase and lowercase letters are to be considered different. The length of each word is less than 13.
输出
For each word in the input, the output should contain all different words that can be generated with the letters of the given word. The words generated from the same input word should be output in alphabetically ascending order. An upper case letter goes before the corresponding lower case letter.
样例输入
3
aAb
abc
acba
样例输出
Aab
Aba
aAb
abA
bAa
baA
abc
acb
bac
bca
cab
cba
aabc
aacb
abac
abca
acab
acba
baac
baca
bcaa
caab
caba
cbaa
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(char a, char b)
{
	char aa = a, bb = b;
	if (aa >= 'A' && aa <= 'Z')
		aa += 'a' - 'A';
	if (bb >= 'A' && bb <= 'Z')
		bb += 'a' - 'A';
	if (bb != aa)
		return aa < bb ? 1 : 0;
	else
		return a < b ? 1 : 0;
}

int main()
{
	int n;
	char str[200];
	int len;
	cin>>n;

	while(n--)
	{
		cin>>str;
		for(len = 0;str[len] != '\0';len++);
		sort(str, str + len, cmp);
		cout<<str<<endl;
		while(next_permutation(str, str + len, cmp))
			cout<<str<<endl;
	}
	return 0;
}

/*

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int visited[30];
char sstr[30];


void dfs(char *temp, int p, int n)
{
	int i, j;
	if (p == n)
	{
		printf("%s\n", temp);
		return;
	}

	for(i = 0;i < n;i++)
		if (!visited[i])
		{
			visited[i] = 1;
			temp[p] = sstr[i];
			dfs(temp, p + 1, n);
			visited[i] = 0;
			for(j = i + 1;j < n;j++)
				if(sstr[j] != sstr[i])
					break;
			i = j - 1;
		}
}


int cmp(const void * a,const void *b)
{
    char aa = *(char *)a;
    char bb = *(char *)b;
	if (aa >= 'A' && aa <= 'Z')
		aa += 'a' - 'A';
	if (bb >= 'A' && bb <= 'Z')
		bb += 'a' - 'A';
	if (bb != aa)
		return aa - bb;
	else
		return *(char *)a - *(char *)b;
}


int main()
{
	int i;
	int n;
	char temp[30];
	int len;

	scanf("%d", &n);
	while(n--)
	{
		scanf("%s", sstr);
		len = strlen(sstr);
		memset(visited, 0, sizeof(visited));
		qsort(sstr, len, sizeof(sstr[0]), cmp);
		temp[len] = '\0';

		dfs(temp, 0, len);
	}
	return 0;
}
*/
