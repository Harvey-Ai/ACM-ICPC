/*
Description

Bessie is traveling on a road teeming with interesting landmarks. The road is labeled just like a number line, and Bessie starts at the "origin" (x = 0). A total of N (1 ≤ N ≤ 50,000) landmarks are located at points x1, x2, ..., xN (-100,000 ≤ xi ≤ 100,000). Bessie wants to visit as many landmarks as possible before sundown, which occurs in T (1 ≤ T ≤ 1,000,000,000) minutes. She travels 1 distance unit in 1 minute.

Bessie will visit the landmarks in a particular order. Since the landmarks closer to the origin are more important to Farmer John, she always heads for the unvisited landmark closest to the origin. No two landmarks will be the same distance away from the origin.

Help Bessie determine the maximum number of landmarks she can visit before the day ends.

Input

* Line 1: Two space-separated integers: T and N
* Lines 2..N+1: Line i+1 contains a single integer that is the location of the ith landmark: xi

Output

* Line 1: The maximum number of landmarks Bessie can visit.

Sample Input

25 5
10
-3
8
-7
1
Sample Output

4*/

#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[50001],brr[50001];
bool cmp(const int a,const int b)
{
	if(a<b) return 0;
	else return 1;
}
int main()
{
	int i,k,l,t,n,a,p,mint,s1,s2;
	scanf("%d%d",&t,&n);
	k=l=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a);
		if(a>=0)
			arr[k++]=a;
		else
			brr[l++]=a;
	}
	sort(&arr[0],&arr[k]);
	sort(&brr[0],&brr[l],cmp);
	arr[k]=1000000000;
	brr[l]=-1000000000;
	if(arr[0]>-brr[0])
	{
		p=brr[0];
		mint=-brr[0];
		s1=1;
		s2=0;
	}
	else
	{
		p=arr[0];
		mint=arr[0];
		s1=0;
		s2=1;
	}
	if(mint>t)
	{
		printf("0\n");
		return 0;
	}
	while(mint<=t)
	{
		if(arr[s2]>-brr[s1])
		{
			mint+=p-brr[s1];
			p=brr[s1];
			s1++;
		}
		else
		{
			mint+=arr[s2]-p;
			p=arr[s2];
			s2++;
		}
	}
	printf("%d\n",s1+s2-1);
	return 0;
}
