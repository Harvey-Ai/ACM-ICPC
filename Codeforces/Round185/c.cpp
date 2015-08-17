#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    if (k >= (n - 1) * n / 2)
    {
        cout << "no solution" << endl;
        return 0;
    }
    int x = 0, y = 0;
    for(int i = 0;i < n;i++)
    {
        printf("%d %d\n", x, y);
        x += 1;
        y += 2001;
    }
    return 0;
}
