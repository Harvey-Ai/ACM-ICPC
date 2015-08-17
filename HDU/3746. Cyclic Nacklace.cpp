/*
Problem Description
CC always becomes very depressed at the end of this month, he has checked his credit card yesterday, without any surprise, there are only 99.9 yuan left. he is too distressed and thinking about how to tide over the last days. Being inspired by the entrepreneurial spirit of "HDU CakeMan", he wants to sell some little things to make money. Of course, this is not an easy task.

As Christmas is around the corner, Boys are busy in choosing christmas presents to send to their girlfriends. It is believed that chain bracelet is a good choice. However, Things are not always so simple, as is known to everyone, girl's fond of the colorful decoration to make bracelet appears vivid and lively, meanwhile they want to display their mature side as college students. after CC understands the girls demands, he intends to sell the chain bracelet called CharmBracelet. The CharmBracelet is made up with colorful pearls to show girls' lively, and the most important thing is that it must be connected by a cyclic chain which means the color of pearls are cyclic connected from the left to right. And the cyclic count must be more than one. If you connect the leftmost pearl and the rightmost pearl of such chain, you can make a CharmBracelet. Just like the pictrue below, this CharmBracelet's cycle is 9 and its cyclic count is 2:


Now CC has brought in some ordinary bracelet chains, he wants to buy minimum number of pearls to make CharmBracelets so that he can save more money. but when remaking the bracelet, he can only add color pearls to the left end and right end of the chain, that is to say, adding to the middle is forbidden.
CC is satisfied with his ideas and ask you for help.
 

Input
The first line of the input is a single integer T ( 0 < T <= 100 ) which means the number of test cases.
Each test case contains only one line describe the original ordinary chain to be remade. Each character in the string stands for one pearl and there are 26 kinds of pearls being described by 'a' ~'z' characters. The length of the string Len: ( 3 <= Len <= 100000 ).
 

Output
For each case, you are required to output the minimum count of pearls added to make a CharmBracelet.
 

Sample Input
3
aaa
abca
abcde
 

Sample Output
0
2
5

*/


#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char str[100005];
int next[100005];
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
	int ncase;
	cin >> ncase;

	while(ncase--)
	{
		scanf("%s", str);
		strLen = strlen(str);
		getNext();

		if (next[strLen - 1] == -1)
			cout << strLen << endl;
		else
		{
			int cirLen = strLen - next[strLen - 1] - 1;
			if (strLen % cirLen)
				cout << cirLen - (strLen % cirLen) << endl;
			else
				cout << 0 << endl;
		}
	}
	return 0;
}
