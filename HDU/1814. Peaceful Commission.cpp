/*
Problem Description
The Public Peace Commission should be legislated in Parliament of The Democratic Republic of Byteland according to The Very Important Law. Unfortunately one of the obstacles is the fact that some deputies do not get on with some others. 

The Commission has to fulfill the following conditions: 
1.Each party has exactly one representative in the Commission, 
2.If two deputies do not like each other, they cannot both belong to the Commission. 

Each party has exactly two deputies in the Parliament. All of them are numbered from 1 to 2n. Deputies with numbers 2i-1 and 2i belong to the i-th party . 

Task 
Write a program, which: 
1.reads from the text file SPO.IN the number of parties and the pairs of deputies that are not on friendly terms, 
2.decides whether it is possible to establish the Commission, and if so, proposes the list of members, 
3.writes the result in the text file SPO.OUT. 
 

Input
In the first line of the text file SPO.IN there are two non-negative integers n and m. They denote respectively: the number of parties, 1 <= n <= 8000, and the number of pairs of deputies, who do not like each other, 0 <= m <=2 0000. In each of the following m lines there is written one pair of integers a and b, 1 <= a < b <= 2n, separated by a single space. It means that the deputies a and b do not like each other. 
There are multiple test cases. Process to end of file. 
 

Output
The text file SPO.OUT should contain one word NIE (means NO in Polish), if the setting up of the Commission is impossible. In case when setting up of the Commission is possible the file SPO.OUT should contain n integers from the interval from 1 to 2n, written in the ascending order, indicating numbers of deputies who can form the Commission. Each of these numbers should be written in a separate line. If the Commission can be formed in various ways, your program may write mininum number sequence. 
 

Sample Input
3 2
1 3
2 4
 

Sample Output
1
4
5

*/

#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

#define maxn 20000
#define W 0
#define R 1
#define B 2
int n, m;
vector<int> mp[maxn];
int color[maxn];
// 用于存储尝试染色的结点
// 若失败则全部还原回白色
int temp[maxn], num;

bool dfs(int u)
{
    if(color[u] == R)
        return true;
    if(color[u] == B)
        return false;
    // 结点未染色，试着染成红色并记录
    color[u] = R;
    // 同组另一结点肯定淘汰了，蓝色
    color[((u-1)^1)+1] = B;
    temp[num++] = u;
    // 按照当前节点继续染色，看看是否会冲突
    // 冲突则代表当前这种染色办法不行
    // 那么就凭刚才做记录的temp数组还原结点(染白)
    for(int i = 0; i < mp[u].size(); i++)
    {
        if(!dfs(mp[u][i]))
            return false;
    }
    return true;
}

bool solve()
{
    memset(color, W, sizeof(color));
    for(int i = 1; i <= 2*n; i++)
    {
        // 此节点未访问过，试着染色
        if(color[i] == W)
        {
            num = 0;
            // 若染色失败
            if(!dfs(i))
            {
                // 凭着染色时的记录，全部还原回白色
                for(int j = 0; j < num; j++)
                {
                    color[temp[j]] = W;
                    color[((temp[j]-1)^1)+1] = W;
                }
                // 如果同组另一节点又失败了
                // 同组两个都不能选，无解
                if(!dfs(((i-1)^1)+1))
                    return false;
            }
        }
    }
    return true;
}

int main()
{
    int a, b;
    while(~scanf("%d%d", &n, &m))
    {
        for(int i = 1; i <= 2*n; i++)
        {
            mp[i].clear();
        }
        for(int i = 1; i <= m; i++)
        {
            scanf("%d%d", &a, &b);
            mp[a].push_back(((b-1)^1)+1);
            mp[b].push_back(((a-1)^1)+1);
        }

        if(solve())
        {
            for(int i = 1; i <= 2*n; i++)
            {
                if(color[i] == R)
                    printf("%d\n", i);
            }
        }
        else
        {
            printf("NIE\n");
        }
    }
    return 0;
}
