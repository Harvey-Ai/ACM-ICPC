/*
Description

Farmer John and Betsy are playing a game with N (1 <= N <= 30,000)identical cubes labeled 1 through N. They start with N stacks, each containing a single cube. Farmer John asks Betsy to perform P (1<= P <= 100,000) operation. There are two types of operations: 
moves and counts. 
* In a move operation, Farmer John asks Bessie to move the stack containing cube X on top of the stack containing cube Y. 
* In a count operation, Farmer John asks Bessie to count the number of cubes on the stack with cube X that are under the cube X and report that value. 

Write a program that can verify the results of the game. 
Input

* Line 1: A single integer, P 

* Lines 2..P+1: Each of these lines describes a legal operation. Line 2 describes the first operation, etc. Each line begins with a 'M' for a move operation or a 'C' for a count operation. For move operations, the line also contains two integers: X and Y.For count operations, the line also contains a single integer: X. 

Note that the value for N does not appear in the input file. No move operation will request a move a stack onto itself. 
Output

Print the output from each of the count operations in the same order as the input file. 
Sample Input

6
M 1 6
C 1
M 2 4
M 2 6
C 3
C 4
Sample Output

1
0
2
*/


//更新状态的并查集
#include <stdio.h>
#include <string.h>
int arr[30001][2];
int find(int a)
{
	int t;
	if(arr[a][0]>=0)
	{
		t=arr[a][0];
		arr[a][0]=find(arr[a][0]);
		arr[a][1]+=arr[t][1];
	}
	else
		return a;
	return arr[a][0];
}
void uion(int a,int b)
{
	int s,t;
	s=find(a);
	t=find(b);
	arr[t][1]=-arr[s][0];
	arr[s][0]+=arr[t][0];
	arr[t][0]=s;
}
int main()
{
	int i,a,b,n;
	char c;
	for(i=0;i<30001;i++)
	{
		arr[i][0]=-1;
		arr[i][1]=0;
	}
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++)
	{
		c=getchar();
		if(c=='M')
		{
			scanf("%d%d",&a,&b);
			uion(a,b);//b-->a
		}
		else
		{
			scanf("%d",&a);
			b=find(a);
			printf("%d\n",-arr[b][0]-arr[a][1]-1);
		}
		getchar();
	}
	return 0;
}
