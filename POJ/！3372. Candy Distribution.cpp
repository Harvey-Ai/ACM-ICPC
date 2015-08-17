/*
Description

N children standing in circle who are numbered 1 through N clockwise are waiting their candies. Their teacher distributes the candies by in the following way:

First the teacher gives child No.1 and No.2 a candy each. Then he walks clockwise along the circle, skipping one child (child No.3) and giving the next one (child No.4) a candy. And then he goes on his walk, skipping two children (child No.5 and No.6) and giving the next one (child No.7) a candy. And so on.

Now you have to tell the teacher whether all the children will get at least one candy?

Input

The input consists of several data sets, each containing a positive integer N (2 ≤ N ≤ 1,000,000,000).

Output

For each data set the output should be either "YES" or "NO".

Sample Input

2
3 
4
Sample Output

YES
NO
YES
*/

#include <iostream>
#include <string>
bool arr[100000000];
using namespace std;
int main()
{
	long i,n,temp;
	bool flag;
	while(cin>>n)
	{
		flag=1;
		for(i=0;i<n;i++)
			arr[i]=0;
		i=0;
		while(i<n)
		{
			temp=(i*(i+1)/2)%n;
			if(arr[temp]==0)
				arr[temp]=1;
			else
			{
				flag=0;
				break;
			}
			i++;
		}
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
