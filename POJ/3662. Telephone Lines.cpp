/*
Description

Farmer John wants to set up a telephone line at his farm. Unfortunately, the phone company is uncooperative, so he needs to pay for some of the cables required to connect his farm to the phone system.

There are N (1 ≤ N ≤ 1,000) forlorn telephone poles conveniently numbered 1..N that are scattered around Farmer John's property; no cables connect any them. A total of P (1 ≤ P ≤ 10,000) pairs of poles can be connected by a cable; the rest are too far apart.

The i-th cable can connect the two distinct poles Ai and Bi, with length Li (1 ≤ Li ≤ 1,000,000) units if used. The input data set never names any {Ai, Bi} pair more than once. Pole 1 is already connected to the phone system, and pole N is at the farm. Poles 1 and N need to be connected by a path of cables; the rest of the poles might be used or might not be used.

As it turns out, the phone company is willing to provide Farmer John with K (0 ≤ K < N) lengths of cable for free. Beyond that he will have to pay a price equal to the length of the longest remaining cable he requires (each pair of poles is connected with a separate cable), or 0 if he does not need any additional cables.

Determine the minimum amount that Farmer John must pay.

Input

* Line 1: Three space-separated integers: N, P, and K
* Lines 2..P+1: Line i+1 contains the three space-separated integers: Ai, Bi, and Li

Output

* Line 1: A single integer, the minimum amount Farmer John can pay. If it is impossible to connect the farm to the phone company, print -1.

Sample Input

5 7 1
1 2 5
3 1 4
2 4 8
3 2 3
5 2 9
3 4 7
4 5 6
Sample Output

4

*/


#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[10001],g[1001][1001],used[1001],ff[1001];
int n,num,cost,ok;
void digkstra()
{
	int i,j,u,llf,temp;
	for(i=0;i<n;i++)
	{
		ff[i]=1001;
		used[i]=0;
	}
	ff[0]=0;
	used[0]=1;
	u=0;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n;j++)
			if(g[u][j]&&!used[j])
			{
				if(g[u][j]>cost)
					temp=ff[u]+1;
				else
					temp=ff[u];
				if(ff[j]>temp)
					ff[j]=temp;
			}
		llf=1001;
		for(j=0;j<n;j++)
			if(ff[j]<llf&&!used[j])
			{
				llf=ff[j];
				u=j;
			}
		if(llf==1001)
			break;
		used[u]=1;
	}
	if(ff[n-1]>num)
		ok=0;
	else
		ok=1;
}

int main()
{
	int i,p,a,b,l,head,tail,res;
	while(scanf("%d%d%d",&n,&p,&num)!=EOF)
	{
		for(i=0;i<p;i++)
		{
			scanf("%d%d%d",&a,&b,&l);
			a--;b--;
			g[a][b]=g[b][a]=l;
			arr[i+1]=l;
		}
		arr[0]=0;
		sort(&arr[0],&arr[p+1]);
		head=0;tail=p;
		res=-1;
		while(tail>=head)
		{
			cost=arr[(head+tail)/2];
			digkstra();
			if(ok==0)
				head=(head+tail)/2+1;
			else
			{
				tail=(head+tail)/2-1;
				res=cost;
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
