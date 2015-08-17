/*
Problem Description
Hululu and Cululu are two pacific ocean countries made up of many islands. These two country has so many years of friendship so they decide to build bridges to connect their islands. Now they want to build the first bridge to connect an island of Hululu and an island of Culuu .
Their world can be considered as a matrix made up of three letters 'H','C' and 'O'.Every 'H' stands for an island of Hululu, every 'C' stands for an island of Cululu, and 'O' stands for the ocean. Here is a example:




The coordinate of the up-left corner is (0,0), and the down-right corner is (4, 3). The x-direction is horizontal, and the y-direction is vertical.
There may be too many options of selecting two islands. To simplify the problem , they come up with some rules below:
1. The distance between the two islands must be as short as possible. If the two islands' coordinates are (x1,y1) and (x2,y2), the distance is |x1-x2|+|y1-y2|.
2. If there are more than one pair of islands satisfied the rule 1, choose the pair in which the Hululu island has the smallest x coordinate. If there are still more than one options, choose the Hululu island which has the smallest y coordinate.
3.After the Hululu island is decided, if there are multiple options for the Cululu island, also make the choice by rule 2. 
Please help their people to build the bridge.
 

Input
There are multiple test cases.
In each test case, the first line contains two integers M and N, meaning that the matrix is M×N ( 2<=M,N <= 40).
Next M lines stand for the matrix. Each line has N letters.
The input ends with M = 0 and N = 0.
It's guaranteed that there is a solution.
 

Output
For each test case, choose two islands, then print their coordinates in a line in following format:
x1 y1 x2 y2
x1,y1 is the coordinate of Hululu island, x2 ,y2 is the coordinate of Cululu island.
 

Sample Input
4 4
CHCH
HCHC
CCCO
COHO
5 4
OHCH
HCHC
CCCO
COHO
HCHC
0 0
 

Sample Output
0 1 0 0
0 1 0 2

*/


#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

char graph[44][44];
int main()
{
	int m, n;
	while(cin >> n >> m, m || n)
	{
		for(int i = 0;i < n;i++)
			scanf("%s", graph[i]);

		int huX, huY, cuX, cuY;
		int dist = -1;
		for(int i = 0;i < n;i++)
			for(int j = 0;j < m;j++)
			{
				if (graph[i][j] != 'H')
					continue;
				for(int k = 0;k < n;k++)
					for(int l = 0;l < m;l++)
					{
						if (graph[k][l] != 'C')
							continue;

						if (abs(k - i) + abs(j - l) < dist || dist == -1)
						{
							huX = i, huY = j;
							cuX = k, cuY = l;
							dist = abs(k - i) + abs(j - l);
						}
					}
			}
		printf("%d %d %d %d\n", huX, huY, cuX, cuY);
	}
	return 0;
}
