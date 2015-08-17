/*
Description

Bobobo and Bottle are good friends, and the birthday of Bottle is coming. So Bobobo is considering preparing Bottle an unexpected gift for his birthday. As a common sense that when a person at his or her birthday party, he or she will open the gift with the presence of the person who gives the gift and then expresses the appreciation. Bobobo knows that the characteristic of Bottle is rush when he receives something important, so he wants to play a joke on him in this way…

Bobobo comes into a gift shop, and there are a lot of different kinds of gift boxes. Bobobo intends to choose various boxes with different size and choose one of the gift boxes to contain the precious gift and place this box into another bigger box and place this bigger box into another bigger one… So Bottle will not see the gift until he opens the innermost box. Imagine the process of his opening the boxes, how rush Bottle will be ^_^ !

The gift boxes are n-dimensional. An n-dimensional box with dimensions ( X1, X2, …, Xn ) can be put into another box with dimensions ( Y1, Y2, …, Yn ) if there exists a permutation π on { 1, 2, …, n } such that Xπ1 < Y1, Xπ2 < Y2, …, Xπn < Yn. The gift is also n-dimensional and it can be put into a box if it satisfies the criterion above. And Bobobo must try his best to choose as many as boxes to contain the gift.

Input

The input file contains multiple test cases. The first line of each test case contains two numbers. The first one is a positive integer number N (1 ≤ N ≤ 500), the number of boxes in the gift shop, and the second one is a positive number d (3 ≤ d ≤ 1 000), the dimension of all the boxes. The next one line contains d positive integers ( G1, G2, …, Gd ) representing the dimensions of the gift. And the subsequent N lines each contain d positive integers ( X1, X2, …, Xd ) representing the dimensions of each box. You may assume that all the numbers you encounter are positive integers and less than 231. The input data is terminated by EOF.

Output

The output of each test case will contain only one line. Output the maximum number of the boxes that Bobobo can choose. If Bobobo can not find any box which can contain the gift, output “Please look for another gift shop!”

Sample Input

5 7
4 6 8 2 7 5 3
2 8 13 6 10 9 4
80 70 12 3 6 8 2
8 7 4 6 9 10 12
100 200 300 400 500 600 700
800 800 800 800 800 800 800
Sample Output

3
*/


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int boxes[505][1005];
int graph[505][505];
int n;
int dp[505];

int dfs(int p)
{
    if (dp[p] != -1)
        return dp[p];
    
    int maxDp = 0;
	for(int i = 0;i < n;i++)
		if (graph[p][i])
            maxDp = max(maxDp,  dfs(i));
    
    dp[p] = maxDp + 1;
    return dp[p];
}

int main()
{
	int d;
	while(scanf("%d %d", &n, &d) != EOF)
    {
        n++;
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < d;j++)
                scanf("%d", &boxes[i][j]);
            sort(boxes[i], boxes[i] + d);
        }

        memset(graph, 0, sizeof(graph));
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++)
            {
                int contain = 1;
                for(int k = 0;k < d;k++)
                    if (boxes[i][k] >= boxes[j][k])
                    {
                        contain = 0;
                        break;
                    }
                if (contain)
                    graph[i][j] = 1;
            }

        memset(dp, -1, sizeof(dp));
        dfs(0);
        if (dp[0] == 1)
            printf("Please look for another gift shop!\n");
        else
            printf("%d\n", dp[0] - 1);
    }
	return 0;
}
