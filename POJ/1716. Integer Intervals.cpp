/*
Description

An integer interval [a,b], a < b, is a set of all consecutive integers beginning with a and ending with b. 
Write a program that: finds the minimal number of elements in a set containing at least two different integers from each interval.
Input

The first line of the input contains the number of intervals n, 1 <= n <= 10000. Each of the following n lines contains two integers a, b separated by a single space, 0 <= a < b <= 10000. They are the beginning and the end of an interval.
Output

Output the minimal number of elements in a set containing at least two different integers from each interval.
Sample Input

4
3 6
2 4
0 2
4 7
Sample Output

4
*/

#include <stdio.h>
#include <algorithm>
using namespace std;
bool tag[10001];
struct dd
{
	int a,b;
}arr[10001];
bool cmp(const dd a,const dd b)
{
	if(a.a<b.a)
		return 1;
	else
	{
		if(a.a>b.a)
			return 0;
		else
			return a.b>b.b;
	}
}
int main()
{
	int i,j,n,cnt,res;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d%d",&arr[i].a,&arr[i].b);
	sort(&arr[0],&arr[n],cmp);
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
		{
			if(arr[j].b<=arr[i].b)
			{
				arr[i].a=-1;
				break;
			}
			if(arr[j].a>=arr[i].b)
				break;
		}
	res=0;
	for(i=0;i<n;i++)
	{
		if(arr[i].a==-1)
			continue;
		cnt=0;
		for(j=arr[i].a;j<=arr[i].b&&cnt<2;j++)
			if(tag[j])
				cnt++;
		j=arr[i].b;
		while(cnt<2)
		{
			if(tag[j]==0)
			{
				tag[j]=1;
				cnt++;
				res++;
			}
			j--;
		}
	}
	printf("%d\n",res);
	return 0;
}
