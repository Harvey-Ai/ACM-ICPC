/*
Description

As we known, data stored in the computers is in binary form. The problem we discuss now is about the positive integers and its binary form. 

Given a positive integer I, you task is to find out an integer J, which is the minimum integer greater than I, and the number of '1's in whose binary form is the same as that in the binary form of I. 

For example, if "78" is given, we can write out its binary form, "1001110". This binary form has 4 '1's. The minimum integer, which is greater than "1001110" and also contains 4 '1's, is "1010011", i.e. "83", so you should output "83".
Input

One integer per line, which is I (1 <= I <= 1000000). 

A line containing a number "0" terminates input, and this line need not be processed.
Output

One integer per line, which is J.
Sample Input

1
2
3
4
78
0
Sample Output

2
4
5
8
83
*/



#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int shift1 = 0x55555555, shift2 = 0xAAAAAAAA;
int shift3 = 0x33333333, shift4 = 0xCCCCCCCC;
int shift5 = 0x0F0F0F0F, shift6 = 0xF0F0F0F0;
int shift7 = 0x00FF00FF, shift8 = 0xFF00FF00;
int shift9 = 0x0000FFFF, shift10 = 0xFFFF0000;

int getOneNum(int c)
{
	c = (c & shift1) + ((c & shift2) >> 1);
	c = (c & shift3) + ((c & shift4) >> 2);
	c = (c & shift5) + ((c & shift6) >> 4);
	c = (c & shift7) + ((c & shift8) >> 8);
	c = (c & shift9) + ((c & shift10) >> 16);
	return c;
}

int main()
{
	int n;

	while(scanf("%d", &n), n)
	{
		int oneNum = getOneNum(n);

		int temp = getOneNum(++n);
		while(temp != oneNum)
			temp = getOneNum(++n);	
		cout << n << endl;
	}
	return 0;
}
