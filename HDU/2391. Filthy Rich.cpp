/*
Problem Description
They say that in Phrygia, the streets are paved with gold. You’re currently on vacation in Phrygia, and to your astonishment you discover that this is to be taken literally: small heaps of gold are distributed throughout the city. On a certain day, the Phrygians even allow all the tourists to collect as much gold as they can in a limited rectangular area. As it happens, this day is tomorrow, and you decide to become filthy rich on this day. All the other tourists decided the same however, so it’s going to get crowded. Thus, you only have one chance to cross the field. What is the best way to do so?

Given a rectangular map and amounts of gold on every field, determine the maximum amount of gold you can collect when starting in the upper left corner of the map and moving to the adjacent field in the east, south, or south-east in each step, until you end up in the lower right corner.
 

Input
The input starts with a line containing a single integer, the number of test cases.
Each test case starts with a line, containing the two integers r and c, separated by a space (1 <= r, c <= 1000). This line is followed by r rows, each containing c many integers, separated by a space. These integers tell you how much gold is on each field. The amount of gold never negative.
The maximum amount of gold will always fit in an int.
 

Output
For each test case, write a line containing “Scenario #i:”, where i is the number of the test case, followed by a line containing the maximum amount of gold you can collect in this test case. Finish each test case with an empty line.
 

Sample Input
1
3 4
1 10 8 8
0 0 1 8
0 27 0 4
 

Sample Output
Scenario #1:
42

*/

#include <stdio.h>
int dp[2][1005];
int main()
{
    int ncase,l,i,j,pp,ss,a,temp,m,n;
    scanf("%d",&ncase);
    l=1;
    while(ncase--)
    {
        scanf("%d%d",&m,&n);
        scanf("%d",&a);
        dp[0][0]=a;
        for(j=1;j<n;j++)
        {
            scanf("%d",&a);
            dp[0][j]=a+dp[0][j-1];
        }
        pp=1;ss=0;
        for(i=1;i<m;i++)
        {
            scanf("%d",&a);
            dp[pp][0]=dp[ss][0]+a;
            for(j=1;j<n;j++)
            {
                temp=dp[ss][j];
                if(temp<dp[ss][j-1])
                    temp=dp[ss][j-1];
                if(temp<dp[pp][j-1])
                    temp=dp[pp][j-1];
                scanf("%d",&a);
                dp[pp][j]=temp+a;
            }
            temp=pp;
            pp=ss;
            ss=temp;
        }
        printf("Scenario #%d:\n",l++);
        printf("%d\n\n",dp[ss][n-1]);
    }
    return 0;
}
