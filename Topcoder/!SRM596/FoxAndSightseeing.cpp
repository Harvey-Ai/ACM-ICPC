#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

class FoxAndSightseeing {
	public:
	int getMin(vector <int> position) {
	
		int sum = 0;
		for(int	i = 0;i < position.size() - 1;i++)
			sum += abs(position[i + 1] - position[i]);
		
		for(int i = 1;i < position.size() - 1;i++)
		{
			int temp = 0;
			for(int j = 1;j < position.size();j++)
			{
				if (j == i)
					continue;
				if (j == i + 1)
					temp += abs(position[j] - position[j - 2]);
				else 
					temp += abs(position[j] - position[j - 1]);
			}
			if (temp < sum)
				sum = temp;
		}
		return sum;
	}
};
