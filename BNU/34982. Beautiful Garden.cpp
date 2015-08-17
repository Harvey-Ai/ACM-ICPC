/*
There are n trees planted in lxhgww's garden. You can assume that these trees are planted along the X-axis, and the coordinate of ith tree is xi.
But in recent days, lxhgww wants to move some of the trees to make them look more beautiful. lxhgww will recognize the trees as beautiful if and only if the distance between any adjacent trees is the same.
Now, lxhgww wants to know what is the minimum number of trees he need to move.
Just to be clear, after moving, there should still be n trees in the X-axis.
 
Input
The first line of the input contains a single integer T, which is the number of test cases.
For each case,
The first line contains an integers number n (1 ≤ n ≤ 40), representing the number of trees lxhgww planted;
The second line contains n integers numbers, the ith number represents xi. (-1000000000 ≤ xi ≤ 1000000000)
Output
For each case, first output the case number as "Case #x: ", and x is the case number. Then output a single number, representing the minimum number of trees lxhgww needs to move.

Sample Input
1
4
1 3 6 7
Sample Output
Case #1: 1
*/

#include <iostream>
#include <queue>
#include <cassert>
#include <set>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct qEleType
{
	int status[9];
	int existCost;
	int totalCost;

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

	bool operator<(const qEleType &a) const
	{
		for(int i = 0;i < 9;i++)
			if (status[i] != a.status[i])
				return status[i] < a.status[i];
		return false;
	}

	qEleType& operator=(const qEleType &b)
	{
		for(int i = 0;i < 9;i++)
			status[i] = b.status[i];
		existCost = b.existCost;
		totalCost = b.totalCost;

		return *this;
	}
};

int hCost, vCost;
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

int cal(int status1[], int status2[])
{
	int totalCost = 0;
	for(int i = 0;i < 9;i++)
	{
		int pos = -1;
		for(int j = 0;j < 9;j++)
			if (status1[i] == status2[j])
			{
				pos = j;
				break;
			}
		int minCost = -1;
		int flag = 0;
		for(int j = i;j != i || !flag;j = (j + 3) > 8 ? (j - 6) : (j + 3))
		{
			flag = 1;

			int hCostSum = abs(pos - j) * hCost;
			if (hCostSum > (9 - abs(pos - j)) * hCost)
				hCostSum = (9 - abs(pos - j)) * hCost;

			int vCostSum = abs(i - j) / 3 * vCost;
			if (vCostSum > ((3 - (abs(i - j) / 3)) * vCost)) 
				vCostSum = ((3 - (abs(i - j) / 3)) * vCost);

			if (minCost == -1 || minCost > hCostSum + vCostSum)
				minCost = hCostSum + vCostSum;
		}
		totalCost += minCost;
	}
	return totalCost;
}

int main()
{
    fac[0] = fac[1] = 1;
    for(int i = 2;i < 10;i++)
        fac[i] = fac[i - 1] * i;
    
	while(cin >> hCost >> vCost, hCost || vCost)
	{
        for(int i = 0;i < 1000000;i++)
            closeTable[i] = -1;
        
		int inStatus[9], endStatus[9];
		for(int i = 0;i < 3;i++)
			for(int j = 0;j < 3;j++)
            {
                cin >> inStatus[i * 3 + j];
                if (inStatus[i * 3 + j] == 0)
                    inStatus[i * 3 + j] = 9;
            }
		for(int i = 0;i < 3;i++)
			for(int j = 0;j < 3;j++)
            {
				cin >> endStatus[i * 3 + j];
                if (endStatus[i * 3 + j] == 0)
                    endStatus[i * 3 + j] = 9;
            }
        int endStausNum = kanto(endStatus);
        
		priority_queue<qEleType, vector<qEleType>, qEleType> openTable;
		openTable.push(qEleType(inStatus, 0, cal(inStatus, endStatus)));

		int res = -1;
		while(!openTable.empty())
		{
			qEleType minStatus = openTable.top();
			openTable.pop();

            int currentNum = kanto(minStatus.status);
			if (currentNum == endStausNum)
			{
                res = minStatus.totalCost;
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

			int pos1 = zeroPos + 1, pos2 = zeroPos - 1, pos3 = zeroPos + 3, pos4 = zeroPos - 3;
			if (pos1 > 8) pos1 = 0;
			if (pos2 < 0) pos2 = 8;
			if (pos3 > 8) pos3 -= 9;
			if (pos4 < 0) pos4 += 9;

			swap(newStatus[pos1], newStatus[zeroPos]);
            qEleType e1(newStatus, minStatus.existCost + hCost, cal(newStatus, endStatus));
            int e1Num = kanto(newStatus);
            if (closeTable[e1Num] == -1 || closeTable[e1Num] > e1.existCost)
                openTable.push(e1);
			swap(newStatus[pos1], newStatus[zeroPos]);

			swap(newStatus[pos2], newStatus[zeroPos]);
			qEleType e2(newStatus, minStatus.existCost + hCost, cal(newStatus, endStatus));
			int e2Num = kanto(newStatus);
            if (closeTable[e2Num] == -1 || closeTable[e2Num] > e2.existCost)
                openTable.push(e2);
			swap(newStatus[pos2], newStatus[zeroPos]);

			swap(newStatus[pos3], newStatus[zeroPos]);
			qEleType e3(newStatus, minStatus.existCost + vCost, cal(newStatus, endStatus));
			int e3Num = kanto(newStatus);
            if (closeTable[e3Num] == -1 || closeTable[e3Num] > e3.existCost)
                openTable.push(e3);
			swap(newStatus[pos3], newStatus[zeroPos]);

			swap(newStatus[pos4], newStatus[zeroPos]);
			qEleType e4(newStatus, minStatus.existCost + vCost, cal(newStatus, endStatus));
			int e4Num = kanto(newStatus);
            if (closeTable[e4Num] == -1 || closeTable[e4Num] > e4.existCost)
                openTable.push(e4);
			swap(newStatus[pos4], newStatus[zeroPos]);
		}

		cout << res << endl;
	}
	return 0;
}
