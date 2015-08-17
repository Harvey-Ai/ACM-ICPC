/*
Description

For 10 > N > 2 numbers we form N*(N-1)/2 sums by adding every pair of the numbers. Your task is to find the N numbers given the sums.
Input

Each line of input contains N followed by N*(N-1)/2 integer numbers separated by a space.
Output

For each line of input, output one line containing N integers in non-descending order such that the input numbers are pairwise sums of the N numbers. If there is more than one solution, any one will do; if there is no solution, print "Impossible".
Sample Input

3 1269 1160 1663
3 1 1 1
5 226 223 225 224 227 229 228 226 225 227
5 216 210 204 212 220 214 222 208 216 210
5 -1 0 -1 -2 1 0 -1 1 0 -1
5 79950 79936 79942 79962 79954 79972 79960 79968 79924 79932
Sample Output

383 777 886
Impossible
111 112 113 114 115
101 103 107 109 113
-1 -1 0 0 1
39953 39971 39979 39983 39989
*/


#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int ok,n,m;;
int arr[20],ss[100],tag[100];
void slove(int p)
{
	int tt[100];
	int i,j,k;
	if(ok)
		return;
	if(p==n)
	{
		printf("%d",arr[0]);
		for(i=1;i<n;i++)
			printf(" %d",arr[i]);
		putchar('\n');
		ok=1;
		return;
	}
	for(i=2;i<m;i++)
	{
		if(tag[i]==0)
		{
			arr[p]=ss[i]-arr[0];
			tag[i]=1;
			for(j=0;j<m;j++)
				tt[j]=tag[j];
			for(j=2,k=1;j<m;j++)
				if(tag[j]==0&&ss[j]==arr[k]+arr[p])
				{
					tag[j]=1;
					k++;
					if(k==p)
						break;
				}
			if(j<m)
				slove(p+1);
			for(j=0;j<m;j++)
				tag[j]=tt[j];
			tag[i]=0;
			break;
		}
	}
}

int main()
{
	int i;
	while(scanf("%d",&n)!=EOF)
	{
		m=n*(n-1)/2;
		for(i=0;i<m;i++)
			scanf("%d",&ss[i]);
		sort(&ss[0],&ss[m]);
		ok=0;
		memset(tag,0,sizeof(tag));
		tag[0]=tag[1]=1;
		for(i=2;i<m;i++)
		{
			arr[2]=(ss[1]-ss[0]+ss[i])/2;
			arr[0]=ss[1]-arr[2];
			arr[1]=ss[0]-arr[0];
			tag[i]=1;
			if(arr[1]+arr[2]==ss[i])
				slove(3);
			tag[i]=0;
			if(ok)
				break;
		}
		if(ok==0)
			printf("Impossible\n");
	}
	return 0;
}
