/*
题目描述：
输入任意4个字符(如：abcd)， 并按反序输出(如：dcba)
输入：
题目可能包含多组用例，每组用例占一行，包含4个任意的字符。
输出：
对于每组输入,请输出一行反序后的字符串。
具体可见样例。
样例输入：
Upin
cvYj
WJpw
cXOA
样例输出：
nipU
jYvc
wpJW
AOXc
*/

#include <iostream>
#include <cstdio>
using namespace std;
 
int main()
{
    char str1[10];
    while(scanf("%s", str1) != EOF)
        printf("%c%c%c%c\n", str1[3], str1[2], str1[1], str1[0]);
    return 0;
}
