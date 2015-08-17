/*
Description

Alice often examines star maps where stars are represented by points in a plane and there is a Cartesian coordinate for each star. Let the Linearity of a star map be the maximum number of stars in a straight line. 


For example, look at the star map shown on the figure above, the Linearity of this map is 3, because the star 1, star 2, and star 5 are within the same straight line, and there is no straight line that passes 4 stars. 

You are to write a program to find the Linearity of a star map. 
Input

Input will contain multiple test cases. Each describes a star map. 

For each test case, the first line of the input contains the number of stars N (2 <= N <= 1000). The following N lines describe coordinates of stars (two integers X and Y per line separated by a space, 0 <= X, Y <= 1000). There can be only one star at one point of the plane. 
Output

Output the Linearity of the map in a single line.
Sample Input

5
0 0
2 0
0 2
1 1
2 2
Sample Output

3
*/


#include <stdio.h>
#include <algorithm>
using namespace std;
int p[1005][2];
double ex[1005];
int main()
{
	int n,i,j,k,nn,res;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
			scanf("%d%d",&p[i][0],&p[i][1]);

		res=0;
		for(i=0;i<n;i++)
		{
			if(res>=n-1-i)
				break;
			for(k=0,j=i+1;j<n;j++,k++)
				ex[k]=(p[j][1]-p[i][1])*1.0/(p[j][0]-p[i][0]);
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
		printf("%d\n",res+1);
	}
	return 0;
}
