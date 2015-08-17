/*
Problem Description
对于表达式n^2+n+41，当n在（x,y）范围内取整数值时（包括x,y）(-39<=x<y<=50)，判定该表达式的值是否都为素数。
 

Input
输入数据有多组，每组占一行，由两个整数x，y组成，当x=0,y=0时，表示输入结束，该行不做处理。
 

Output
对于每个给定范围内的取值，如果表达式的值都为素数，则输出"OK",否则请输出“Sorry”,每组输出占一行。
 

Sample Input
0 1
0 0
 

Sample Output
OK
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 3000
char is[N],prm[N];
int getprm(int n)
{
    int i, j, k = 0;
    int s, e = (int)(sqrt(0.0 + n) + 1);
    memset(is, 1, sizeof(is));
    prm[k++] = 2; is[0] = is[1] = 0;
    for (i = 4; i < n; i += 2) is[i] = 0;
    for (i = 3; i < e; i += 2) if (is[i]) {
        prm[k++] = i;
        for (s = i * 2, j = i * i; j < N; j += s) is[j] = 0;
    }
    for ( ; i < n; i += 2) if (is[i]) prm[k++] = i;
    return k;               // 返回素数的个数
}
int main()
{
    int i,x,y;
    getprm(N);
    while(scanf("%d%d",&x,&y),x||y)
    {
        for(i=x;i<=y;i++)
            if(is[i*i+i+41]==0)
                break;
        if(i<=y)
            printf("Sorry\n");
        else
            printf("OK\n");
    }
    return 0;
}
