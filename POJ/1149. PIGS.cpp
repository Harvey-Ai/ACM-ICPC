/*
Description

Mirko works on a pig farm that consists of M locked pig-houses and Mirko can't unlock any pighouse because he doesn't have the keys. Customers come to the farm one after another. Each of them has keys to some pig-houses and wants to buy a certain number of pigs. 
All data concerning customers planning to visit the farm on that particular day are available to Mirko early in the morning so that he can make a sales-plan in order to maximize the number of pigs sold. 
More precisely, the procedure is as following: the customer arrives, opens all pig-houses to which he has the key, Mirko sells a certain number of pigs from all the unlocked pig-houses to him, and, if Mirko wants, he can redistribute the remaining pigs across the unlocked pig-houses. 
An unlimited number of pigs can be placed in every pig-house. 
Write a program that will find the maximum number of pigs that he can sell on that day.
Input

The first line of input contains two integers M and N, 1 <= M <= 1000, 1 <= N <= 100, number of pighouses and number of customers. Pig houses are numbered from 1 to M and customers are numbered from 1 to N. 
The next line contains M integeres, for each pig-house initial number of pigs. The number of pigs in each pig-house is greater or equal to 0 and less or equal to 1000. 
The next N lines contains records about the customers in the following form ( record about the i-th customer is written in the (i+2)-th line): 
A K1 K2 ... KA B It means that this customer has key to the pig-houses marked with the numbers K1, K2, ..., KA (sorted nondecreasingly ) and that he wants to buy B pigs. Numbers A and B can be equal to 0.
Output

The first and only line of the output should contain the number of sold pigs.
Sample Input

3 3
3 1 10
2 1 2 2
2 1 3 3
1 2 6
Sample Output

7
*/


#include <iostream>
using namespace std;
//求网络最大流,邻接阵形式
//返回最大流量,flow返回每条边的流量
//传入网络节点数n,容量mat,源点source,汇点sink
#define MAXN 1200
#define inf 1000000000

int max_flow(int n,int mat[][MAXN],int source,int sink,int flow[][MAXN])
{
	int pre[MAXN],que[MAXN],d[MAXN],p,q,t,i,j;
	if (source==sink) return inf;
    for (i=0;i<n;i++)
        for (j=0;j<n;flow[i][j++]=0);
	for (;;)
	{
       for (i=0;i<n;pre[i++]=0);
	   pre[t=source]=source+1,d[t]=inf;
	   for(p=q=0;p<=q&&!pre[sink];t=que[p++])
            for(i=0;i<n;i++)
                if(!pre[i]&&(j=mat[t][i]-flow[t][i]))
					pre[que[q++]=i]=t+1,d[i]=d[t]<j?d[t]:j;
				else if (!pre[i]&&(j=flow[i][t]))
                    pre[que[q++]=i]=-t-1,d[i]=d[t]<j?d[t]:j;
       if (!pre[sink]) break;
        for (i=sink;i!=source;)
            if (pre[i]>0)
               flow[pre[i]-1][i]+=d[sink],i=pre[i]-1;
            else
                flow[i][-pre[i]-1]-=d[sink],i=-pre[i]-1;
    }
    for (j=i=0;i<n;j+=flow[source][i++]);
    return j;
}


int mat[MAXN][MAXN],flow[MAXN][MAXN];
int n,m;
void init()
{
	int i,j,a,x;
	int q[1000];

    memset(mat,0,sizeof(mat));

    for (i=1;i<=m;i++)
       scanf("%d",&mat[n+i][n+m+1]);

    for(i=1;i<=n;i++)
    {
		scanf("%d",&a);
		for (j=0;j<a;j++)
        {
            scanf("%d",&q[j]);
			mat[i][q[j]+n]=inf;
		}
		scanf("%d",&mat[0][i]);
    }
    for(i=1;i<=m;i++)
    {
		int pre=0;
		for(j=1;j<=n;j++)
        if(mat[j][i+n]>0 )
        {
			if(pre>0)
				mat[j][pre]=inf;
			pre=j;
        }
    } 
}

int main ()
{
    while (scanf("%d%d",&m,&n)!=EOF)
    {
        init();
        printf("%d\n",max_flow(n+m+2,mat,0,n+m+1,flow));
    }

    return 0;
}
