/*
Description

Little John is playing very funny game with his younger brother. There is one big box filled with M&Ms of different colors. At first John has to eat several M&Ms of the same color. Then his opponent has to make a turn. And so on. Please note that each player has to eat at least one M&M during his turn. If John (or his brother) will eat the last M&M from the box he will be considered as a looser and he will have to buy a new candy box.

Both of players are using optimal game strategy. John starts first always. You will be given information about M&Ms and your task is to determine a winner of such a beautiful game.

Input

The first line of input will contain a single integer T – the number of test cases. Next T pairs of lines will describe tests in a following format. The first line of each test will contain an integer N – the amount of different M&M colors in a box. Next line will contain N integers Ai, separated by spaces – amount of M&Ms of i-th color.

Constraints:
1 <= T <= 474,
1 <= N <= 47,
1 <= Ai <= 4747

Output

Output T lines each of them containing information about game winner. Print “John” if John will win the game or “Brother” in other case.

Sample Input

2
3
3 5 1
1
1
Sample Output

John
Brother

*/

#include <stdio.h>
int main()
{
	int i,t,n,a,ct,nim;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ct=0;nim=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a);
			nim^=a;
			if(a==1)
				ct++;
		}
		if(ct==n)
		{
			if(n%2)
				printf("Brother\n");
			else
				printf("John\n");
		}
		else
		{
			if(ct==n-1)
				printf("John\n");
			else
			{
				if(nim==0)
					printf("Brother\n");
				else
					printf("John\n");
			}
		}
	}
	return 0;
}
