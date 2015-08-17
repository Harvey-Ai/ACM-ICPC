/*
Description

The 15-puzzle has been around for over 100 years; even if you don't know it by that name, you've seen it. It is constructed with 15 sliding tiles, each with a number from 1 to 15 on it, and all packed into a 4 by 4 frame with one tile missing. Let's call the missing tile 'x'; the object of the puzzle is to arrange the tiles so that they are ordered as: 
 1  2  3  4 

 5  6  7  8 

 9 10 11 12 

13 14 15  x 

where the only legal operation is to exchange 'x' with one of the tiles with which it shares an edge. As an example, the following sequence of moves solves a slightly scrambled puzzle: 
 1  2  3  4    1  2  3  4    1  2  3  4    1  2  3  4 

 5  6  7  8    5  6  7  8    5  6  7  8    5  6  7  8 

 9  x 10 12    9 10  x 12    9 10 11 12    9 10 11 12 

13 14 11 15   13 14 11 15   13 14  x 15   13 14 15  x 

           r->           d->           r-> 

The letters in the previous row indicate which neighbor of the 'x' tile is swapped with the 'x' tile at each step; legal values are 'r','l','u' and 'd', for right, left, up, and down, respectively. 

Not all puzzles can be solved; in 1870, a man named Sam Loyd was famous for distributing an unsolvable version of the puzzle, and 
frustrating many people. In fact, all you have to do to make a regular puzzle into an unsolvable one is to swap two tiles (not counting the missing 'x' tile, of course). 

In this problem, you will write a program for solving the less well-known 8-puzzle, composed of tiles on a three by three 
arrangement. 
Input

You will receive a description of a configuration of the 8 puzzle. The description is just a list of the tiles in their initial positions, with the rows listed from top to bottom, and the tiles listed from left to right within a row, where the tiles are represented by numbers 1 to 8, plus 'x'. For example, this puzzle 
 1  2  3 

 x  4  6 

 7  5  8 

is described by this list: 

 1 2 3 x 4 6 7 5 8 
Output

You will print to standard output either the word ``unsolvable'', if the puzzle has no solution, or a string consisting entirely of the letters 'r', 'l', 'u' and 'd' that describes a series of moves that produce a solution. The string should include no spaces and start at the beginning of the line.
Sample Input

 2  3  4  1  5  x  7  6  8 
Sample Output

ullddrurdllurdruldr

*/


#include <iostream>
#include <queue>
#include <cassert>
#include <set>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct qEleType
{
	int status[9];
	int existCost;
	int totalCost;
    string op;

	qEleType(int s[], int e, int t)
	{
		for(int i = 0;i < 9;i++)
			status[i] = s[i];
		existCost = e;
		totalCost = t + e;
	}
	qEleType()
	{
	}

	bool operator()(const qEleType &a, const qEleType &b)
	{
		if (a.totalCost > b.totalCost)
			return 1;
		else
			return 0;
	}
};

int closeTable[1000000];
int fac[10];

int kanto(int s[]){//康托展开  
	int res = 0;

	int has[9];
	for(int i = 0;i < 9;i++)
		has[i] = 1;

	for(int i = 0; i < 9; i++){  
		int x = s[i], y = 0;  
		for(int j = 1; j < x; j++){  
			if(has[j]) y++;  
		}  
		res += y * fac[8 - i]; 
		has[x] = 0; 
	}  
	return res;  
}

int cal(int status[])
{
	int totalCost = 0;
	
    for(int i = 0;i < 9;i++)
    {
		int h = (status[i] - 1) / 3;
		int v = (status[i] - 1) % 3;
		totalCost += abs(i / 3 - h) + abs(i % 3 - v);
	}

	return totalCost;
}

int main()
{
	fac[0] = fac[1] = 1;
	for(int i = 2;i < 10;i++)
		fac[i] = fac[i - 1] * i;
	int left[10], right[10], bottom[10], top[10];

	for(int i = 0;i < 10;i++)
	{
		if (i % 3 != 0)
			left[i] =  i - 1;
		else
			left[i] = -1;
		if (i % 3 != 2)
			right[i] = (i + 1);
		else
			right[i] = -1;
		if (i / 3 != 0)
			top[i] = i - 3;
		else
			top[i] = -1;
		if (i / 3 != 2)
			bottom[i] = i + 3;
		else
			bottom[i] = -1;
	}
	memset(closeTable, -1, sizeof(closeTable));

	int endStatus[9];
	for(int i = 0;i < 9;i++)
		endStatus[i] = i + 1;
	int endStausNum = kanto(endStatus);
	
	int inStatus[9];
	for(int i = 0;i < 9;i++)
	{
		char a;
        cin >> a;
		if (a == 'x')
			inStatus[i] = 9;
		else
			inStatus[i] = a - '0';
	}

	priority_queue<qEleType, vector<qEleType>, qEleType> openTable;
	openTable.push(qEleType(inStatus, 0, cal(inStatus)));
	string res;

	while(!openTable.empty())
	{
		qEleType minStatus = openTable.top();
		openTable.pop();

		int currentNum = kanto(minStatus.status);
		if (currentNum == endStausNum)
		{
			res = minStatus.op;
			break;
		}
		closeTable[currentNum] = minStatus.existCost;

		int newStatus[9];
		int zeroPos = -1;
		for(int i = 0;i < 9;i++)
		{
			newStatus[i] = minStatus.status[i];
			if (newStatus[i] == 9)
				zeroPos = i;
		}
		int pos1 = left[zeroPos], pos2 = right[zeroPos], pos3 = bottom[zeroPos], pos4 = top[zeroPos];

        if (pos1 != -1)
		{
			swap(newStatus[pos1], newStatus[zeroPos]);
			int e1Num = kanto(newStatus);
			if (closeTable[e1Num] == -1 || closeTable[e1Num] > minStatus.existCost + 1)
			{
				qEleType leftStatus(newStatus, minStatus.existCost + 1, cal(newStatus));
				leftStatus.op = minStatus.op + 'l';
				openTable.push(leftStatus);
			}
			swap(newStatus[pos1], newStatus[zeroPos]);
		}

		if (pos2 != -1)
		{
			swap(newStatus[pos2], newStatus[zeroPos]);
			int e2Num = kanto(newStatus);
			if (closeTable[e2Num] == -1 || closeTable[e2Num] > minStatus.existCost + 1)
			{
				qEleType rightStatus(newStatus, minStatus.existCost + 1, cal(newStatus));
				rightStatus.op = minStatus.op + 'r';
				openTable.push(rightStatus);
			}
			swap(newStatus[pos2], newStatus[zeroPos]);
		}

		if (pos3 != -1)
		{
			swap(newStatus[pos3], newStatus[zeroPos]);
			int e3Num = kanto(newStatus);
			if (closeTable[e3Num] == -1 || closeTable[e3Num] > minStatus.existCost + 1)
			{
				qEleType bottomStatus(newStatus, minStatus.existCost + 1, cal(newStatus));
				bottomStatus.op = minStatus.op + 'd';
				openTable.push(bottomStatus);
			}
			swap(newStatus[pos3], newStatus[zeroPos]);
		}

		if (pos4 != -1)
		{
			swap(newStatus[pos4], newStatus[zeroPos]);
			int e4Num = kanto(newStatus);
			if (closeTable[e4Num] == -1 || closeTable[e4Num] > minStatus.existCost + 1)
			{
				qEleType topStatus(newStatus, minStatus.existCost + 1, cal(newStatus));
				topStatus.op = minStatus.op + 'u';
				openTable.push(topStatus);
			}
			swap(newStatus[pos4], newStatus[zeroPos]);
		}
	}

	cout << res << endl;
	return 0;
}
