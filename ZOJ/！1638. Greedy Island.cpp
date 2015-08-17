/*
Gon and Killua are engaged in a game of Greedy Island. The goal of the game is to collect 100 spell cards distributed all over the game. A spell card has three properties: Attack, Defense and Special. The numeric value of each property is between 0 and 100. Each card can be used only ONCE. All the spell cards must be stored in the Book - the initial item of the game. The Book can store at most 50 spell cards, so Gon and Killua can have at most 100 spell cards in all. Now Gon and Killua have n spell cards, and they want to use A cards for Attack, B cards for Defense and C cards for Special uses (A + B + C <= 100). If n > A + B + C, they have to discard some cards.
They would like to know the maximum sum of the Attack value in Attack Group, Defense value in Defense Group and Special value in Special Group. If there are multiple solutions, choose the solution with the maximum sum of ALL the properties of all the cards.


Input

The first line contains an integer T (1 <= T <= 10), the number of test cases.

For each test case, the first line contains a single integer n (n <= 100,100); the next line contains three integers A, B and C (A, B, C >= 0, A + B + C <= n); the following n lines contain the Attack value, Defense value and Special value of the n spell cards.


Output

For each test case, print the maximum sum of Attack value in Attack Group, Defense value in Defense Group and Special value in Special Group, and maximum sum of ALL the properties of all the cards in one line, separated with one space.


Sample Input

2
3
1 1 1
100 0 0
0 100 0
0 0 100
4
1 1 1
12 32 44
33 48 37
37 38 33
46 79 78

Sample Output

300 300
163 429
*/


#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct cardType
{
	int a, b, c;
	int used;
};
cardType cards[100106];

bool cmp1(const cardType &card1, const cardType &card2)
{
	return card1.a > card2.a;
}

bool cmp2(const cardType &card1, const cardType &card2)
{
	return card1.b > card2.b;
}

bool cmp3(const cardType &card1, const cardType &card2)
{
	return card1.c > card2.c;
}

int graph[305][305];
int matchX[305], matchY[305];
int lx[305], ly[305];
int visitX[305], visitY[305];
int n;

bool findAug(int x)
{
	visitX[x] = 1;
	for(int i = 0;i < n;i++)
		if (!visitY[i] && lx[x] + ly[i] == graph[x][i] && graph[x][i] != 0)
		{
			visitY[i] = 1;
			if (matchY[i] == -1 || findAug(matchY[i]))
			{
				matchX[x] = i;
				matchY[i] = x;
				return true;
			}
		}

	return false;
}

int maxMatch()
{
	for(int i = 0;i < n;i++)
		matchX[i] = matchY[i] = -1;

	for(int i = 0;i < n;i++)
	{
		ly[i] = 0;
		lx[i] = -100000000;
		for (int j = 0;j < n;j++)
			if (lx[i] < graph[i][j])
				lx[i] = graph[i][j];
	}

	for(int i = 0;i < n;i++)
	{
		memset(visitX, 0, sizeof(visitX));
		memset(visitY, 0, sizeof(visitY));
		while(!findAug(i))
		{
			int minDist = 1000000000;
			for(int j = 0;j < n;j++)
			{
				if (!visitX[j])
					continue;
				for(int k = 0;k < n;k++)
				{
					if (visitY[k])
						continue;
					minDist = min(minDist, lx[j] + ly[k] - graph[j][k]);
				}
			}

			for(int j = 0;j < n;j++)
			{
				if (visitX[j])
					lx[j] -= minDist;
				if (visitY[j])
					ly[j] += minDist;
			}
			memset(visitX, 0, sizeof(visitX));
			memset(visitY, 0, sizeof(visitY));
		}
	}
}

int main()
{
	int ncase;
	cin >> ncase;

	while(ncase--)
	{
		int nn;
		int a, b, c;
		scanf("%d", &nn);
		scanf("%d %d %d", &a, &b, &c);
		for(int i = 0;i < nn;i++)
		{
			scanf("%d %d %d", &cards[i].a, &cards[i].b, &cards[i].c);
			cards[i].used = 0;
		}

		n = min((a + b + c) * 3, nn);
		sort(cards, cards + nn, cmp1);
		for(int i = 0;i < a * 3 && i < nn;i++)
			cards[i].used = 1;
		sort(cards, cards + nn, cmp2);
		for(int i = 0, j = 0;j < b * 3 && i < nn;i++, j++)
		{
			if (cards[i].used == 1)
				j--;
			else
				cards[i].used = 1;
		}
		sort(cards, cards + nn, cmp3);
		for(int i = 0, j = 0;j < c * 3 && i < nn;i++, j++)
		{
			if (cards[i].used == 1)
				j--;
			else
				cards[i].used = 1;
		}
		vector<cardType> avCards;
		for(int i = 0;i < nn;i++)
			if (cards[i].used)
				avCards.push_back(cards[i]);

		for(int i = 0;i < n;i++)
			for(int j = 0;j < n;j++)
				graph[i][j] = 0;

		for(int i = 0;i < n;i++)
		{
			for(int j = 0;j < a;j++)
				graph[j][i] = avCards[i].a;
			for(int j = a;j < a + b;j++)
				graph[j][i] = avCards[i].b;
			for(int j = a + b;j < a + b + c;j++)
				graph[j][i] = avCards[i].c;
		}
		maxMatch();

		int sum = 0, total = 0;
		for(int i = 0;i < a + b + c;i++)
		{
			if (i < a)
				sum += avCards[matchX[i]].a;
			else if (i < a + b)
				sum += avCards[matchX[i]].b;
			else 
				sum += avCards[matchX[i]].c;
			total += (avCards[matchX[i]].a + avCards[matchX[i]].b + avCards[matchX[i]].c);
		}

		cout << sum << " " << total << endl;
	}

	return 0;
}
