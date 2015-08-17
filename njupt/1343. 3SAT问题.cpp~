/*
Description
 

SAT的一个实例是k个布尔变量1 x ，…， k x 的m个布尔表达式1 A ，…， m A 。若存在各布尔变量i x (1≤i≤k)的0，1 赋值，使每个布尔表达式i A (1≤i≤m)都取值1，则称布尔表达式1 A 2 A … m A 是可满足的。

★ 合取范式的可满足性问题CNF-SAT

如果一个布尔表达式是一些因子和之积，则称之为合取范式，简称CNF(ConjunctiveNormal Form)。这里的因子是变量x或x。例如( )( )( ) 1 2 2 3 1 2 3 x + x x + x x + x + x 就是一个合取范式，而1 2 3 x x + x 就不是合取范式。

★ k-SAT

如果一个布尔合取范式的每个乘积项最多是k个因子的析取式，就称之为k元合取范式，简记为k-CNF。一个k-SAT问题是判定一个k-CNF是否可满足。特别地，当k=3 时，3-SAT问题在NP完全问题树中具有重要地位。

★ MAX-SAT

给定k个布尔变量1 x ，…， k x 的m个布尔表达式1 A ，…， m A ，求各布尔变量i x (1≤i≤k)的0，1 赋值，使尽可能多的布尔表达式i A 取值1。

★ Weighted-MAX-SAT

给定k个布尔变量1 x ，…， k x 的m个布尔表达式1 A ，…， m A ，每个布尔表达式i A 都有一个权值wi，求各布尔变量i x (1≤i≤k)的0，1赋值，使取值1 的布尔表达式权值之和达到最大。

对于给定的带权3-CNF，设计一个蒙特卡罗算法，使其权值之和尽可能大。



Input

 输入数据的第一行有2个正整数k和m，分别表示变量数和布尔表

达式数。接下来的m行中，每行有5 个整数w,i,j,k,0，表示相应表达式的权值为w，表达式含的变量下标分别为i,j,k，行末以0 结尾。下标为负数时，表示相应的变量为取反变量。

Output

 输出计算出的最大权值

Sample Input
5 3
9 3 1 4 0
9 1 -5 3 0
8 2 -5 1 0

Sample Output
26
*/


#include <iostream>
#include <cstdio>
#include <ctime>
#include <vector>
#include <cstdlib>
using namespace std;

struct expType
{
    int v1, v2, v3;
    int weight;
    expType(int i, int j, int k, int w)
    {
        v1 = i;
        v2 = j;
        v3 = k;
        weight = w;
    }
};

vector<int> choosed;
vector<expType> exps;

int main()
{
    int n, m;
    
    //ifstream input("input.txt", ios::in); 
    cin>>n>>m;
        choosed.clear();
        choosed.resize(n + 1);
        for(int i = 0;i < m;i++)
        {
            int w, ii, jj, kk, temp;
           cin >> w >> ii >> jj >> kk >> temp;
            // scanf("%d %d %d %d %d", &w, &ii, &jj, &kk, &temp);
            exps.push_back(expType(ii, jj, kk, w));
        }

        int maxWeight = 0;
        srand((unsigned int)time(NULL));
        while(1)
        {
            for(int i = 1;i <= n;i++)
                choosed[i] = rand() % 2;

            int sum = 0;
            for(int i = 0;i < m;i++)
            {
                int v1 = exps[i].v1;
                int v2 = exps[i].v2;
                int v3 = exps[i].v3;
                if ((v1 > 0 && choosed[v1]) || (v2 > 0 && choosed[v2]) || (v3 > 0 && choosed[v3]))
                    sum += exps[i].weight;
                else if ((v1 < 0 && !choosed[-v1]) || (v2 < 0 && !choosed[-v2]) || (v3 < 0 && !choosed[-v3]))
                    sum += exps[i].weight;
            }
            if (sum == maxWeight)
                break;
            if (maxWeight < sum)
                maxWeight = sum;
        }
       // printf("%d", maxWeight);
    //   ofstream output("output.txt", ios::out);
       cout << maxWeight << endl;
    

    return 0;
}
