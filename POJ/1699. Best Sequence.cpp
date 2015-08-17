/*
Description

The twenty-first century is a biology-technology developing century. One of the most attractive and challenging tasks is on the gene project, especially on gene sorting program. Recently we know that a gene is made of DNA. The nucleotide bases from which DNA is built are A(adenine), C(cytosine), G(guanine), and T(thymine). Given several segments of a gene, you are asked to make a shortest sequence from them. The sequence should use all the segments, and you cannot flip any of the segments. 

For example, given 'TCGG', 'GCAG', 'CCGC', 'GATC' and 'ATCG', you can slide the segments in the following way and get a sequence of length 11. It is the shortest sequence (but may be not the only one). 


Input

The first line is an integer T (1 <= T <= 20), which shows the number of the cases. Then T test cases follow. The first line of every test case contains an integer N (1 <= N <= 10), which represents the number of segments. The following N lines express N segments, respectively. Assuming that the length of any segment is between 1 and 20.
Output

For each test case, print a line containing the length of the shortest sequence that can be made from these segments.
Sample Input

1
5
TCGG
GCAG
CCGC
GATC
ATCG
Sample Output

11
*/


#include <iostream>
#include <string>
using namespace std;

int n;
int dp[1 << 10][15];
int graph[15][15];
string segStr[15];

int maxSimilar(string a, string b)
{
    for(int k = 0;k < a.size();k++)
    {
        int i;
        for(i = 0; i < b.size() && (i + k) < a.size();i++)
            if (a[i + k] != b[i])
                break;
        if (i == b.size() || (i + k) == a.size())
            return i;
    }
    return 0;
}

void dfs(int status, int cur, int val)
{
    if (dp[status][cur] != -1 && dp[status][cur] < val)
        return;


    dp[status][cur] = val;
    for(int i = 0;i < n;i++)
    {
        if (status & (1 << i))
            continue;
        
        if (graph[cur][i] == segStr[i].size())
            dfs(status | (1 << i), cur, val);
        else
            dfs(status | (1 << i), i, val + segStr[i].size() - graph[cur][i]);
    }
}


int main()
{
    int ncase;
    cin >> ncase;

    while(ncase--)
    {
        cin >> n;
        for(int i = 0;i < n;i++)
            cin >> segStr[i];

        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++)
                graph[i][j] = maxSimilar(segStr[i], segStr[j]);
            
        for(int i = 0;i < (1 << n);i++)
            for(int j = 0;j < n;j++)
                dp[i][j] = -1;

        for(int i = 0;i < n;i++)
            dfs(1 << i, i, segStr[i].size());

        int res = 100000;
        for(int i = 0;i < n;i++)
            if (dp[(1 << n) - 1][i] < res && dp[(1 << n) - 1][i] != -1)
                res = dp[(1 << n) - 1][i];
        cout << res << endl;
    }
    return 0;
}
