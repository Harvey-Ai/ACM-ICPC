/*
Description
换寝室是大家都不愿意碰到的事情，不幸的是，可怜的wwm高中大学都遇到了。
室友们有一个不成文的规定，那就是根据自己的学号选择床号。如果某同学的学号是a，并且有0..k-1一共k张床，那么他就会选择a%k号床作为他睡觉的地点。显然，两个人不能睡在一张床上。那么给出所有同学的学号，请你为他们准备一间卧室，使得里面的床的数量最少。

Input
第一行是同学的个数n(1<=n<=5,000)；第2到第n+1行是每个同学的学号Si(1<=Si<=1,000,000)。

Output

仅一行，是最少的床的数目。

Sample Input
5
4
6
9
10
13

Sample Output
8
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

#define N 5005
#define S 1000001

int arr[N];
int primeM[S];
int prime[78668];
bool map[S];

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int getPrime()
{
    int i, j;
    int cnt;

    memset(primeM, 0, sizeof(primeM));

    cnt = 0;
    for(i = 2;i < S;i++)
    {
        for(j = 0;j < cnt;j++)
        {
            if (i * prime[j] >= S)
                break;
            primeM[i * prime[j]] = prime[j];
        }

        if (primeM[i] == 0)
            prime[cnt++] = i;
    }
//    printf("%d\n", cnt);
}

int main()
{
    int i, j, k, l;
    int diff;
    int temp;
    int n;

    getPrime();
    scanf("%d", &n);

    for(i = 0;i < n;i++)
        scanf("%d", &arr[i]);

    qsort(arr, n, sizeof(arr[0]), cmp);
    memset(map, 0, sizeof(map));

    for(i = 0;i < n;i++)
        for(j = i + 1;j < n;j++)
        {
            diff = arr[j] - arr[i];
            map[diff] = 1;
        }

    for(i = 2;i <= S;i++)
        if (map[i])
        {
            temp = i;
            while(primeM[temp])
            {
                map[temp] = 1;
                temp /= primeM[temp];
            }
        }

    for(i = 2;i <= S;i++)
        if (!map[i])
        {
            printf("%d\n", i);
            return 0;
        }
    return 0;
}

