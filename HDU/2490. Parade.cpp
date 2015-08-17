/*
Problem Description
Panagola, The Lord of city F likes to parade very much. He always inspects his city in his car and enjoys the welcome of his citizens. City F has a regular road system. It looks like a matrix with n+1 west-east roads and m+1 north-south roads. Of course, there are (n+1)×(m+1) road crosses in that system. The parade can start at any cross in the southernmost road and end at any cross in the northernmost road. Panagola will never travel from north to south or pass a cross more than once. Citizens will see Panagola along the sides of every west-east road. People who love Panagola will give him a warm welcome and those who hate him will throw eggs and tomatoes instead. We call a road segment connecting two adjacent crosses in a west-east road a “love-hate zone”. Obviously there are m love-hate zones in every west-east road. When passing a love-hate zone, Panagola may get happier or less happy, depending on how many people love him or hate him in that zone. So we can give every love-hate zone a “welcome value” which may be negative, zero or positive. As his secretary, you must make Panagola as happy as possible. So you have to find out the best route ----- of which the sum of the welcome values is maximal. You decide where to start the parade and where to end it.



When seeing his Citizens, Panagola always waves his hands. He may get tired and need a break. So please never make Panagola travel in a same west-east road for more than k minutes. If it takes p minutes to pass a love-hate zone, we say the length of that love-hate zone is p. Of course you know every love-hate zone’s length. 



The figure below illustrates the case in sample input. In this figure, a best route is marked by thicker lines.


 

Input
There are multiple test cases. Input ends with a line containing three zeros.
Each test case consists of 2×n + 3 lines. 

The first line contains three integers: n, m and k.(0<n<=100,0<m<=10000, 0<=k<=3000000)

The next n+1 lines stands for n + 1 west-east roads in north to south order. Each line contains m integers showing the welcome values of the road’s m love-hate zones, in west to east order.

The last n+1 lines also stands for n + 1 west-east roads in north to south order. Each line contains m integers showing the lengths (in minutes) of the road's m love-hate zones, in west to east order.
 

Output
For each test case, output the sum of welcome values of the best route. The answer can be fit in a 32 bits integer.
 

Sample Input
2 3 2
7 8 1
4 5 6
1 2 3
1 1 1
1 1 1
1 1 1
0 0 0
 

Sample Output
27

*/


#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

__int64 welcomeV[2][10005];
__int64 blockW[105][10005];
__int64 blockT[105][10005];

struct sumType
{
    __int64 start;
    __int64 value;
    sumType(__int64 s, __int64 v)
    {
        start = s;
        value = v;
    }
    sumType()
    {
        start = 0LL;
        value = 0LL;
    }
    bool operator()(const sumType &a, const sumType &b)
    {
        if (a.value < b.value)
            return 1;
        else
            return 0;
    }
};

int main()
{
    __int64 m, n, k;
    while(cin >> n >> m >> k, k || m || n)
    {
        __int64 now = 1LL, pre = 0LL;
       // memset(welcomeV, 0, sizeof(welcomeV));
        for(__int64 i = 0LL;i < 10005LL ;i++)
            welcomeV[0][i] = welcomeV[1][i] = 0LL;
        
        for(__int64 i = n;i >= 0LL;i--)
            for(__int64 j = 0LL;j < m;j++)
                scanf("%I64d", &blockW[i][j]);

        for(__int64 i = n;i >= 0LL;i--)
            for(__int64 j = 0LL;j < m;j++)
                scanf("%I64d", &blockT[i][j]);

        for(__int64 i = 0LL;i <= n;i++)
        {
            __int64 upBlock = 0LL;
            __int64 timeSum = 0LL;
            __int64 valueSum = 0;
            int temp = 0LL;
            priority_queue<sumType, vector<sumType>, sumType> maxSumQ;
            
            maxSumQ.push(sumType(0LL, welcomeV[pre][0]));
            welcomeV[now][0] = welcomeV[pre][0];
            for(__int64 j = 1LL;j <= m;j++)
            {
                valueSum += (__int64)(blockW[i][j - 1]);
                temp += blockW[i][j - 1];
                //if valu
            //    if (valueSum > temp)
             //      while(1);
                timeSum += blockT[i][j - 1];
                maxSumQ.push(sumType(j, welcomeV[pre][j] - valueSum)); 
                while(timeSum > k)
                {
                    timeSum -= blockT[i][upBlock];
                    upBlock++;
                }
                
                while(1)
                {
                    sumType maxSum = maxSumQ.top();
                    if (maxSum.start >= upBlock)
                    {
                        welcomeV[now][j] = maxSum.value + valueSum;
                        break;
                    }   
                    else
                        maxSumQ.pop();
                }
            }

            timeSum = 0LL;
            valueSum = 0LL;
            upBlock = m;
            temp = 0LL;
            priority_queue<sumType, vector<sumType>, sumType> maxSumQ2;
            maxSumQ2.push(sumType(m, welcomeV[pre][m]));
            for(__int64 j = m - 1;j >= 0LL;j--)
            {
                valueSum += (__int64)(blockW[i][j]);
                timeSum += (__int64)(blockT[i][j]);
                temp += blockW[i][j];
             //   if (valueSum > temp)
            //       while(1);
                maxSumQ2.push(sumType(j, welcomeV[pre][j] - valueSum)); 
                while(timeSum > k)
                {
                    timeSum -= blockT[i][upBlock - 1];
                    upBlock--;
                }
                while(1)
                {
                    sumType maxSum2 = maxSumQ2.top();
                    if (maxSum2.start <= upBlock)
                    {
                        if (welcomeV[now][j] < (maxSum2.value + valueSum))
                            welcomeV[now][j] = maxSum2.value + valueSum;
                        break;
                    }   
                    else
                        maxSumQ2.pop();
                }
            }
            now = 1 - now;
            pre = 1 - pre;
        }
        
        __int64 maxV = welcomeV[pre][0];
        for(__int64 i = 0LL;i <= m;i++)
            if (maxV < welcomeV[pre][i])
                maxV = welcomeV[pre][i];
        printf("%lld\n", maxV);
    }
    return 0;
}
