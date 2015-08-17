/*
Description

Polygon is a game for one player that starts on a polygon with N vertices, like the one in Figure 1, where N=4. Each vertex is labelled with an integer and each edge is labelled with either the symbol + (addition) or the symbol * (product). The edges are numbered from 1 to N. 


On the first move, one of the edges is removed. Subsequent moves involve the following steps: 
�pick an edge E and the two vertices V1 and V2 that are linked by E; and 
�replace them by a new vertex, labelled with the result of performing the operation indicated in E on the labels of V1 and V2. 
The game ends when there are no more edges, and its score is the label of the single vertex remaining. 

Consider the polygon of Figure 1. The player started by removing edge 3. After that, the player picked edge 1, then edge 4, and, finally, edge 2. The score is 0. 


Write a program that, given a polygon, computes the highest possible score and lists all the edges that, if removed on the first move, can lead to a game with that score. 
Input

Your program is to read from standard input. The input describes a polygon with N vertices. It contains two lines. On the first line is the number N. The second line contains the labels of edges 1, ..., N, interleaved with the vertices' labels (first that of the vertex between edges 1 and 2, then that of the vertex between edges 2 and 3, and so on, until that of the vertex between edges N and 1), all separated by one space. An edge label is either the letter t (representing +) or the letter x (representing *). 

3 <= N <= 50 
For any sequence of moves, vertex labels are in the range [-32768,32767]. 
Output

Your program is to write to standard output. On the first line your program must write the highest score one can get for the input polygon. On the second line it must write the list of all edges that, if removed on the first move, can lead to a game with that score. Edges must be written in increasing order, separated by one space.
Sample Input

4
t -7 t 4 x 2 x 5
Sample Output

33
1 2

*/


#include <iostream>
#include <cassert>
using namespace std;

char newOp[51];
int newOpNum[51];

int dp[101][101];
int dp2[101][101];

void cal(int head, int tail)
{
	if (dp[head][tail] != -100000)
		return;
	if (head == tail)
    {
        dp[head][tail] = newOpNum[head];
		dp2[head][tail] = newOpNum[head];
        return;
    }
    
	int maxV = -100000;
    int minV = 100000;
	for(int i = head;i < tail;i++)
	{
		int temp1, temp2;
        cal(head, i);
        cal(i + 1, tail);
        
        if (newOp[i] == 't')
        {
            temp1 = dp[head][i] + dp[i + 1][tail];
            temp2 = dp2[head][i] + dp2[i + 1][tail];
        }
		else if (newOp[i] == 'x')
        {
            temp1 = dp[head][i] * dp[i + 1][tail];
            if (temp1 < dp2[head][i] * dp2[i + 1][tail])
                temp1 = dp[head][i] * dp[i + 1][tail];
            if (temp1 < dp[head][i] * dp2[i + 1][tail])
                temp1 = dp[head][i] * dp2[i + 1][tail];
            if (temp1 < dp2[head][i] * dp[i + 1][tail])
                temp1 = dp2[head][i] * dp[i + 1][tail];
            
            temp2 = dp[head][i] * dp[i + 1][tail];
            if (temp2 > dp2[head][i] * dp2[i + 1][tail])
                temp2 = dp2[head][i] * dp2[i + 1][tail];
            if (temp2 > dp[head][i] * dp2[i + 1][tail])
                temp2 = dp[head][i] * dp2[i + 1][tail];
            if (temp2 > dp2[head][i] * dp[i + 1][tail])
                temp2 = dp2[head][i] * dp[i + 1][tail];
        }
		if (temp1 > maxV)
			maxV = temp1;
        if (temp2 < minV)
            minV = temp2;
	}
	dp[head][tail] = maxV;
    dp2[head][tail] = minV;
}

int main()
{
	int n;
	char op[51];
	int opNum[51];

	while(cin >> n)
    {
	for(int i = 0;i < n;i++)
		cin >> op[i] >> opNum[i];
	
	int res[100];
	for(int i = 0;i < n;i++)
	{
		int head = i, tail = i;
		int k = 0;
		newOp[k] = op[(head + 1) % n];
		newOpNum[k++] = opNum[head];
		for(int j = (head + 1) % n;j != tail;j = (j + 1) % n)
		{
			if (((j + 1) % n) != tail)
				newOp[k] = op[(j + 1) % n];
			newOpNum[k++] = opNum[j];
		}

		for(int l1 = 0;l1 < n;l1++)
			for(int l2 = 0;l2 < n;l2++)
				dp[l1][l2] = -100000;
		cal(0, n - 1);
        res[i] = dp[0][n - 1];
	}

	int max = -100000;
	for(int i = 0;i < n;i++)
		if (res[i] > max)
			max = res[i];
	cout << max << endl;

	for(int i = 0;i < n;i++)
		if (res[i] == max)
			cout << i + 1 << " ";
	cout << endl;
    }
	return 0;
}
