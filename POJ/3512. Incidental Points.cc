/*
Description

Unlike a straight line, a straight segment between two points P1, P2 (normally written as P1P2) is a line that links the two points but doesn’t extend beyond them. A third point P3 is said to be incident to P1P2 iff P3 lies on the straight line and between the points P1 and P2. P1P2 is said to include P3. By definition, P1 and P2 are included in P1P2. Write a program to find the segment that includes the most number of given points.

Input

Your program will be tested on one or more test cases. Each test case includes a set of two or more unique points, where the Cartesian coordinates of each point is specified on a separate line using two integers X and Y where 0 ≤ |X|, |Y| < 1,000,000. No test case has more than 1000 points. An input line made of two or more '-' (minus signs) signals the end of a test case. An extra input line of two or more '-' (minus signs) follow the last test case.

Output

For each test case, output the result on a single line using the following format:

k. n

Where k is the test case number (starting at 1), and n is the number of points on the segment.

Sample Input

1 1
1 5
5 9
9 5
5 5
3 2
5 3
----
1 5
5 1
1 1
5 5
--
--------
Sample Output

1. 4
2. 2
*/


#include <iostream>
#include <algorithm>
using namespace std;
int p[1005][2];
double ex[1005];
int main()
{
	char c;
	int n,i,j,k,l,nn,res,f,cnt;
	l=1;
	while(1)
	{
		f=0;
		if(cin.peek()=='-')
		{
			getchar();
			c=cin.peek();
			if(c!='-')
				f=1;
			else
				break;
		}
		for(i=0;;i++)
		{
			if(cin.peek()=='-')
			{
				getchar();
				c=cin.peek();
				if(c!='-')
					f=1;
				else
					break;
			}
			scanf("%d%d",&p[i][0],&p[i][1]);
			if(f)
				p[i][0]=-p[i][0];
			c=getchar();
			f=0;
		}
		c=getchar();
		while(c!='\n')
			c=getchar();
		n=i;
		res=0;
		for(i=0;i<n;i++)
		{
			if(res>=n-1-i)
				break;
			for(k=0,cnt=0,j=i+1;j<n;j++)
			{
				if(p[j][0]!=p[i][0])
					ex[k++]=(p[j][1]-p[i][1])*1.0/(p[j][0]-p[i][0]);
				else
					cnt++;
			}
			if(cnt>res)
				res=cnt;
			nn=k;
			sort(&ex[0],&ex[nn]);
			for(k=0;k<nn;)
			{
				j=k+1;
				while(j<nn&&ex[j]==ex[j-1])
					j++;
				if(j-k>res)
					res=j-k;
				k=j;
			}
		}
		printf("%d. %d\n",l++,res+1);
	}
	c=getchar();
	while(c!='\n')
		c=getchar();
	return 0;
}
