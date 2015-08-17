#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int arr[10000];
//double table[5000][5000];
int layer;

int initD()
{
    arr[0] = 0;
    for(layer = 1;;layer++)
    {
        arr[layer] = arr[layer - 1] + 4 * (layer - 1) + 1;
        if (arr[layer] > 1000006)
            break;
    }
}


int main()
{
    initD();
    int ncase;
    //freopen("1.txt",  "r", stdin);
    //freopen("out.txt","w", stdin);
    scanf("%d", &ncase);
    for(int icase = 1;icase <= ncase;icase++)
    {
        int n, x, y;
        scanf("%d %d %d", &n, &x, &y);

        int cen;
        for(cen = 1;;cen++)
            if (arr[cen] >= n)
                break;

        int left = n - arr[cen - 1];
        if (fabs(x) + fabs(y) != (cen - 1) * 2 || left < fabs(y))
        {
            printf("Case #%d: 0.0\n", icase);
            continue;
        }

        if (fabs(x) + fabs(y) < (cen - 1) * 2 )
        {
            printf("Case #%d: 1.0\n", icase);
            continue;
        }

        if (left == (cen - 1) * 4 + 1 && fabs(x) + fabs(y) == (cen - 1) * 2 )
        {
            printf("Case #%d: 1.0\n", icase);
            continue;
        }
        
        double res = 0.0;
        int begin = (y + 1), end = (cen - 1) * 2;
        if (left > end + begin)
            begin = left - end;

        printf("%d %d %d\n", begin, end, left);
        for(int i = begin;i <= end;i++)
        {
            int j = i, k = left - i;
            
            double temp = 1;
            for(int l = 1;l <= j;l++)
            {
                temp *= (left - l + 1);
                temp /= l;
                temp *= 0.5;
            }/*
            for(int l = 1;l <= k;l++)
            {
                temp *= (left - l + 1);
                temp /= l;
                temp *= 0.5;
            }*/
            res += temp;
        }
        printf("Case #%d: %0.6lf\n", icase, res);
    }
    return 0;
}
