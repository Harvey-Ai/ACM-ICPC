/*
Description

The advice to "buy low" is half the formula to success in the bovine stock market.To be considered a great investor you must also follow this problems' advice: 
                    "Buy low; buy lower"

Each time you buy a stock, you must purchase it at a lower price than the previous time you bought it. The more times you buy at a lower price than before, the better! Your goal is to see how many times you can continue purchasing at ever lower prices. 

You will be given the daily selling prices of a stock (positive 16-bit integers) over a period of time. You can choose to buy stock on any of the days. Each time you choose to buy, the price must be strictly lower than the previous time you bought stock. Write a program which identifies which days you should buy stock in order to maximize the number of times you buy. 

Here is a list of stock prices: 
 Day   1  2  3  4  5  6  7  8  9 10 11 12

Price 68 69 54 64 68 64 70 67 78 62 98 87


The best investor (by this problem, anyway) can buy at most four times if each purchase is lower then the previous purchase. One four day sequence (there might be others) of acceptable buys is: 
Day    2  5  6 10

Price 69 68 64 62
Input

* Line 1: N (1 <= N <= 5000), the number of days for which stock prices are given 

* Lines 2..etc: A series of N space-separated integers, ten per line except the final line which might have fewer integers. 
Output

Two integers on a single line: 
* The length of the longest sequence of decreasing prices 
* The number of sequences that have this length (guaranteed to fit in 31 bits) 

In counting the number of solutions, two potential solutions are considered the same (and would only count as one solution) if they repeat the same string of decreasing prices, that is, if they "look the same" when the successive prices are compared. Thus, two different sequence of "buy" days could produce the same string of decreasing prices and be counted as only a single solution. 
Sample Input

12
68 69 54 64 68 64 70 67 78 62
98 87
Sample Output

4 2
*/



#include <stdio.h>
#include <string.h>
#define N 5005

int arr[N];
int longest[N];
int ways[N];
int main()
{
	int i, j, wayC, max, maxC, res, n;
	scanf("%d", &n);

	for(i = 0;i < n;i++)
		scanf("%d", &arr[i]);

	memset(longest, 0, sizeof(longest));

	longest[0] = 1;
	ways[0] = 1;
	for(i = 1;i < n;i++)
	{
		wayC = 1;
		max = 1;
		for(j = 0;j < i;j++)
		{
			if (arr[i] < arr[j])
			{
				if (max < longest[j] + 1)
				{
					max = longest[j] + 1;
					wayC = ways[j];
				}
				else
					if (max == longest[j] + 1)
						wayC += ways[j];
			}
		}
		for (j = 0;j < i;j++)
			if (max == longest[j] && arr[j] == arr[i])
				ways[j] = 0;
		ways[i] = wayC;
		longest[i] = max;
	}

	maxC = 1;
	res = 1;
	for(i = 1;i < n;i++)
	{
		if (longest[i] > maxC)
		{
			maxC = longest[i];
			res = ways[i];
		}
		else
		{
			if (longest[i] == maxC)
				res += ways[i];
		}
	}
	printf("%d %d\n", maxC, res);
	return 0;
}
