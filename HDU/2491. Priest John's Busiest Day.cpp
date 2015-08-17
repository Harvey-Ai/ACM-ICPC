/*
Problem Description
John is the only priest in his town. October 26th is the John's busiest day in a year because there is an old legend in the town that the couple who get married on that day will be forever blessed by the God of Love. This year N couples plan to get married on the blessed day. The i-th couple plan to hold their wedding from time Si to time Ti. According to the traditions in the town, there must be a special ceremony on which the couple stand before the priest and accept blessings. Moreover, this ceremony must be longer than half of the wedding time and can’t be interrupted. Could you tell John how to arrange his schedule so that he can hold all special ceremonies of all weddings?

Please note that:

John can not hold two ceremonies at the same time.
John can only join or leave the weddings at integral time.
John can show up at another ceremony immediately after he finishes the previous one.
 

Input
The input consists of several test cases and ends with a line containing a zero.


In each test case, the first line contains a integer N ( 1 ≤ N ≤ 100,000) indicating the total number of the weddings.

In the next N lines, each line contains two integers Si and Ti. (0 <= Si < Ti <= 2147483647)
 

Output
For each test, if John can hold all special ceremonies, print "YES"; otherwise, print “NO”.
 

Sample Input
3
1 5
2 4
3 6
2
1 5
4 6
0
 

Sample Output
NO
YES
*/


#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct wedType
{
    long long s, t;
    long long midTime;
};

wedType wedTime[100005];
bool cmp(const wedType &a, const wedType &b)
{
    if (a.midTime < b.midTime || (a.midTime == b.midTime && a.s < b.s))
        return 1;
    else
        return 0;
}

int main()
{
    int n;
    while (cin >> n, n)
    {
        for(int i = 0;i < n;i++)
        {
            scanf("%lld %lld", &wedTime[i].s, &wedTime[i].t);
            wedTime[i].midTime = wedTime[i].s + (wedTime[i].t - wedTime[i].s) / 2 + 1;
        }
        sort(&wedTime[0], &wedTime[n], cmp);
        
        int ok = 1;
        long long nowTime = wedTime[0].s;
        for(int i = 0;i < n;i++)
        {
            long long cerTime = (wedTime[i].t - wedTime[i].s) / 2 + 1;
            if (nowTime < wedTime[i].s)
                nowTime = wedTime[i].s;
            if (nowTime + cerTime > wedTime[i].t)
            {
                ok = 0;
                break;
            }    
            nowTime += cerTime;
        }
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
