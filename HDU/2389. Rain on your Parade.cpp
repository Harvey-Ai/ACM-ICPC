/*
Problem Description
You’re giving a party in the garden of your villa by the sea. The party is a huge success, and everyone is here. It’s a warm, sunny evening, and a soothing wind sends fresh, salty air from the sea. The evening is progressing just as you had imagined. It could be the perfect end of a beautiful day.
But nothing ever is perfect. One of your guests works in weather forecasting. He suddenly yells, “I know that breeze! It means its going to rain heavily in just a few minutes!” Your guests all wear their best dresses and really would not like to get wet, hence they stand terrified when hearing the bad news.
You have prepared a few umbrellas which can protect a few of your guests. The umbrellas are small, and since your guests are all slightly snobbish, no guest will share an umbrella with other guests. The umbrellas are spread across your (gigantic) garden, just like your guests. To complicate matters even more, some of your guests can’t run as fast as the others.
Can you help your guests so that as many as possible find an umbrella before it starts to pour? 

Given the positions and speeds of all your guests, the positions of the umbrellas, and the time until it starts to rain, find out how many of your guests can at most reach an umbrella. Two guests do not want to share an umbrella, however. 
 

Input
The input starts with a line containing a single integer, the number of test cases.
Each test case starts with a line containing the time t in minutes until it will start to rain (1 <=t <= 5). The next line contains the number of guests m (1 <= m <= 3000), followed by m lines containing x- and y-coordinates as well as the speed si in units per minute (1 <= si <= 3000) of the guest as integers, separated by spaces. After the guests, a single line contains n (1 <= n <= 3000), the number of umbrellas, followed by n lines containing the integer coordinates of each umbrella, separated by a space.
The absolute value of all coordinates is less than 10000.
 

Output
For each test case, write a line containing “Scenario #i:”, where i is the number of the test case starting at 1. Then, write a single line that contains the number of guests that can at most reach an umbrella before it starts to rain. Terminate every test case with a blank line.
 

Sample Input
2
1
2
1 0 3
3 0 3
2
4 0
6 0
1
2
1 1 2
3 3 2
2
2 2
4 4
 

Sample Output
Scenario #1:
2

Scenario #2:
2

*/

#include <stdio.h>
#include <string.h>

const int N = 3005; 
int n, m;//二分图的两个集合分别含有n和m个元素,match[i]存储集合m中的节点i在集合n中的匹配节点,初值为-1
int map[N][N];//map存储邻接矩阵-单向边

int pred[N] , mk[N] , open[N] , src[N], cx[N], cy[N];


int MaxMatch()

{

    int i , u , v , t , d , e , cur , tail , res(0) ;

    memset(mk , 0xff , sizeof(mk)) ; memset(cx , 0xff , sizeof(cx)) ; memset(cy , 0xff , sizeof(cy)) ;

    for (i = 0 ; i < n ; i++)

    {

         pred[i] = -1 ;

         for (open[cur = tail = 0] = i ; cur <= tail && cx[i] == -1 ; cur++)

        {

             for (u = open[cur] , v = 0 ; v < m && cx[i] == -1 ; v ++) if (map[u][v] && mk[v] != i)

            {

                mk[v] = i ; open[++tail] = cy[v] ; if (open[tail] >= 0) { pred[open[tail]] = u ; continue ; }

                for (d = u , e = v ; d != -1 ; t = cx[d] , cx[d] = e , cy[e] = d , e = t , d = pred[d]) ;

            }

        }

        if (cx[i] != -1) res++ ;

    }

    return res ;

}

struct Lpoint 
{
    int x,y;
    int len;
}p[N]; //点
int p2pdis(Lpoint p1,Lpoint p2) 
{
    return ((p1.x-p2.x) * (p1.x-p2.x) + (p1.y-p2.y) * (p1.y-p2.y));
}
int main(void)
{
    int ncase, cnt=0;
    scanf("%d", &ncase);
    while( ncase-- )
    {
        int  t;
        int i, j;
        scanf("%d%d", &t, &n);
        for( i=0; i < n; ++i ) 
        {
            scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].len);
            p[i].len *= t; p[i].len *= p[i].len;
        }
        scanf("%d", &m);
        for( i=0; i < m; ++i )
        {
            Lpoint  um;
            scanf("%d%d", &um.x, &um.y);
            for( j=0; j < n; ++j )
                map[j][i] = ( p2pdis(p[j], um) <= p[j].len );
        }
        printf("Scenario #%d:\n%d\n\n", ++cnt, MaxMatch());
    }
    return 0;
}
