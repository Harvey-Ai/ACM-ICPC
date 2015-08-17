/*
Description

Given two strings a and b we define a*b to be their concatenation. For example, if a = "abc" and b = "def" then a*b = "abcdef". If we think of concatenation as multiplication, exponentiation by a non-negative integer is defined in the normal way: a^0 = "" (the empty string) and a^(n+1) = a*(a^n).
Input

Each test case is a line of input representing s, a string of printable characters. The length of s will be at least 1 and will not exceed 1 million characters. A line containing a period follows the last test case.
Output

For each s you should print the largest n such that s = a^n for some string a.
Sample Input

abcd
aaaa
ababab
.
Sample Output

1
4
3
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char str[1000006];
int next[1000006];
int strLen;

void getNext()
{
	int k = -1;
	next[0] = -1;

	for(int i = 1;i < strLen;i++)
	{
		while(k >= 0 && str[i] != str[k + 1])
			k = next[k];

		if (str[i] == str[k + 1])
			k++;
		next[i] = k;
	}
}

int main()
{
	while(scanf("%s", str))
	{
        if (str[0] == '.')
            break;
		strLen = strlen(str);		
		getNext();
		if (strLen % (strLen - next[strLen - 1] - 1) == 0)
			cout << strLen / (strLen - next[strLen - 1] - 1) << endl;
		else
			cout << 1 << endl;
	}

	return 0;
}
