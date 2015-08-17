/*
Problem Description
按要求，给国家进行排名。
 

Input
有多组数据。
第一行给出国家数N，要求排名的国家数M，国家号从0到N-1。
第二行开始的N行给定国家或地区的奥运金牌数，奖牌数，人口数（百万）。
接下来一行给出M个国家号。
 

Output
排序有4种方式: 金牌总数 奖牌总数 金牌人口比例 奖牌人口比例 
对每个国家给出最佳排名排名方式 和 最终排名
格式为: 排名:排名方式
如果有相同的最终排名，则输出排名方式最小的那种排名，对于排名方式，金牌总数 < 奖牌总数 < 金牌人口比例 < 奖牌人口比例 
如果有并列排名的情况，即如果出现金牌总数为 100,90,90,80.则排名为1,2,2,4.
每组数据后加一个空行。
 

Sample Input
4 4
4 8 1
6 6 2
4 8 2
2 12 4
0 1 2 3
4 2
8 10 1
8 11 2
8 12 3
8 13 4
0 3
 

Sample Output
1:3
1:1
2:1
1:2

1:1
1:1
*/

#include <iostream>
#include <algorithm>
using namespace std;

struct tt
{
    int gold, sum, people;
    int index;
    int realtanker;
};

bool cmp1(const struct tt a, const struct tt b)
{
    return a.gold > b.gold ? 1 : 0;
}

bool cmp2(const struct tt a, const struct tt b)
{
    return a.sum > b.sum ? 1 : 0;
}

bool cmp3(const struct tt a, const struct tt b)
{
    return a.gold * b.people > b.gold * a.people ? 1 : 0;
}

bool cmp4(const struct tt a, const struct tt b)
{
    return a.sum * b.people > b.sum * a.people ? 1 : 0;
}

struct tt country1[200000], country2[200000], country3[200000], country4[200000];
int arr[200000];

int main()
{
    int n, m;
    int i, j, a;

    while(cin >> n >> m)
    {
        for(i = 0;i < n;i++)
        {
            cin >> country1[i].gold >> country1[i].sum >> country1[i].people;
            country1[i].index = i;

            country2[i] = country1[i];
            country3[i] = country1[i];
            country4[i] = country1[i];
        }

        for(i = 0;i < m;i++)
            cin >> arr[i];

        for(i = 0;i < n;i++)
        {
            for(j = 0;j < m;j++)
                if (arr[j] == country1[i].index)
                    break;
            if (j == m)
            {
                country1[i].gold = country1[i].sum = -1;
                country1[i].people = 1;
                country2[i] = country1[i];
                country3[i] = country1[i];
                country4[i] = country1[i];

            }
        }

        sort(&country1[0], &country1[n], cmp1);
        sort(&country2[0], &country2[n], cmp2); 
        sort(&country3[0], &country3[n], cmp3); 
        sort(&country4[0], &country4[n], cmp4);


        int pos1, pos2, pos3, pos4;
        pos1 = pos2 = pos3 = pos4 = 1;
        country1[0].realtanker = country2[0].realtanker = country3[0].realtanker = country4[0].realtanker = 1;
        for(i = 1;i < n;i++)
        {
            if (country1[i].gold != country1[i - 1].gold)
                pos1 = i + 1;
            if (country2[i].sum != country2[i - 1].sum)
                pos2 = i + 1;
            if (country3[i].gold * country3[i - 1].people != country3[i - 1].gold * country3[i].people)
                pos3 = i + 1;
            if (country4[i].sum * country4[i - 1].people != country4[i - 1].sum * country4[i].people)
                pos4 = i + 1;
            country1[i].realtanker = pos1;
            country2[i].realtanker = pos2;
            country3[i].realtanker = pos3;
            country4[i].realtanker = pos4;
        }

        for(i = 0;i < m;i++)
        {
            a = arr[i];
            int tanker, pai;
            for(j = 0;j < n;j++)
                if (country1[j].index == a)
                {
                    tanker = country1[j].realtanker;
                    pai = 1;
                }

            for(j = 0;j < n;j++)
                if (country2[j].index == a && country2[j].realtanker < tanker)
                {
                    tanker = country2[j].realtanker;
                    pai = 2;
                }
            for(j = 0;j < n;j++)
                if (country3[j].index == a && country3[j].realtanker < tanker)
                {
                    tanker = country3[j].realtanker;
                    pai = 3;
                }
            for(j = 0;j < n;j++)
                if (country4[j].index == a && country4[j].realtanker < tanker)
                {
                    tanker = country4[j].realtanker;
                    pai = 4;
                }
            cout << tanker << ":" << pai << endl;
        }
        cout << endl;
    }
    return 0;
}
