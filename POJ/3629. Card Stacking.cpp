/*
Description

Bessie is playing a card game with her N-1 (2 ≤ N ≤ 100) cow friends using a deck with K (N ≤ K ≤ 100,000; K is a multiple of N) cards. The deck contains M = K/N "good" cards and K-M "bad" cards. Bessie is the dealer and, naturally, wants to deal herself all of the "good" cards. She loves winning.

Her friends suspect that she will cheat, though, so they devise a dealing system in an attempt to prevent Bessie from cheating. They tell her to deal as follows:

1. Start by dealing the card on the top of the deck to the cow to her right

2. Every time she deals a card, she must place the next P (1 ≤ P ≤ 10) cards on the bottom of the deck; and

3. Continue dealing in this manner to each player sequentially in a counterclockwise manner

Bessie, desperate to win, asks you to help her figure out where she should put the "good" cards so that she gets all of them. Notationally, the top card is card #1, next card is #2, and so on.

Input

* Line 1: Three space-separated integers: N, K, and P

Output

* Lines 1..M: Positions from top in ascending order in which Bessie should place "good" cards, such that when dealt, Bessie will obtain all good cards.

Sample Input

3 9 2
Sample Output

3
7
8

*/


#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int arr[100000],rel[100000];
int main()
{
	memset(arr,0,sizeof(arr));
	int i,j,n,k,l,p,t,pos;
	scanf("%d%d%d",&n,&k,&p);
	t=k/n;
	pos=0;
	arr[0]=1;
	for(i=1;i<n;i++)
	{
		for(l=0;l<=p;)
		{
			pos++;
			if(pos>=k)
				pos-=k;
			if(!arr[pos])
				l++;
		}
		arr[pos]=1;
	}
	rel[0]=pos+1;
	for(i=1;i<t;i++)
	{
		for(j=0;j<n;j++)
		{
			for(l=0;l<=p;)
			{
				pos++;
				if(pos>=k)
					pos-=k;
				if(!arr[pos])
					l++;
			}
			arr[pos]=1;
		}
		rel[i]=pos+1;
	}
	sort(&rel[0],&rel[t]);
	for(i=0;i<t;i++)
		printf("%d\n",rel[i]);
	return 0;
}
