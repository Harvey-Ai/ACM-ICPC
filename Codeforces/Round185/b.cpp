#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    double a, b, c, d;

    cin >> a >> b >> c >> d;

    double res;

    int zi, mu;
    zi = a * d;
    mu = a * d + b * c - a * c;

    res = zi * 1.0 / mu;
    printf("%.7lf\n", res);
    return 0;
}
