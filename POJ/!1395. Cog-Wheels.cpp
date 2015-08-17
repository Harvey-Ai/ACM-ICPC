/*
Description

Background 

Your little sister has got a new mechanical building kit, which includes many cog-wheels of different sizes. She starts building gears with different ratios, but soon she notices that there are some ratios which are quite difficult to realize, and some others she cannot realize at all. She would like to have a computer program that tells her what ratios can be realized and what ratios cannot. She asks you to write a program that does the job. 

For example, let us assume that the kit contains cog-wheels with 6, 12, and 30 cogs. Your sister wants to realize a gear of ratio 5 : 4. One possible solution is shown in Figure 2. 

 
Figure 2: Combination of cog-wheels realizing a gear of 5 : 4.


It depicts a complete gear of ratio 5 : 4. Four wheels are used: cog-wheels of sizes 30 and 12 on the first axis, cog-wheels of sizes 6 and 12 on the second axis. The gear ratio is given by 


as desired. However, a gear of ratio 1 : 6 cannot be realized using the cog-wheels your sister has. 


Problem 

Given the sizes of the cog-wheels in the kit (i.e. the number of cogs they have), decide whether a given gear ratio can be built or not. You may use any finite number of cog-wheels of each size available. 
Input

The input begins with a line containing the number of scenarios. 

The input for each scenario starts with a description of the cog-wheels in the kit. First, there is a line containing the number n of different sizes of cog-wheels (1<=n<=20). The next line contains n numbers c1 . . . cn, separated by single blanks. These denote the n different sizes of the cog-wheels in the kit, with 5<=ci<=100 for i = 1, . . . , n. You may assume that there is a cog-wheel of smallest size c = min{c1, . . . , cn} in the kit such that all sizes c1, . . . , cn are multiples of c. 

The line describing the available cog-wheels is followed by the list of gear ratios to be realized. It starts with a line containing the numbermof ratios. The nextmlines each contain two integers a and b, separated by a single blank. They denote the ratio a : b, with 1<=a, b<=10000. 
Output

The output for every scenario begins with a line containing "Scenario #i:", where i is the number of the scenario starting at 1. Then print the results for all the gear ratios given in that scenario. For each gear ratio a : b, print a line containing either Gear ratio a:b can be realized. 

or 

Gear ratio a:b cannot be realized. 

Terminate the output of each scenario with a blank line.
Sample Input

2
3
6 12 30
2
5 4
1 6
1
42
2
13 13
42 1
Sample Output

Scenario #1:
Gear ratio 5:4 can be realized.
Gear ratio 1:6 cannot be realized.

Scenario #2:
Gear ratio 13:13 can be realized.
Gear ratio 42:1 cannot be realized.
*/


#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	int gcd(int x, int y);
	int arr[25];
	int i,j,k,ncase,ntest,a1,b1,a,b,c,n;
	scanf("%d",&ncase);
	for(i=0;i<ncase;i++)
	{
		scanf("%d",&n);
		for(j=0;j<n;j++)
			scanf("%d",&arr[j]);
		sort(&arr[0],&arr[n]);
		for(j=1;j<n;j++)
			arr[j]/=arr[0];
		for(j=1;j<n;j++)
		{
			for(k=1;k<n;k++)
			{
				if(j==k)
					continue;
				c=gcd(arr[j],arr[k]);
				arr[j]/=c;
				arr[k]/=c;
			}
		}
		sort(&arr[1],&arr[n]);
		printf("Scenario #%d:\n",i+1);
		scanf("%d",&ntest);
		for(j=0;j<ntest;j++)
		{
			scanf("%d%d",&a,&b);
			a1=a;b1=b;
			c=gcd(a,b);
			a/=c;
			b/=c;
			for(k=1;k<n;k++)
			{
				c=gcd(a,arr[k]);
				if(c!=1)
				{
					while(a%c==0)
						a/=c;
				}
				if(a==1||arr[k]>a)
					break;
			}
			if(a!=1)
			{
				printf("Gear ratio %d:%d cannot be realized.\n",a1,b1);
				continue;
			}
			for(k=1;k<n;k++)
			{
				c=gcd(b,arr[k]);
				if(c!=1)
				{
					while(b%c==0)
						b/=c;
				}
				if(b==1||arr[k]>b)
					break;
			}
			if(b==1)
				printf("Gear ratio %d:%d can be realized.\n",a1,b1);
			else
				printf("Gear ratio %d:%d cannot be realized.\n",a1,b1);
		}
	}
	return 0;
}

int gcd(int x, int y)
{
	int tmp;
	while(y)
	{
		tmp=y;
		y = x % y;
		x = tmp;
	}
	return x;
}
