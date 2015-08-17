#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int graph[105][105];
int friendNum[105];
int friends[105][10];

int cmp(const int &a, const int &b)
{
    if (friendNum[a] > friendNum[b])
        return 1;
    else
        return 0;
}

int main()
{
    int m, n;
    scanf("%d %d", &n, &m);

    memset(graph, 0, sizeof(graph));
    for(int i = 0;i < m;i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;b--;
        graph[a][b] = graph[b][a] = 1;
    }

    for(int k = 0;k < n;k++)
        for(int i = 0;i < n;i++)
        {
            if (i == k)
                continue;
            for(int j = 0;j < n;j++)
            {
                if (j == k || j == i)
                    continue;
                graph[j][i] = graph[i][j] = (graph[i][k] && graph[j][k]) || graph[i][j];
            }
        }
    //printf("kkk%d\n", graph[
   // for(int i = 0;i < n;i++)
   //     printf(" %d", graph[3][i]);
   // putchar('\n');
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
        {
            friendNum[i] += graph[i][j];
            if (graph[i][j] && friendNum[i] < 10)
                friends[i][friendNum[i] - 1] = j;
        }

    int arr[100];
    for(int i = 0;i < n;i++)
        arr[i] = i;
    sort(&arr[0], &arr[n], cmp);
    int ok = 1;
    int n1 = 0, n2 = 0, n3 = 0;
    for(int i = 0;i < n;i++)
        if (friendNum[i] == 0)
        {
           // printf("1 %d\n", i);
            n1++;
        }
        else if (friendNum[i] == 1)
        {
            n2++;
            //printf("2 %d\n", i);
        }
        else if (friendNum[i] == 2)
        {
           // printf("3  %d\n", i);
            n3++;
        }
        else
            ok = 0;

    // printf("%d %d %d\n", n1, n2, n3);
    if (n2 / 2 > n1)
        ok = 0;
    if (ok == 0)
    {
        printf("-1\n");
        return 0;
    }
    else
    {
        int flag[100] = {0};
        int k = n - 1;
        for(int i = 0;i < n;i++)
        {
            if (flag[arr[i]])
                continue;
            if (friendNum[arr[i]] == 2)
            {
                flag[arr[i]] = 1;
                flag[friends[arr[i]][0]] = 1;
                flag[friends[arr[i]][1]] = 1;
               // printf("%d friend %d %d\n", arr[i], friends[arr[i]][0], friends[arr[i]][1]);
                printf("%d %d %d\n", arr[i] + 1, friends[arr[i]][0] + 1, friends[arr[i]][1] + 1);
            }
            else if (friendNum[arr[i]] == 1)
            {
                flag[arr[i]] = 1;
                flag[friends[arr[i]][0]] = 1;
                flag[arr[k]] = 1;
                printf("%d %d %d\n", arr[i] + 1, friends[arr[i]][0] + 1, arr[k] + 1);
                k--;
            }
            else 
            {
                flag[arr[i]] = 1;
                flag[arr[k]] = 1;
                flag[arr[k - 1]] = 1;
                printf("%d %d %d\n", arr[i] + 1, arr[k] + 1, arr[k - 1] + 1);
                k -= 2;
            }
        }
    }
    return 0;
}
