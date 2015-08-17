/*
Description

Farmer John's cows are getting restless about their poor telephone service; they want FJ to replace the old telephone wire with new, more efficient wire. The new wiring will utilize N (2 ≤ N ≤ 100,000) already-installed telephone poles, each with some heighti meters (1 ≤ heighti ≤ 100). The new wire will connect the tops of each pair of adjacent poles and will incur a penalty cost C × the two poles' height difference for each section of wire where the poles are of different heights (1 ≤ C ≤ 100). The poles, of course, are in a certain sequence and can not be moved.

Farmer John figures that if he makes some poles taller he can reduce his penalties, though with some other additional cost. He can add an integer X number of meters to a pole at a cost of X2.

Help Farmer John determine the cheapest combination of growing pole heights and connecting wire so that the cows can get their new and improved service.

Input

* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains a single integer: heighti

Output

* Line 1: The minimum total amount of money that it will cost Farmer John to attach the new telephone wire.

Sample Input

5 2
2
3
5
1
4
Sample Output

15
*/

#include <stdio.h>
double arr[2][100];
double temp,tt,min;
int main()
{
	int i,k,a,p,s,h,lh,n,c,tm;
	while(scanf("%d%d",&n,&c)!=EOF)
	{
		scanf("%d",&h);
		h--;
		for(i=h;i<100;i++)
			arr[0][i]=(i-h)*(i-h);
		lh=h;p=1;s=0;
		for(i=1;i<n;i++)
		{
			scanf("%d",&h);
			h--;
			for(k=h;k<=lh;k++)
				arr[p][k]=arr[s][lh]+(k-h)*(k-h)+(lh-k)*c;
			if(h>lh+1)	a=h;
			else	a=lh+1;
			min=arr[s][lh];
			for(k=lh+1;k<=a;k++)
			{
				min+=c;
				if(arr[s][k]<min)
					min=arr[s][k];
			}
			for(k=a;k<100;k++)
			{
				if(min>arr[s][k])
					min=arr[s][k];
				arr[p][k]=min+(k-h)*(k-h);
				min+=c;
			}
			lh=h;
			tm=p;
			p=s;
			s=tm;
		}
		min=arr[s][lh];
		for(i=lh;i<100;i++)
			if(arr[s][i]<min)
				min=arr[s][i];
		printf("%.0lf\n",min);
	}
	return 0;
}
