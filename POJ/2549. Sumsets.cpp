/*
Description

Given S, a set of integers, find the largest d such that a + b + c = d where a, b, c, and d are distinct elements of S.
Input

Several S, each consisting of a line containing an integer 1 <= n <= 1000 indicating the number of elements in S, followed by the elements of S, one per line. Each element of S is a distinct integer between -536870912 and +536870911 inclusive. The last line of input contains 0.
Output

For each S, a single line containing d, or a single line containing "no solution".
Sample Input

5
2 
3 
5 
7 
12
5
2 
16 
64 
256 
1024
0
*/

#include <stdio.h>
#include <algorithm>
using namespace std;
long arr[1005],a;
int main()
{
	int i,j,head,tail,n;
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;i++) 
			scanf("%ld",&arr[i]);
		sort(&arr[0],&arr[n]);
		for(i=n-1;i>0;i--)
		{
			for(j=n-1;j>=0;j--)
			{
				if(i!=j)
				{
					a=arr[i]-arr[j];
					tail=n-1;head=0;
					while(tail>head)
					{
						if(tail==i||tail==j) 
						{
							tail--;
							continue;
						}
						if(head==i||head==j) 
						{
							head++;
							continue;
						}
						if(arr[head]+arr[tail]==a)	
							break;
						if(arr[head]+arr[tail]>a)	tail--;
						else	head++;
					}
					if(tail>head)
						break;
				}
			}
			if(j>=0)
				break;
		}
		if(i>0)	printf("%ld\n",arr[i]);
		else printf("no solution\n");
	}
	return 0;
}
