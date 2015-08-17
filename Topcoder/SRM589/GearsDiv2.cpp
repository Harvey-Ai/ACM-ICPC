#include <string>
#include <vector>
#include <iostream>
using namespace std;
class GearsDiv2 {
	public:
	int getmin(string Directions) {
	/*	
		string dD = Directions + Directions;
		int num = Directions.size();
		int maxLeft = 1;
		for(int i = 0;i < num;i++)
		{
			int dp[200] = {0};
			for(int j = 0;j < num;j++)
			{
				dp[i + j] = 1;
				int max = 1;
				for(int k = i;k < i + j;k++)
					if (dD[k] != dD[i + j] && max < dp[k] + 1)
						max = dp[k] + 1;
				dp[i + j] = max;
			}
			
			for(int j = 1;j < num;j++)
			{
				int temp = dp[i + j];
				if (dD[i + j] == dD[i])
					temp--;
				if (maxLeft < temp)
					maxLeft = temp;
			}
		}
		return num - maxLeft;
		*/

		string d = Directions;
		int num = Directions.size();
		int res = num;

		int i;
		for(i = 1;i < num;i++)
			if (Direction[i] != Direction[i - 1])
				break;
		if (i == num)
			return (num + 1) / 2;

		for(int j = 0;j < i;j++)
			Direction += Direction[j];

		for(int j = i;j < num + i;j++)
		{
			int 
			while(Direction[j + 1] ==
		}

	}
};
