#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

vector<long long> factor;
void getFactor(long long n)
{
    factor.clear();
    for(long long i = 1;i * i <= n;i++)
        if (n % i == 0)
            factor.push_back(i);

}

int main()
{
    long long n;

    scanf("%I64d", &n);
    if (n % 3)
    {
        printf("0\n");
        return 0;
    }
    n /= 3;
    getFactor(n);
   
    //printf("size %d\n", factor.size());
    long long res = 0;
    for(int i = 0;i < factor.size();i++)
    {
        long long a = n / factor[i];
        for(int j = 0;j <= i;j++)
        {
            if (a % factor[j]) continue;
            long long c = a / factor[j];
            if (c > factor[j]) continue;


            long long total = factor[i] + factor[j] + c;
            if (total % 2)
                continue;
            else
                total /= 2;
            if (total - factor[i] <= 0 || total - factor[j] <= 0 || total - c <= 0)
                continue;
            
            //printf("%I64d %I64d %I64d\n", factor[i], factor[j], c);
            if (factor[i] == factor[j] && factor[j] == c)
                res++;
            else if (factor[i] == factor[j] || factor[j] == c)
                res += 3;
            else
                res += 6;
        }
    }
    printf("%I64d\n", res);
    return 0;
}
