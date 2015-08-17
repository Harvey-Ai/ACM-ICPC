/*
Description

Some of Farmer John's N cows (1 ≤ N ≤ 80,000) are having a bad hair day! Since each cow is self-conscious about her messy hairstyle, FJ wants to count the number of other cows that can see the top of other cows' heads.

Each cow i has a specified height hi (1 ≤ hi ≤ 1,000,000,000) and is standing in a line of cows all facing east (to the right in our diagrams). Therefore, cow i can see the tops of the heads of cows in front of her (namely cows i+1, i+2, and so on), for as long as these cows are strictly shorter than cow i.

Consider this example:

        =
=       =
=   -   =         Cows facing right -->
=   =   =
= - = = =
= = = = = =
1 2 3 4 5 6 
Cow#1 can see the hairstyle of cows #2, 3, 4
Cow#2 can see no cow's hairstyle
Cow#3 can see the hairstyle of cow #4
Cow#4 can see no cow's hairstyle
Cow#5 can see the hairstyle of cow 6
Cow#6 can see no cows at all!

Let ci denote the number of cows whose hairstyle is visible from cow i; please compute the sum of c1 through cN.For this example, the desired is answer 3 + 0 + 1 + 0 + 1 + 0 = 5.

Input

Line 1: The number of cows, N. 
Lines 2..N+1: Line i+1 contains a single integer that is the height of cow i.
Output

Line 1: A single integer that is the sum of c1 through cN.
Sample Input

6
10
3
7
4
12
2
Sample Output

5
*/

#include <stdio.h>
int dp[80005],arr[80005];
int main()
{
	long long res;
	int i,n,p;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	dp[n-1]=0;
	for(i=n-2;i>=0;i--)
	{
		p=i+1;
		while(p<n)
		{
			if(arr[i]>arr[p])
				p+=dp[p]+1;
			else
				break;
		}
		dp[i]=p-i-1;
	}
	res=0;
	for(i=0;i<n;i++)
		res+=dp[i];
	printf("%lld\n",res);
	return 0;
}
