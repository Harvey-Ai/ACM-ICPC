#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int account;
    cin >> account;

    if (account >= 0)
        printf("%d\n", account);
    else
    {
        int max = account;
        if (account / 10 > max)
            max = account / 10;
        if (account < -9)
        {
            if ((account / 100) * 10 - abs(account % 10) > max)
                max = (account / 100) * 10 - abs(account % 10);
        }
        printf("%d\n", max);
    }
    return 0;
}
