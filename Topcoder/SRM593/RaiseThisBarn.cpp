#include <string>
#include <vector>
#include <iostream>
using namespace std;
class RaiseThisBarn {
	public:
	int calc(string str) {
		
		int sum = 0;
		for(int i = 0;i < str.size();i++)
			if (str[i] == 'c')
				sum++;

		if (sum % 2)
			return 0;
		int res = 0;
		int temp = 0;
		
		for(int i = 0;i < str.size() - 1;i++)
		{
			if (str[i] == 'c')
				temp++;	
			if (temp == sum / 2)
				res++;
		}
		return res;	
	}
};
