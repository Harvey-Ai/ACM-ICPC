/*
Description

In the army, a platoon is composed by n soldiers. During the morning inspection, the soldiers are aligned in a straight line in front of the captain. The captain is not satisfied with the way his soldiers are aligned; it is true that the soldiers are aligned in order by their code number: 1 , 2 , 3 , . . . , n , but they are not aligned by their height. The captain asks some soldiers to get out of the line, as the soldiers that remain in the line, without changing their places, but getting closer, to form a new line, where each soldier can see by looking lengthwise the line at least one of the line's extremity (left or right). A soldier see an extremity if there isn't any soldiers with a higher or equal height than his height between him and that extremity. 

Write a program that, knowing the height of each soldier, determines the minimum number of soldiers which have to get out of line. 
Input

On the first line of the input is written the number of the soldiers n. On the second line is written a series of n floating numbers with at most 5 digits precision and separated by a space character. The k-th number from this line represents the height of the soldier who has the code k (1 <= k <= n). 

There are some restrictions: 
•	2 <= n <= 1000 
•	the height are floating numbers from the interval [0.5, 2.5] 
Output

The only line of output will contain the number of the soldiers who have to get out of the line.
Sample Input

8
1.86 1.86 1.30621 2 1.4 1 1.97 2.2
Sample Output

4
*/



#include <stdio.h>
int dp1[1001],dp2[1001];
double arr[1001];
int main()
{
	int i,j,n,max;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
			scanf("%lf",&arr[i]);
		dp1[0]=1;
		for(i=1;i<n;i++)
		{
			max=1;
			for(j=0;j<i;j++)
				if(arr[j]<arr[i]&&dp1[j]+1>max)
					max=dp1[j]+1;
			dp1[i]=max;
		}
		dp2[n-1]=1;
		for(i=n-2;i>=0;i--)
		{
			max=1;
			for(j=n-1;j>i;j--)
				if(arr[j]<arr[i]&&dp2[j]+1>max)
					max=dp2[j]+1;
			dp2[i]=max;
		}
		max=0;
		for(i=0;i<n-1;i++)
			for(j=i+1;j<n;j++)
			if(dp1[i]+dp2[j]>max)
				max=dp1[i]+dp2[j];
		printf("%d\n",n-max);
	}
	return 0;
}
