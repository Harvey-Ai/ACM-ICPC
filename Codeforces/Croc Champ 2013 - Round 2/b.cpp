#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n, k;
    char str[1000000];
    scanf("%d %d\n", &n, &k);
    scanf("%s", str);
    int i;
    int rocks = 0;
    for(i = 0;i < n;i++)
    {
        if (str[i] == '#')
            rocks++;
        else
            rocks = 0;
        if (rocks >= k)
            break;
    }
    if (i < n)
        printf("NO\n");
    else
        printf("YES\n");
    return 0;
}
