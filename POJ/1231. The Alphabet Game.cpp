/*
Description

Little Dara has recently learned how to write a few letters of the English alphabet (say k letters). He plays a game with his little sister Sara. He draws a grid on a piece of paper and writes p instances of each of the k letters in the grid cells. He then asks Sara to draw as many side-to-side horizontal and/or vertical bold lines over the grid lines as she wishes, such that in each rectangle containing no bold line, there would be p instances of one letter or nothing. For example, consider the sheet given in Figure 1, where Sara has drawn two bold lines creating four rectangles meeting the condition above. Sara wins if she succeeds in drawing the required lines. Dara being quite fair to Sara, wants to make sure that there would be at least one solution to each case he offers Sara. You are to write a program to help Dara decide on the possibility of drawing the right lines. 

Input

The first line of the input file contains a single integer t (1 <= t <= 10), the number of test cases, followed by the input data for each test case. The first line of each test case consists of two integers k (1 <= k <= 26), the number of different letters, and p (1 <= p <= 10), the number of instances of each letter. Followed by the first line, there are k lines, one for each letter, each containing p pairs of integers (xi, yi) for 1 <= i <= p. A pair indicates coordinates of the cell on the paper where one instance of the letter is written. The coordinates of the upper left cell of the paper is assumed to be (1,1). Coordinates are positive integers less than or equal to 1,000,000. You may assume that no cell contains more than one letter. 
Output

There should be one line per test case containing a single word YES or NO depending on whether the input paper can be divided successfully according to the constraints stated in the problem. 
Sample Input

2
3 2
6 4 8 4
4 2 2 1
2 3 2 4
3 3
1 1 3 1 5 1
2 1 4 1 6 1
2 2 4 2 8 1
Sample Output

YES
NO
*/


#include <stdio.h>
#define IsBtween(x, a, b) (x >= a && x <= b)
#define Min(x, y) (x > y ? y : x)
int vMax[30][2], hMax[30][2];
void getSlot(int a1, int b1, int a2, int b2, int &small, int &lager)
{
	if (a1 > a2)
	{
		small = b2;
		lager = a1;
	}
	else
	{
		small = b1;
		lager = a2;
	}
}
int main()
{
	int i, j, k, l, p, x, y, flag, uslot, dslot, rslot, lslot, testCase;
	scanf("%d", &testCase);
	while(testCase--)
	{
		scanf("%d %d", &k, &p);
		for(i = 0;i < 30 ;i++)
		{
			vMax[i][0] = hMax[i][0] = 1000001;
			vMax[i][1] = hMax[i][1] = 0;
		}
		for(i = 0;i < k;i++)
			for(j = 0;j < p;j++)
			{
				scanf("%d %d", &x, &y);
				if (x > hMax[i][1])	hMax[i][1] = x;
				if (x < hMax[i][0])	hMax[i][0] = x;
				if (y > vMax[i][1])	vMax[i][1] = y;
				if (y < vMax[i][0])	vMax[i][0] = y;
			}
		for(i = 0; i < k;i++)
		{
			for(j = i + 1;j < k;j++)
			{
				flag = 0;
				if (!IsBtween(hMax[i][0], hMax[j][0], hMax[j][1]) 
					&& !IsBtween(hMax[i][1], hMax[j][0], hMax[j][1]))
				{
					getSlot(hMax[i][0], hMax[i][1], hMax[j][0], hMax[j][1], lslot, rslot);
					lslot++;rslot--;
					for(l = 0;l < k;l++)
					{
						if (l == i || l == j)	continue; 
						if (IsBtween(lslot, hMax[l][0], hMax[l][1]) 
							&& IsBtween(rslot, hMax[l][0], hMax[l][1]))
							break;
					}
					if (l >= k)	flag = 1;
				}
				else	
				if (!IsBtween(vMax[i][0], vMax[j][0], vMax[j][1]) 
					&& !IsBtween(vMax[i][1], vMax[j][0], vMax[j][1]))
				{
					getSlot(vMax[i][0], vMax[i][1], vMax[j][0], vMax[j][1], uslot, dslot);
					dslot--;uslot++;
					for(l = 0;l < k;l++)
					{
						if (l == i || l == j)	continue; 
						if (IsBtween(uslot, vMax[l][0], vMax[l][1])
							&& IsBtween(dslot, vMax[l][0], vMax[l][1]))
							break;
					}
					if (l >= k)	flag = 1;
				}
				if (!flag)	break;
			}
			if (j < k)	break;
		}
		if (i < k)	printf("NO\n");
		else	printf("YES\n");
	}
	return 0;
}
