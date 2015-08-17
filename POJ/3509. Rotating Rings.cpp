/*
Description

1	1	1	1	1
1	2	2	2	1
1	2	3	2	1
1	2	2	2	1
1	1	1	1	1
Figure (a)
1	2	3	4
5	6	7	8
9	10	11	12
13	14	15	16
Figure (b)
9	5	1	2
13	7	11	3
14	6	10	4
15	16	12	8
Figure (c)
Any square grid can be viewed as one or more rings, one inside the other. For example, as shown in figure (a), a 5 * 5 grid is made of three rings, numbered 1,2 and 3 (from outside to inside.) A square grid of size N is said to be sorted, if it includes the values from 1 to N2 in a row-major order, as shown in figure (b) for N = 4. We would like to determine if a given square grid can be sorted by only rotating its rings. For example, the grid in figure (c) can be sorted by rotating the first ring two places counter-clockwise, and rotating the second ring one place in the clockwise direction.

Input

Your program will be tested on one or more test cases. The first input line of a test case is an integer N which is the size of the grid. N input lines will follow, each line made of N integer values specifying the values in the grid in a row-major order. Note than 0 < N ≤ 1,000 and grid values are natural numbers less than or equal to 1,000,000.

The end of the test cases is identified with a dummy test case with N = 0.

Output

For each test case, output the result on a single line using the following format:

k. result

Where k is the test case number (starting at 1), and result is "YES" or "NO" (without the double quotes.)

Sample Input

4
9 5 1 2
13 7 11 3
14 6 10 4
15 16 12 8
3
1 2 3
5 6 7
8 9 4
0
Sample Output

1. YES
2. NO
*/


#include <stdio.h>
int n;
int arr[1005][1005],st[90000];
bool check(int t,int nn)
{
	int i,j,l,f,len;
	for(i=0;i<nn;i++)
		st[nn+i]=st[i];
	for(l=0;l<nn;l++)
		if((n+1)*t+1==st[l])
			break;
	t=n-t*2;
	if(l<nn)
	{
		f=1;
		for(j=1;j<t;j++)
			if(st[l+j]!=st[l+j-1]+1)
			{
				f=0;
				break;
			}
		if(f)
		{
			for(j=t;j<2*t-1;j++)
				if(st[l+j]!=st[l+j-1]+n)
				{
					f=0;
					break;
				}
		}
		if(f)
		{
			for(j=2*t-1;j<3*t-2;j++)
				if(st[l+j]!=st[l+j-1]-1)
				{
					f=0;
					break;
				}
		}
		if(f)
		{
			for(j=3*t-2;j<4*t-3;j++)
				if(st[l+j]!=st[l+j-1]-n)
				{
					f=0;
					break;
				}
		}
		if(f)
			return 1;
		else
			return 0;
	}
	else
		return 0;
}

int main()
{
	int i,j,k,l;
	l=1;
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&arr[i][j]);

		if(n%2)
		{
			if(arr[n/2][n/2]!=n/2*(n+1)+1)
			{
				printf("%d. NO\n",l++);
				continue;
			}
		}
		for(i=0;i<n/2;i++)
		{
			k=0;
			for(j=i;j<n-i;j++)
				st[k++]=arr[i][j];
			for(j=i+1;j<n-i;j++)
				st[k++]=arr[j][n-i-1];
			for(j=n-i-2;j>=i;j--)
				st[k++]=arr[n-i-1][j];
			for(j=n-i-2;j>i;j--)
				st[k++]=arr[j][i];
			if(check(i,k)==0)
				break;
		}
		if(i>=n/2)
			printf("%d. YES\n",l++);
		else
			printf("%d. NO\n",l++);
	}
	return 0;
}
