#include <stdio.h>
#include <string.h>

char strA[1005], strB[1005];
int len1, len2;
// 0 del, 1 insert, 2 ch
int dp[1005][1005], action[1005][1005];


int change(int p1, int p2)
{
	int min = 10000000;
	int temp, act;

	if (p1 == len1 && p2 == len2)
		return 0;
	// del;
	if (p1 < len1)
	{
		if (dp[p1 + 1][p2] != -1)
			min = dp[p1 + 1][p2] + 1;
		else
			min = change(p1 + 1, p2) + 1;
		act = 0;
	}

	// insert
	if (p2 < len2)
	{
		if (dp[p1][p2 + 1] != -1)
			temp = dp[p1][p2 + 1] + 1;
		else
			temp = change(p1, p2 + 1) + 1;
		if (temp < min)
		{
			min = temp;
			act = 1;
		}
	}

	// ch
	if (p1 < len1 && p2 < len2)
	{
		if (dp[p1 + 1][p2 + 1] != -1)
			temp = dp[p1 + 1][p2 + 1] + 1;
		else
			temp = change(p1 + 1, p2 + 1) + 1;
		if (strA[p1] == strB[p2])
			temp--;
		if (temp < min)
		{
			min = temp;
			act = 2;
		}
	}

	dp[p1][p2] = min;
	action[p1][p2] = act;
	return min;
}

int main()
{
	int p1, p2, pp;
	int i, j;
	int res, acc;
	scanf("%s %s", strA, strB);
	len1 = strlen(strA);
	len2 = strlen(strB);

	for(i = 0;i <= len1;i++)
		for(j = 0;j <= len2;j++)
		{
			dp[i][j] = -1;
			action[i][j] = -1;
		}
	res = change(0, 0);
	printf("%d\n", res);

	p1 = p2 = 0;
	pp = 1;
	while(p1 < len1 || p2 < len2)
	{
		acc = action[p1][p2];
		switch(acc)
		{
			case 0: {printf("DELETE %d\n", pp);p1++;break;}
			case 1: {printf("INSERT %d %c\n", pp, strB[p2]);p2++;pp++;break;}
			case 2: 
			{
				if (strA[p1] == strB[p2])
				{
					p1++;p2++;
					pp++;
				}
				else
				{
					printf("REPLACE %d %c\n", pp, strB[p2]);
					pp++;
					p1++;p2++;
				}
				break;
			}
		}			
	}

	return 0;
}
