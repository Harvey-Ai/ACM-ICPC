#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int sum[100005];
string str;
int main()
{
    getline(cin, str, '\n');
    int len = str.size();

    sum[0] = 0;
    for(int i = 1;i < len;i++)
    {
        if (str[i] == str[i - 1])
            sum[i] = sum[i - 1] + 1;
        else
            sum[i] = sum[i - 1];
    }

    int m;
    cin >> m;
    for(int i = 0; i < m;i++)
    {
        int a, b;
        cin >> a >> b;
        printf("%d\n", sum[b - 1] - sum[a - 1]);
    }
    return 0;
}
