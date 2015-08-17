/*
Description

Alice, a charming girl, have been dreaming of being a movie star for long. Her chances will come now, for several filmmaking companies invite her to play the chief role in their new films. Unfortunately, all these companies will start making the films at the same time, and the greedy Alice doesn't want to miss any of them!! You are asked to tell her whether she can act in all the films. 

As for a film, 
it will be made ONLY on some fixed days in a week, i.e., Alice can only work for the film on these days; 
Alice should work for it at least for specified number of days; 
the film MUST be finished before a prearranged deadline.

For example, assuming a film can be made only on Monday, Wednesday and Saturday; Alice should work for the film at least for 4 days; and it must be finished within 3 weeks. In this case she can work for the film on Monday of the first week, on Monday and Saturday of the second week, and on Monday of the third week. 

Notice that on a single day Alice can work on at most ONE film. 
Input

The first line of the input contains a single integer T (1 <= T <= 20), the number of test cases. Then T cases follow. Each test case begins with a single line containing an integer N (1 <= N <= 20), the number of films. Each of the following n lines is in the form of "F1 F2 F3 F4 F5 F6 F7 D W". Fi (1 <= i <= 7) is 1 or 0, representing whether the film can be made on the i-th day in a week (a week starts on Sunday): 1 means that the film can be made on this day, while 0 means the opposite. Both D (1 <= D <= 50) and W (1 <= W <= 50) are integers, and Alice should go to the film for D days and the film must be finished in W weeks.
Output

For each test case print a single line, 'Yes' if Alice can attend all the films, otherwise 'No'.
Sample Input

2
2
0 1 0 1 0 1 0 9 3
0 1 1 1 0 0 0 6 4
2
0 1 0 1 0 1 0 9 4
0 1 1 1 0 0 0 6 2
Sample Output

Yes
No
Hint

A proper schedule for the first test case:



date     Sun    Mon    Tue    Wed    Thu    Fri    Sat

week1          film1  film2  film1         film1

week2          film1  film2  film1         film1

week3          film1  film2  film1         film1

week4          film2  film2  film2

*/


#include <stdio.h>
#include <string.h>
int g[1005][355],cx[1005],cy[355],used[355];
int nx,ny;
int path(int u)
{
	int i;
	for(i=0;i<ny;i++)
	{
		if(g[u][i]&&!used[i])
		{
			used[i]=1;
			if(cy[i]==-1||path(cy[i]))
			{
				cx[u]=i;
				cy[i]=u;
				return 1;
			}
		}
	}
	return 0;
}
int maxmatch()
{
	int i,res;
	res=0;
	memset(cx,0xff,sizeof(cx));
    memset(cy,0xff,sizeof(cy));
	for(i=0;i<nx;i++)
		if(cx[i]==-1)
		{
			memset(used,0,sizeof(used));
			res+=path(i);
		}
	return res;
}

int main()
{
	int arr[10];
	int i,j,k,l,dd,n,d,w,ncase,maxw;
	scanf("%d",&ncase);
	while(ncase--)
	{
		memset(g,0,sizeof(g));
		dd=0;maxw=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			for(j=0;j<7;j++)
				scanf("%d",&arr[j]);
			scanf("%d%d",&d,&w);
			if(maxw<w)
				maxw=w;
			for(j=0;j<d;j++)
			{
				for(l=0;l<7;l++)
					if(arr[l])
					{
						for(k=0;k<w;k++)	
							g[j+dd][k*7+l]=1;
					}
			}
			dd+=d;
		}
		nx=dd;ny=maxw*7;
		if(dd>maxw*7||maxmatch()<dd)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}
