/*
Problem Description
Read the program below carefully then answer the question.
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include<iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include<vector>

const int MAX=100000*2;
const int INF=1e9;

int main()
{
  int n,m,ans,i;
  while(scanf("%d%d",&n,&m)!=EOF)
  {
    ans=0;
    for(i=1;i<=n;i++)
    {
      if(i&1)ans=(ans*2+1)%m;
      else ans=ans*2%m;
    }
    printf("%d\n",ans);
  }
  return 0;
}
 

Input
Multi test cases，each line will contain two integers n and m. Process to end of file.
[Technical Specification]
1<=n, m <= 1000000000
 

Output
For each case，output an integer，represents the output of above program.
 

Sample Input
1 10
3 100
 

Sample Output
1
5
 

*?/


#include <iostream>
#include <cstdio>
using namespace std;

__int64 fastMod(__int64 num, __int64 m)
{
    __int64 temp = 4;
    __int64 res = 1;

    while(num)
    {
        if (num % 2)
            res = (res * temp) % m;
        temp = (temp * 4) % m;
        num /= 2;
    }
    return res;
}

int main()
{
    __int64 n, m;
    while(cin >> n >> m)
    {
        __int64 t, a1;
        if (n % 2)
        {
            a1 = 1;
            t = (n - 1) / 2 + 1;
        }
        else
        {
            a1 = 2;
            t = n / 2;
        }
        __int64 k = (a1 * (fastMod(t, m) - 1)) % m;
        
        if (k == 0)
            k = m;
        while(k % 3 != 0)
             k = (k + m);
        cout << (k / 3) % m << endl;
    }
    return 0;
}
