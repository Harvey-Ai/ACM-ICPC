/*
Description

A supermarket has a set Prod of products on sale. It earns a profit px for each product x∈Prod sold by a deadline dx that is measured as an integral number of time units starting from the moment the sale begins. Each product takes precisely one unit of time for being sold. A selling schedule is an ordered subset of products Sell ≤ Prod such that the selling of each product x∈Sell, according to the ordering of Sell, completes before the deadline dx or just when dx expires. The profit of the selling schedule is Profit(Sell)=Σx∈Sellpx. An optimal selling schedule is a schedule with a maximum profit. 
For example, consider the products Prod={a,b,c,d} with (pa,da)=(50,2), (pb,db)=(10,1), (pc,dc)=(20,2), and (pd,dd)=(30,1). The possible selling schedules are listed in table 1. For instance, the schedule Sell={d,a} shows that the selling of product d starts at time 0 and ends at time 1, while the selling of product a starts at time 1 and ends at time 2. Each of these products is sold by its deadline. Sell is the optimal schedule and its profit is 80. 


Write a program that reads sets of products from an input text file and computes the profit of an optimal selling schedule for each set of products. 
Input

A set of products starts with an integer 0 <= n <= 10000, which is the number of products in the set, and continues with n pairs pi di of integers, 1 <= pi <= 10000 and 1 <= di <= 10000, that designate the profit and the selling deadline of the i-th product. White spaces can occur freely in input. Input data terminate with an end of file and are guaranteed correct.
Output

For each set of products, the program prints on the standard output the profit of an optimal selling schedule for the set. Each result is printed from the beginning of a separate line.
Sample Input

4  50 2  10 1   20 2   30 1

7  20 1   2 1   10 3  100 2   8 2
   5 20  50 10
Sample Output

80
185
Hint

The sample input contains two product sets. The first set encodes the products from table 1. The second set is for 7 products. The profit of an optimal schedule for these products is 185.

*/


#include <stdio.h>
#include <stdlib.h>
#define N 100005

struct product
{
	int pf;
	int dl;
};

int cmp(const void *a, const void *b)
{
	return ((struct product *)b)->pf - ((struct product *)a)->pf;
}

int main()
{
	int i, n, maxTime;
	int ff, temp, salT, res;
	struct product pd[N];
	int time[N];

	while(scanf("%d", &n) != EOF)
	{
		maxTime = 0;
		res = 0;
		for(i = 0;i < n;i++)
		{
			scanf("%d %d", &pd[i].pf, &pd[i].dl);
			if (pd[i].dl > maxTime)
				maxTime = pd[i].dl;
		}

		qsort(pd, n, sizeof(pd[0]), cmp);
		
		memset(time, -1, sizeof(time));

		for(i = 0;i < n;i++)
		{
			salT = pd[i].dl;
			while(time[salT] >= 0)
				salT = time[salT];

			if (salT)
			{
				res += pd[i].pf;
				time[salT] = salT - 1;
				ff = pd[i].dl;
				while(ff != salT)
				{
					temp = time[ff];
					time[ff] = salT - 1;
					ff = temp;
				}
			}
			else
			{
				time[pd[i].dl] = 0;
				ff = pd[i].dl;
				while(ff != 0)
				{
					temp = time[ff];
					time[ff] = 0;
					ff = temp;
				}
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
