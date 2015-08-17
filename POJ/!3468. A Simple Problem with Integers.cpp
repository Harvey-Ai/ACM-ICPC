/*
Description

You have N integers, A1, A2, ... , AN. You need to deal with two kinds of operations. One type of operation is to add some given number to each number in a given interval. The other is to ask for the sum of numbers in a given interval.

Input

The first line contains two numbers N and Q. 1 ≤ N,Q ≤ 100000.
The second line contains N numbers, the initial values of A1, A2, ... , AN. -1000000000 ≤ Ai ≤ 1000000000.
Each of the next Q lines represents an operation.
"C a b c" means adding c to each of Aa, Aa+1, ... , Ab. -10000 ≤ c ≤ 10000.
"Q a b" means querying the sum of Aa, Aa+1, ... , Ab.

Output

You need to answer all Q commands in order. One answer in a line.

Sample Input

10 5
1 2 3 4 5 6 7 8 9 10
Q 4 4
Q 1 10
Q 2 4
C 3 6 3
Q 2 4
Sample Output

4
55
9
15
Hint

The sums may exceed the range of 32-bit integers.
*/



#include <stdio.h>
 long arr[40][100001];
int main()
{
	__int64 rel;
	long i,j,k,n,q,a,bg,ed,top,topsize,size;
	char c;
	while(scanf("%d%d",&n,&q)!=EOF)
	{
		for(i=0;i<n;i++)
			scanf("%ld",&arr[0][i]);
		getchar();
		for(size=2,i=1;size<=n;i++,size*=2)
			for(j=0;j+size<=n;j++)
				arr[i][j]=arr[i-1][j]+arr[i-1][j+size/2];

		top=i-1;topsize=size/2;
		for(i=0;i<q;i++)
		{
			c=getchar();
			scanf("%d%d",&bg,&ed);
			if(c=='C')
			{
				scanf("%d",&a);
				size=topsize;
				int comhead,comtail;
				for(j=top;j>=0;j--,size/=2)
				{
					k=bg-size;
					if(k<0)
						k=0;
					for(;k<ed;k++)
					{
						if(bg-1>k)
							comhead=bg-1;
						else
							comhead=k;
						if(ed>k+size)
							comtail=k+size-1;
						else
							comtail=ed-1;
						arr[j][k]+=(comtail-comhead+1)*a;
					}
				}
			}
			else
			{
				rel=0;
				j=topsize;k=top;
				size=ed-bg+1;
				while(size)
				{
					while(j>size)
					{
						j/=2;
						k--;
					}
					size-=j;
					rel+=arr[k][bg-1];
					bg=bg+j;
				}
				printf("%ld\n",rel);
			}
			getchar();
		}
	}
	return 0;
}
