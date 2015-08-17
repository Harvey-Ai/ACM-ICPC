/*
Description

Given a N × N matrix A, whose element in the i-th row and j-th column Aij is an number that equals i2 + 100000 × i + j2 - 100000 × j + i × j, you are to find the M-th smallest element in the matrix.

Input

The first line of input is the number of test case.
For each test case there is only one line contains two integers, N(1 ≤ N ≤ 50,000) and M(1 ≤ M ≤ N × N). There is a blank line before each test case.

Output

For each test case output the answer on a single line.

Sample Input

12

1 1

2 1

2 2

2 3

2 4

3 1

3 2

3 8

3 9

5 1

5 25

5 10
Sample Output

3
-99993
3
12
100007
-199987
-99993
100019
200013
-399969
400031
-99939

*/

#include <stdio.h>
long long res,m,n;
long long cnt(long long mm)
{
	int flag;
	long long temp,ccnt,j,hh,tt,mid;
	ccnt=0;flag=0;
	for(j=1;j<=n;j++)
	{
		hh=1;tt=n;
		while(hh<=tt)
		{
			mid=(hh+tt)>>1;
			temp=mid*mid+100000*mid+j*j-100000*j+mid*j;
			if(temp>mm)
				tt=mid-1;
			else
				hh=mid+1;
		}
		ccnt+=hh-1;
		if(ccnt>m)
			return ccnt;
		if(hh-1>0)
			temp=(hh-1)*(hh-1)+100000*(hh-1)+j*j-100000*j+(hh-1)*j;
		else
			temp=mm+1;
		if(temp<=mm)
		{
			if(flag==0)
			{
				res=temp;
				flag=1;
			}
			else
			{
				if(temp>res)
					res=temp;
			}
		}
	}
	return ccnt;
}

int main()
{
	int ncase;
	long long j,min,max,mid,temp;
	scanf("%d",&ncase);
	while(ncase--)
	{
		scanf("%lld%lld",&n,&m);
		max=n*n+100000*n+1-100000+n;
		for(j=2;j<=n;j++)
		{
			 temp=n*n+100000*n+j*j-100000*j+n*j;
			 if(temp>max)
				 max=temp;
		}
		min=3;
		for(j=2;j<=n;j++)
		{
			 temp=1+100000+j*j-100000*j+j;
			 if(temp<min)
				 min=temp;
		}
	//	printf("%I64d %I64d\n",min,max);
		while(min<=max)
		{
			mid=(min+max)>>1;
			temp=cnt(mid);
			if(temp<=m)
			{
				if(temp<m)
					min=mid+1;
				else
					break;
			}
			else
				max=mid-1;
		}
		printf("%lld\n",res);
	}
	return 0;
}

