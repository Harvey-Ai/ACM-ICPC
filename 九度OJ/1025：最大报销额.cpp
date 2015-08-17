/*
题目描述：
    现有一笔经费可以报销一定额度的发票。允许报销的发票类型包括买图书（A类）、文具（B类）、差旅（C类），要求每张发票的总额不得超过1000元，每张发票上，单项物品的价值不得超过600元。现请你编写程序，在给出的一堆发票中找出可以报销的、不超过给定额度的最大报销额。
输入：
    测试输入包含若干测试用例。每个测试用例的第1行包含两个正数 Q 和 N，其中 Q 是给定的报销额度，N（N<=30）是发票张数。随后是 N 行输入，每行的格式为：
    m Type_1:price_1 Type_2:price_2 ... Type_m:price_m
    其中正整数 m 是这张发票上所开物品的件数，Type_i 和 price_i 是第 i 项物品的种类和价值。物品种类用一个大写英文字母表示。当N为0时，全部输入结束，相应的结果不要输出。
输出：
    对每个测试用例输出1行，即可以报销的最大数额，精确到小数点后2位。
样例输入：
200.00 3
2 A:23.50 B:100.00
1 C:650.00
3 A:59.99 A:120.00 X:10.00
1200.00 2
2 B:600.00 A:400.00
1 C:200.50
1200.50 3
2 B:600.00 A:400.00
1 C:200.50
1 A:100.00
100.00 0
样例输出：
123.50
1000.00
1200.50

*/

#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
 
int flag[3000005];
int main()
{
    double moneyBound;
    int n;
 
    while(scanf("%lf %d", &moneyBound, &n), n)
    {
        vector<int> ticketArr;
        for(int i = 0;i < n;i++)
        {
            int m;
            scanf("%d", &m);
            int ok = true;
            double sum = 0;
            while(m--)
            {
                char c;
                double money;
                getchar();
                scanf("%c:%lf", &c, &money);
                sum += money;
                if (money > 600 || sum > 1000 || !(c == 'A' || c == 'B' || c == 'C'))
                    ok = false;
            }
            if (ok)
                ticketArr.push_back(int(sum * 100));
        }
         
        vector<int> moneyArr;
        moneyArr.push_back(0);
        memset(flag, 0, sizeof(flag));
        for(int i = 0;i < ticketArr.size();i++)
        {
            int moneySize = moneyArr.size();
            for(int j = 0;j < moneySize;j++)
            {
                int money = ticketArr[i] + moneyArr[j];
                if (money <= moneyBound * 100 && !flag[money])
                {
                    moneyArr.push_back(money);
                    flag[money] = 1;
                }
            }
        }
 
        int maxMoney = 0;
        for(int i = 0;i < moneyArr.size();i++)
            maxMoney = max(maxMoney, moneyArr[i]);
 
        printf("%.2lf\n", maxMoney / 100.0);
    }
 
    return 0;
}
