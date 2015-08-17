#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

long long arr[2000006];
int main()
{
    int m;
    cin >> m;
    for(int i = 0;i < m;i++)
        cin >> arr[i];

    int layer = 1;
    int temp = 1;
    while(temp * 4 <= m)
    {
        layer++;
        temp *= 4;
    }
    sort(&arr[0], &arr[m]);
    
    long long sum = 0;
    int nowLayer = 1;
    int caNum = 0, totalNum = 1;

    int index = m - 1;
    while(totalNum <= m)
    {
        for(int i = 0;i < totalNum - caNum;index--, i++)
            sum += arr[index] * (layer - nowLayer + 1);
        caNum = totalNum;
        totalNum *= 4;
        nowLayer++;
    }
    cout << sum << endl;
    return 0;
}
