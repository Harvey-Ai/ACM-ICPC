#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    int arr[100005];
    int n;
    int i;
    scanf("%d", &n);

    for(i = 0;i < n;i++)
        scanf("%d", &arr[i]);
    sort(&arr[0], &arr[n]);

    for(i = 1;i < n;i++)
        if (arr[i] % arr[0] != 0)
            break;
    if (i < n)
        printf("-1\n");
    else
        printf("%d\n", arr[0]);
    return 0;
}
