/*
Description

There is an apple tree outside of kaka's house. Every autumn, a lot of apples will grow in the tree. Kaka likes apple very much, so he has been carefully nurturing the big apple tree.

The tree has N forks which are connected by branches. Kaka numbers the forks by 1 to N and the root is always numbered by 1. Apples will grow on the forks and two apple won't grow on the same fork. kaka wants to know how many apples are there in a sub-tree, for his study of the produce ability of the apple tree.

The trouble is that a new apple may grow on an empty fork some time and kaka may pick an apple from the tree for his dessert. Can you help kaka?


Input

The first line contains an integer N (N ≤ 100,000) , which is the number of the forks in the tree.
The following N - 1 lines each contain two integers u and v, which means fork u and fork v are connected by a branch.
The next line contains an integer M (M ≤ 100,000).
The following M lines each contain a message which is either
"C x" which means the existence of the apple on fork x has been changed. i.e. if there is an apple on the fork, then Kaka pick it; otherwise a new apple has grown on the empty fork.
or
"Q x" which means an inquiry for the number of apples in the sub-tree above the fork x, including the apple (if exists) on the fork x
Note the tree is full of apples at the beginning

Output

For every inquiry, output the correspond answer per line.
Sample Input

3
1 2
1 3
3
Q 1
C 2
Q 1
Sample Output

3
2
*/


#include <stdio.h>
#include <vector>
#include <memory.h>
using namespace std;
vector <int> tree[100005];
int arr[100005],s[100005],e[100005],tag[100005];
int t,N;
int Lowbit(int t)
{
	return t & ( t ^ ( t - 1 ) ); 
}
int Sum(int end)
{
      int sum = 0;
      while(end > 0)
      {
          sum += arr[end];
          end -= Lowbit(end);
      }
      return sum;
}
void plus(int pos , int num)
{ 
      while(pos <= N)
      {
            arr[pos] += num;
            pos += Lowbit(pos);
      }
}
void dfs(int now, int father)
{
    int i;
    s[now]=t;   //前序遍历序号 
    for(i=0;i<tree[now].size();i++)
	{
        if(tree[now][i]!=father)
		{
            t++;
            dfs(tree[now][i],now);
        }
    }
    e[now]=t;   //后序遍历序号 

}
int main()
{
	int a,b,i,n,k;
	char c;
	while(scanf("%d",&N)!=EOF)
	{
		arr[0]=arr[N]=0;
		for(i=0;i<=N;i++)
			tree[i].clear();
		for(i=1;i<N;i++)
		{
			arr[i]=0;
			scanf("%d%d",&a,&b);
			tree[a].push_back(b);
			tree[b].push_back(a);
		}
		t=1;
		dfs(1,0);
		for(i=1;i<=N;i++)
		{
			tag[i]=1;
			plus(i,1);
		}
		scanf("%d",&n);
		while(n--)
		{
			getchar();
			c=getchar();
			scanf("%d",&k);
			if(c=='C')
			{
				if(tag[k]==1)
				{
					tag[k]=0;
					plus(s[k],-1);
				}
				else
				{
					tag[k]=1;
					plus(s[k],1);
				}
			}
			else
				printf("%d\n",Sum(e[k])-Sum(s[k]-1));
		}
	}
	return 0;
}
