#include <string>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;
class ORSolitaireDiv2 {
	public:
	int getMinimum(vector <int> numbers, int goal) {
		int numBit[50][50];
		int goalBit[50];
		int pos = 0;
		memset(goalBit, 0, sizeof(goalBit));
		memset(numBit, 0, sizeof(numBit));
		while(goal)
		{
			goalBit[pos] = goal & 0x01;
			goal /= 2;
			pos++;
		}

		for(int i = 0;i < numbers.size();i++)
		{
			int temp = numbers[i];
			int pos = 0;
			while(temp)
			{
				numBit[i][pos] = temp & 0x01;
				temp /= 2;
				pos++;
			}
		}

		int validateNum[50];
		memset(validateNum, 0, sizeof(validateNum));
		for(int i = 0;i < numbers.size();i++)
		{
			int j;
			for(j = 0;j < 50;j++)
				if (numBit[i][j] == 1 && goalBit[j] == 0)
					break;
			if (j < 50)
				continue;
			for(j = 0;j < 50;j++)
				if (numBit[i][j])
					validateNum[j]++;
		}

		int res = -1;
		for(int i = 0;i < 50;i++)
			if (goalBit[i] == 1 && (res > validateNum[i] || res == -1))
				res = validateNum[i];
		return res;
	}
};
