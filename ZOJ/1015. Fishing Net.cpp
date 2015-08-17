/*
In a highly modernized fishing village, inhabitants there make a living on fishery. Their major tools, fishing nets, are produced and fixed by computer. After catching fishes each time, together with plenty of fishes, they will bring back the shabby fishing nets, which might be full of leaks. Then they have to inspect those nets. If there exist large leaks, they have to repair them before launching out again.

Obviously, the smaller the leaks in the fishing nets are, the more fishes they will catch. So after coming back, those fishermen will input the information of the fishing nets into the computer to check whether the nets have leaks.

The checking principle is very simple: The computer regards each fishing net as a simple graph constructed by nodes and edges. In the graph, if any circle whose length (the number of edges) is larger than 3 must has at least one chord, the computer will output "Perfect" indicating that the fishnet has no leaks. Otherwise, "Imperfect" will be displayed and the computer will try to repair the net. 

Note: A circle is a closed loop, which starts from one node, passes through other distinct nodes and back to the starting node. A chord is an edge, which connects two different nodes on the circle, but it does not belong to the set of edges on the circle.


Input

The input file contains several test cases representing different fishing nets. The last test case in the input file is followed by a line containing 0 0.

The first line of each test case contains two integers, n and m, indicating the number of nodes and edges on the net respectively, 1 <= n <= 1000. It is followed by m lines accounting for the details of the edges. Each line consists of two integers xi and yi, indicating there is an edge between node xi and node yi.


Output

For each test case, display its checking results. The word "Imperfect" suggests that the corresponding fishing net is leaking, while the word "Perfect" stands for a fishing net in good condition.

Follow the output for each net with a blank line.


Sample Input

4 4
1 2
2 3
3 4
4 1
3 3
1 2
2 3
3 1
0 0


Output for the Sample Input

Imperfect

Perfect
*/

#include <cstdio>
#include <string.h>
bool graph[1001][1001],used[1001];
int A[1001],link[1001];
int main()
{
	int a,b,i,j,k,y,max,max_id,m,n;
	while(scanf("%d%d",&n,&m),n||m)
	{
		memset(graph,0,sizeof(graph));
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			graph[a][b]=graph[b][a]=1;
		}
		memset(used,0,sizeof(used));
		A[n]=1;used[1]=1;
		for(i=n-1;i>0;i--)
		{
			memset(link,0,sizeof(link));
			for(k=1;k<=n;k++)
			{
				if(!used[k])
				{
					for(j=n;j>i;j--)
					{
						if(graph[A[j]][k])
							link[k]++;
					}
				}
			}
			max=0;
			for(j=1;j<=n;j++)
				if(link[j]>max)
				{
					max=link[j];
					max_id=j;
				}
				A[i]=max_id;
				used[max_id]=true;
		}
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
				if(graph[A[i]][A[j]])
					break;
			y=j;
			j++;
			while(j<=n)
			{
				if(graph[A[i]][A[j]]&&(!graph[A[y]][A[j]]))
					break;
				j++;
			}
			if(j<=n)
				break;
		}
		if(i<n)
			printf("Imperfect\n\n");
		else
			printf("Perfect\n\n");
	}
	return 0;
}
