/*

Given a set of n integers: A={a1, a2,..., an}, we define a function d(A) as below:

Your task is to calculate d(A).
Input

The input consists of T(<=30) test cases. The number of test cases (T) is given in the first line of the input. 
Each test case contains two lines. The first line is an integer n(2<=n<=50000). The second line contains n integers: a1, a2, ..., an. (|ai| <= 10000).There is an empty line after each case.
Output

Print exactly one line for each test case. The line should contain the integer d(A).
Sample Input

1

10
1 -1 2 2 3 -3 4 -4 5 -5
Sample Output

13
Hint

In the sample, we choose {2,2,3,-3,4} and {5}, then we can get the answer. 
*/


#include <stdio.h>
int arr[50005],l[50005],r[50005];
int n;
void maxsum()
{
	int i,sum,b;
	b=sum=arr[0];
	l[0]=arr[0];
	for(i=1;i<n;i++)
	{
		if(b>0) b+=arr[i];
		else b=arr[i];
		if(b>sum) 
			sum=b;
		l[i]=sum;
	}
}
void maxsum2()
{
	int i,sum,b;
	b=sum=arr[n-1];
	r[n-1]=arr[n-1];
	for(i=n-2;i>=0;i--)
	{
		if(b>0) b+=arr[i];
		else b=arr[i];
		if(b>sum) 
			sum=b;
		r[i]=sum;
	}
}
int main()
{
	int max,i,N;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);
		maxsum();
		maxsum2();
		max=l[0]+r[1];

		for(i=1;i<n-1 ;i++)
			if(max<l[i]+r[i+1])
				max=l[i]+r[i+1];

		printf("%d\n",max);
	}
	return 0;
}
