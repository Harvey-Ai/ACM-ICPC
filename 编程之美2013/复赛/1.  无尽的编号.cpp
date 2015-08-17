/*
描述

在一条公路上，将要依次建造N座建筑。在每个建筑建成之后，都会用一个01串来给它编号。整条公路从起点到终点，所有建筑的编号都严格按照字典序递增的顺序来排列，而每在一个新的地方建起一个建筑时，它的编号会按以下规则确定：

1) 编号要比前一个建筑（起点方向）的字典序大，比后一个建筑（终点方向）的字典序小

3) 编号一定以1结尾

2) 编号要尽可能短，满足该条件时，字典序尽可能小

最开始时，公路的起点和终点上各有一个建筑，编号分别是0和1。接下来依次给出N个坐标 a1, a2, ..., aN，依次表示下一个建筑将要建造的位置，最后要问，当所有建筑建成时，这些建筑的编号总长度是多少，其中又出现了多少个字符1。所有建筑都在公路起点和终点之间，并且没有两个建筑建在同一个位置。

输入

输入文件包含多组测试数据。

第一行，给出一个整数T，为数据组数。接下来依次给出每组测试数据。

每组数据中第一行为一个整数 N，表示将要建造的建筑数量，第二行是用单个空格隔开的N个互不相同的整数 a1, a2, ..., aN，表示依次将要建造的建筑所在的坐标。

输出

对于每组测试数据，输出一行"Case #X: Y Z"，其中X表示测试数据编号，Y表示所有建筑编号总长，Z表示所有编号中字符1的数量。所有建筑包括起点和终点的这两个建筑。所有数据按读入顺序从1开始编号。

数据范围

小数据：T ≤ 100, 0 < N ≤ 100, 0 ≤ ai ≤ 1000

大数据：T ≤ 10, 0 < N ≤ 50000, 0 ≤ ai ≤ 500000

 

样例输入

1

5

1 2 3 4 5

样例输出

Case #1: 22 16

*/


#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int compareStr(char *s1, char *s2)
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int i1, i2;
    for(i1 = 0, i2 = 0;i1 < len1 && i2 < len2;i1++, i2++)
    {
        if (s1[i1] > s2[i2])
            return 1;
        else if (s1[i1] < s2[i2])
            return -1;
    }

    if (i1 < len1)
        return 1;
    else if (i2 < len2)
        return -1;
    return 0;
}

int convertZ(char *str)
{
    int len = strlen(str);
    int i;
    for(i = len - 1;i >= 0;i--)
        if (str[i] == '0')
        {
            str[i] = '1';
            break;
        }
    if (i >= 0)
        return true;
    else
        return false;
}

int calOne(char *str)
{
    int len = strlen(str);
    int oneNum = 0;
    for(int i = 0;i < len;i++)
        if (str[i] == '1')
            oneNum++;
    return oneNum;
}

char arrStr[50005][1000];
char str[1000];
int flag[50005][2];

int main()
{
    int ncase;
    scanf("%d", &ncase);
    for(int icase = 1;icase <= ncase;icase++)
    {
        memset(flag, -1, sizeof(flag));
        int n;
        scanf("%d", &n);
        flag[0][0] = 0;flag[0][1] = 0;
        flag[n + 1][1] = n + 1;flag[n + 1][0] = n + 1;
        strcpy(arrStr[0], "0");
        strcpy(arrStr[n + 1], "1");

        int digNum = 0;
        int oneNum = 0;
        for(int i = 0;i < n;i++)
        {
            int a;
            scanf("%d", &a);
            int k;
            if (flag[a][0] == -1)
            {
                for(k = a - 1;flag[k][0] == -1;k--)
                    flag[k][1] = a;
                flag[a][0] = flag[k][0];
                flag[k][1] = a;
            }
            if (flag[a][1] == -1)
            {
                for(k = a + 1;flag[k][1] == -1;k++)
                    flag[k][0] = a;
                flag[a][1] = flag[k][1];
                flag[k][0] = a;
            }

            strcpy(str, arrStr[flag[a][0]]);
            printf("left %d right %d\n", flag[a][0], flag[a][1]);
            int conRes = convertZ(str);
            if (!conRes || compareStr(str, arrStr[flag[a][1]]) >= 0)
            {
                int addZ = 1;
                strcpy(str, arrStr[flag[a][0]]);
                int ll = strlen(str);
               // printf("str %s\n", str);
                str[ll] = '1';
                str[ll + 1] = '\0';

                while(compareStr(str, arrStr[flag[a][1]]) >= 0)
                {
                    for(int i = 0;i < addZ;i++)
                        str[ll + i] = '0';
                    str[ll + addZ] = '1';
                    str[ll + addZ + 1] = '\0';
                    addZ++;
                }
            }
            strcpy(arrStr[a], str);
            printf("%s\n", str);
            digNum += strlen(str);
            oneNum += calOne(str);
        }
        printf("Case #%d: %d %d\n", icase, digNum + 2, oneNum + 1);
    }
    return 0;

}

