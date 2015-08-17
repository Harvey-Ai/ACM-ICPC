/*
Description

Rain has pummeled the cows' field, a rectangular grid of R rows and C columns (1 <= R <= 50, 1 <= C <= 50). While good for the grass, the rain makes some patches of bare earth quite muddy. The cows, being meticulous grazers, don't want to get their hooves dirty while they eat. 

To prevent those muddy hooves, Farmer John will place a number of wooden boards over the muddy parts of the cows' field. Each of the boards is 1 unit wide, and can be any length long. Each board must be aligned parallel to one of the sides of the field. 

Farmer John wishes to minimize the number of boards needed to cover the muddy spots, some of which might require more than one board to cover. The boards may not cover any grass and deprive the cows of grazing area but they can overlap each other. 

Compute the minimum number of boards FJ requires to cover all the mud in the field.
Input

* Line 1: Two space-separated integers: R and C 

* Lines 2..R+1: Each line contains a string of C characters, with '*' representing a muddy patch, and '.' representing a grassy patch. No spaces are present.
Output

* Line 1: A single integer representing the number of boards FJ needs.
Sample Input

4 4
*.*.
.***
***.
..*.
Sample Output

4
Hint

OUTPUT DETAILS: 

Boards 1, 2, 3 and 4 are placed as follows: 
1.2. 
.333 
444. 
..2. 
Board 2 overlaps boards 3 and 4.
*/


#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int graph[2500][2500];
int visited[2500];
int matchX[2500], matchY[2500];
int nodeNum;

bool find(int x)
{
	for(int i = 0;i < nodeNum;i++)
	{
		if (graph[x][i] && !visited[i])
		{
			visited[i] = 1;
			if (matchY[i] == -1 || find(matchY[i]))
			{
				matchY[i] = x;
				matchX[x] = i;
				return true;
			}
		}
	}
	return false;
}

int maxMatch()
{
	int res = 0;
	for(int i = 0;i < nodeNum;i++)
		matchX[i] = matchY[i] = -1;

	for(int i = 0;i < nodeNum;i++)
	{
		memset(visited, 0, sizeof(visited));
		if (find(i))
			res++;
	}
	return res;
}

int main()
{
	int r, c;
	cin >> r >> c;

	string grassMap[55];
	for(int i = 0;i < r;i++)
		cin >> grassMap[i];

	memset(graph, 0, sizeof(graph));
	int vIndex[55];
    for(int i = 0;i < c;i++)
        vIndex[i] = i;
    int rNum = 0, cNum = c;
    for(int i = 0;i < r;i++)
    {
        int flag = 0;
        for(int j = 0;j < c;j++)
        {
			if (grassMap[i][j] == '*')
            {
                if (!flag)
                {
                    flag = 1;
                    rNum++;
                }
                graph[rNum - 1][vIndex[j]] = 1;
            }
            else
            {
                flag = 0;
                vIndex[j] = cNum++;
            }
        }
    }
				

	nodeNum = max(rNum, cNum);
	cout << maxMatch() << endl;
	return 0;
}
