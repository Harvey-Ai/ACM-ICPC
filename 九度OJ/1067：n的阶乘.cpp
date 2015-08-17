/*
题目描述：
输入一个整数n，输出n的阶乘
输入：
一个整数n(1<=n<=20)
输出：
n的阶乘
样例输入：
3
样例输出：
6
*/


#include <iostream>
#include <cstdio>
using namespace std;
 
int main()
{
    int n;
    while(cin >> n)
    {
        long long res = 1;
        for(int i = 2; i<= n;i++)
            res *= i;
        printf("%lld\n", res);
    }
    return 0;
}
