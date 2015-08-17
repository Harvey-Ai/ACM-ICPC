/*
Problem Description
FatMouse has stored some cheese in a city. The city can be considered as a square grid of dimension n: each grid location is labelled (p,q) where 0 <= p < n and 0 <= q < n. At each grid location Fatmouse has hid between 0 and 100 blocks of cheese in a hole. Now he's going to enjoy his favorite food.

FatMouse begins by standing at location (0,0). He eats up the cheese where he stands and then runs either horizontally or vertically to another location. The problem is that there is a super Cat named Top Killer sitting near his hole, so each time he can run at most k locations to get into the hole before being caught by Top Killer. What is worse -- after eating up the cheese at one location, FatMouse gets fatter. So in order to gain enough energy for his next run, he has to run to a location which have more blocks of cheese than those that were at the current hole.

Given n, k, and the number of blocks of cheese at each grid location, compute the maximum amount of cheese FatMouse can eat before being unable to move. 
 

Input
There are several test cases. Each test case consists of 

a line containing two integers between 1 and 100: n and k 
n lines, each with n numbers: the first line contains the number of blocks of cheese at locations (0,0) (0,1) ... (0,n-1); the next line contains the number of blocks of cheese at locations (1,0), (1,1), ... (1,n-1), and so on. 
The input ends with a pair of -1's. 
 

Output
For each test case output in a line the single integer giving the number of blocks of cheese collected. 
 

Sample Input
3 1
1 2 5
10 11 6
12 12 7
-1 -1
 

Sample Output
37

*/

#include <stdio.h>
int arr[105][105],f[105][105];
int m,n;
void dfs(int r,int l)
{
    int i,max;
    max=arr[r][l];
    for(i=1;i<=m;i++)
    {
        if(r+i<n&&arr[r+i][l]>arr[r][l])
        {
            if(f[r+i][l]==-1)
                dfs(r+i,l);
            if(f[r+i][l]+arr[r][l]>max)
                max=f[r+i][l]+arr[r][l];
        }
        if(r-i>=0&&arr[r-i][l]>arr[r][l])
        {
            if(f[r-i][l]==-1)
                dfs(r-i,l);
            if(f[r-i][l]+arr[r][l]>max)
                max=f[r-i][l]+arr[r][l];
        }
        if(l+i<n&&arr[r][l+i]>arr[r][l])
        {
            if(f[r][l+i]==-1)
                dfs(r,l+i);
            if(f[r][l+i]+arr[r][l]>max)
                max=f[r][l+i]+arr[r][l];
        }
        if(l-i>=0&&arr[r][l-i]>arr[r][l])
        {
            if(f[r][l-i]==-1)
                dfs(r,l-i);
            if(f[r][l-i]+arr[r][l]>max)
                max=f[r][l-i]+arr[r][l];
        }
    }
    if(f[r][l]<max)
        f[r][l]=max;
}
int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m),m!=-1&&n!=-1)
    {
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                scanf("%d",&arr[i][j]);
                f[i][j]=-1;
            }
        dfs(0,0);
        printf("%d\n",f[0][0]);
    }
    return 0;
}
