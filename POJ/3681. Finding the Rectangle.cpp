/*
Description

Given N point on the x-y coordinates, you are to find the rectangle of the smallest area which covers no less than M points. The coordinates of the four vertices must be integers and the sides must be parallel to the axes. If one point lies on the sides of the rectangle, it is not considered as being covered. 

Input

The first line of input is the number of test case.
The first line of each test case contains two integers, N and M (1 ≤ M ≤ N ≤ 200).
The next N line each contain two integers xi, yi (1 ≤ xi, yi ≤ 10,000) describing the points. 
There is a blank line before each test case.

Output

For each test case output the smallest area in a separate line.

Sample Input

5

2 1
200 6
100 5

2 2
200 6
100 5

2 1
1 1
1 1

2 2
1 1
1 1

8 5
5 7
6 6
6 8
7 5
7 9
8 6
8 8
9 7
Sample Output

4
306
4
4
20
*/


#include <iostream>
#include <algorithm>
using namespace std;

int be[300];
struct Point
{
int a;
int b;
}
s[300];

bool operator <(const Point & p,const Point & q)
{
if(p.a!=q.a)
   return p.a<q.a;
return p.b<q.b;
}
void copy(int low,int high)
{
int i,j;
for(i=low,j=0;i<high;j++,i++)
{
   be[j]=s[i].b;
}
}
int main()
{
int Z,i,j,m,n,maxx,S,k,high,t;
cin>>Z;
while(Z--)
{
   cin>>n>>m;
   for(i=0;i<n;i++)
    cin>>s[i].a>>s[i].b;
   sort(s,s+n);
   maxx=INT_MAX;
   for(i=0;i<n;i++)
   {
    for(j=0;j<n;j++)
    {
     t=j-i+1;
     high=s[j].a-s[i].a;
     if(t>=m)
     {
      copy(i,j+1);
      sort(be,be+t);
      for(k=0;k+m<=t;k++)
      {
       S=(be[k+m-1]-be[k]+2)*(high+2);
       if(S<maxx)
        maxx=S;
      }
     }
    }
   }
   cout<<maxx<<endl;
}
return 0;
}
