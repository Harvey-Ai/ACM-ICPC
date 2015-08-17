#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[10006];
int main()
{
    int ncase;
    freopen("1.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &ncase);

    for(int icase = 1;icase <= ncase;icase++)
    {
        int a, n;
        scanf("%d %d", &a, &n);
        for(int i = 0;i < n;i++)
            scanf("%d", &arr[i]);
        sort(&arr[0], &arr[n]);

        int res = n;
        for(int i = 0;i <= n;i++)
        {
            int weight = a;
            int temp = n - i;
            for(int j = 0;j < i;j++)
            {
                while (weight <= arr[j])
                {
                    temp++;
                    weight += weight - 1;
                    if (weight == 1)
                    {
                        temp = n + 1;
                        break;
                    }
                }
                if (weight <= arr[j])
                    break;
                weight += arr[j];
            }
            if (temp < res)
                res = temp;
        }
        printf("Case #%d: %d\n", icase, res);
    }
    return 0;
}
