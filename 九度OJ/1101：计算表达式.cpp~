/*
题目描述：
对于一个不存在括号的表达式进行计算
输入：
存在多种数据，每组数据一行，表达式不存在空格
输出：
输出结果
样例输入：
6/2+3+3*4
样例输出：
18
*/

#include <iostream>
using namespace std;
 
int ying(char *s, int *pos)
{
    int a = 0;
    while(s[*pos] >= '0' && s[*pos] <= '9')
    {
        a *= 10;
        a += s[*pos] - '0';
        (*pos)++;
    }
    return a;
}
 
int xiang(char *s, int *pos)
{
    int b = *pos;
    int res1 = ying(s, &b);
    while (s[b] == '*' || s[b] == '/')
    {
        if (s[b] == '*')
        {
            b++;
            res1 *= ying(s, &b);
        }
        else
        {
            b++;
            res1 /= ying(s, &b);
        }
    }
    *pos = b;
    return res1;
}
 
int work(char *s, int pos)
{
    int res1 = xiang(s, &pos);
//  cout << res1 << endl;
//  cout << s[pos] << endl;
    while (s[pos] == '+' || s[pos] == '-') 
    {
        if (s[pos] == '+')
        {
            pos++;
            int res2 = xiang(s, &pos);
        //  cout << res2 << endl;
            res1 += res2;
        }
        else
        {
            pos++;
            res1 -= xiang(s, &pos);
        }
    }
    return res1;
}
 
int main()
{
    char str[100];
    while(cin >> str)
    {
        int res = work(str, 0);
        cout << res << endl;
    }
    return 0;
}
