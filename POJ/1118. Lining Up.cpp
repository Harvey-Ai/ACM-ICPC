/*
Description

"How am I ever going to solve this problem?" said the pilot. 

Indeed, the pilot was not facing an easy task. She had to drop packages at specific points scattered in a dangerous area. Furthermore, the pilot could only fly over the area once in a straight line, and she had to fly over as many points as possible. All points were given by means of integer coordinates in a two-dimensional space. The pilot wanted to know the largest number of points from the given set that all lie on one line. Can you write a program that calculates this number? 


Your program has to be efficient! 
Input

Input consist several case,First line of the each case is an integer N ( 1 < N < 700 ),then follow N pairs of integers. Each pair of integers is separated by one blank and ended by a new-line character. The input ended by N=0.
Output

output one integer for each input case ,representing the largest number of points that all lie on one line.
Sample Input

5
1 1
2 2
3 3
9 10
10 11
0
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
	while(scanf("%d",&n),n)
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
