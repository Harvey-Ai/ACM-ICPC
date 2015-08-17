/*
Description

Farmer John's N (1 ≤ N ≤ 10,000) cows are lined up to be milked in the evening. Each cow has a unique "grumpiness" level in the range 1...100,000. Since grumpy cows are more likely to damage FJ's milking equipment, FJ would like to reorder the cows in line so they are lined up in increasing order of grumpiness. During this process, the places of any two cows (not necessarily adjacent) can be interchanged. Since grumpy cows are harder to move, it takes FJ a total of X+Y units of time to exchange two cows whose grumpiness levels are X and Y.

Please help FJ calculate the minimal time required to reorder the cows.

Input

Line 1: A single integer: N. 
Lines 2..N+1: Each line contains a single integer: line i+1 describes the grumpiness of cow i. 
Output

Line 1: A single line with the minimal time required to reorder the cows in increasing order of grumpiness.
Sample Input

3
2
3
1
Sample Output

7
Hint

2 3 1 : Initial order. 
2 1 3 : After interchanging cows with grumpiness 3 and 1 (time=1+3=4). 
1 2 3 : After interchanging cows with grumpiness 1 and 2 (time=2+1=3).
*/


#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[10005],brr[10005];
int search(int t,int low,int high)
{
	int mid;
	while(high>=low)
	{
		mid=(high+low)/2;
		if(t==arr[mid])
			return mid;
		if(t>arr[mid])
			low=mid+1;
		else
			high=mid-1;
	}
}
int main()
{
	int i,tt,sum,temp,num,min,m,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{

		scanf("%d",&arr[i]);
		brr[i]=arr[i];
	}
	sort(arr,arr+n);
	m=arr[0];
	sum=0;
	for(i=0;i<n;i++)
	{
		temp=i;num=0;min=0;
		if(brr[temp])
			min=brr[temp];
		while(brr[temp])
		{
			if(brr[temp]<min)
				min=brr[temp];
			sum+=brr[temp];
			tt=temp;
			temp=search(brr[temp],0,n-1);
			brr[tt]=0;
			num++;
		}
		if(min)
		{
			if((num-2)*min<min+(num+1)*m)
				sum+=(num-2)*min;
			else
				sum+=min+(num+1)*m;
		}
	}
	printf("%d\n",sum);
	return 0;
}
