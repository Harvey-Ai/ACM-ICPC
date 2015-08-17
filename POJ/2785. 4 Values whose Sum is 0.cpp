/*
Description

The SUM problem can be formulated as follows: given four lists A, B, C, D of integer values, compute how many quadruplet (a, b, c, d ) ∈ A x B x C x D are such that a + b + c + d = 0 . In the following, we assume that all lists have the same size n .
Input

The first line of the input file contains the size of the lists n (this value can be as large as 4000). We then have n lines containing four integer values (with absolute value as large as 228 ) that belong respectively to A, B, C and D .
Output

For each input file, your program has to write the number quadruplets whose sum is zero.
Sample Input

6
-45 22 42 -16
-41 -27 56 30
-36 53 -37 77
-36 30 -75 -46
26 -38 -10 62
-32 -54 -6 45
Sample Output

5
Hint

Sample Explanation: Indeed, the sum of the five following quadruplets is zero: (-45, -27, 42, 30), (26, 30, -10, -46), (-32, 22, 56, -46),(-32, 30, -75, 77), (-32, -54, 56, 30).
*/


#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[4001][4],b[16000001],c[16000001];
int main()
{
	int i,j,n,r,h,mid,t,cnt,tg;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d%d%d%d",&arr[i][0],&arr[i][1],&arr[i][2],&arr[i][3]);
	t=0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			b[t++]=arr[i][0]+arr[j][1];

	t=0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			c[t++]=arr[i][2]+arr[j][3];

	sort(&c[0],&c[t]);
	cnt=0;
	for(i=0;i<t;i++)
	{
		tg=-b[i];
		h=0;r=t-1;
		while(h<=r)
		{
			mid=(r+h)/2;
			if(c[mid]<tg)
				h=mid+1;
			else
			{
				if(c[mid]>tg)
					r=mid-1;
				else
					break;
			}
		}
		if(h<=r)
		{
			r=h=mid=(r+h)/2;
			while(h>=0&&c[h]==tg)
				h--;
			while(r<t&&c[r]==tg)
				r++;
			cnt+=r-h-1;
		}
	}
	printf("%d\n",cnt);
	return 0;
}
