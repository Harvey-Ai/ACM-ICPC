/*
Problem Description
N(3<=N<=20000) ping pong players live along a west-east street(consider the street as a line segment). 

Each player has a unique skill rank. To improve their skill rank, they often compete with each other. If two players want to compete, they must choose a referee among other ping pong players and hold the game in the referee's house. For some reason, the contestants can’t choose a referee whose skill rank is higher or lower than both of theirs.

The contestants have to walk to the referee’s house, and because they are lazy, they want to make their total walking distance no more than the distance between their houses. Of course all players live in different houses and the position of their houses are all different. If the referee or any of the two contestants is different, we call two games different. Now is the problem: how many different games can be held in this ping pong street?
 

Input
The first line of the input contains an integer T(1<=T<=20), indicating the number of test cases, followed by T lines each of which describes a test case.


Every test case consists of N + 1 integers. The first integer is N, the number of players. Then N distinct integers a1, a2 … aN follow, indicating the skill rank of each player, in the order of west to east. (1 <= ai <= 100000, i = 1 … N).
 

Output
For each test case, output a single line contains an integer, the total number of different games.
 

Sample Input
1
3 1 2 3
 

Sample Output
1

*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define typev int // type of res

const int N = 100005;
typev ar[N]; // index: 1 ~ N
int lowb(int t) { return t & (-t) ; }
void add(int i, typev v) {
    for ( ; i < N; ar[i] += v, i += lowb(i));
}
typev sum(int i) {
    typev s = 0;
    for ( ; i > 0; s += ar[i], i -= lowb(i));
    return s;
}

int arr[20005];
int leftL[20005], rightL[20005];
int main()
{
    int ncase;
    cin >> ncase;

    while(ncase--)
    {
        int n;
        cin >> n;

        memset(ar, 0, sizeof(ar));
        for(int i = 0;i < n;i++)
            scanf("%d", &arr[i]);
        for(int i = 0;i < n;i++)
        {
            leftL[i] = sum(arr[i]);
            add(arr[i], 1);
        }
        memset(ar, 0, sizeof(ar));
        for(int i = n - 1;i >= 0;i--)
        {
            rightL[i] = sum(arr[i]);
            add(arr[i], 1);    
        }
        
        long long res = 0;
        for(int i = 1;i < n - 1;i++)
            res += leftL[i] * (n - i - 1 - rightL[i]) + (i - leftL[i]) * rightL[i];
        cout << res << endl;
    }
    return 0;
}

