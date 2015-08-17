/*
Description

Every year there is the same problem at Halloween: Each neighbour is only willing to give a certain total number of sweets on that day, no matter how many children call on him, so it may happen that a child will get nothing if it is too late. To avoid conflicts, the children have decided they will put all sweets together and then divide them evenly among themselves. From last year's experience of Halloween they know how many sweets they get from each neighbour. Since they care more about justice than about the number of sweets they get, they want to select a subset of the neighbours to visit, so that in sharing every child receives the same number of sweets. They will not be satisfied if they have any sweets left which cannot be divided.

Your job is to help the children and present a solution.

Input

The input contains several test cases.
The first line of each test case contains two integers c and n (1 ≤ c ≤ n ≤ 100000), the number of children and the number of neighbours, respectively. The next line contains n space separated integers a1 , ... , an (1 ≤ ai ≤ 100000 ), where ai represents the number of sweets the children get if they visit neighbour i.

The last test case is followed by two zeros.

Output

For each test case output one line with the indices of the neighbours the children should select (here, index i corresponds to neighbour i who gives a total number of ai sweets). If there is no solution where each child gets at least one sweet print "no sweets" instead. Note that if there are several solutions where each child gets at least one sweet, you may print any of them.

Sample Input

4 5
1 2 3 7 5
3 6
7 11 2 5 13 17
0 0
Sample Output

3 5
2 3 4

*/


#include <stdio.h>
#include <string.h>
int main()
{
	int i,j,n,c,s,a;
	while(scanf("%d%d",&c,&n),n&&c)
	{
		int arr[100005];
		memset(arr,0,sizeof(arr));
		s=0;
		arr[0]=1;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a);
			s=(s+a)%c;
			if(arr[s])
				break;
			else
				arr[s]=i+1;
		}
		printf("%d",arr[s]);
		for(j=arr[s]+1;j<=i;j++)
			printf(" %d",j);
		putchar('\n');
		for(i++;i<=n;i++)	scanf("%d",&a);
	}
	return 0;
}
