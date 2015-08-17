#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct cirEle
{
	int val;
};

class CircuitsConstruction {
	public:
	int maximizeResistance(string circuit, vector <int> conductors) {
		sort(conductors.begin(), conductors.end(), greater<int>());
		
		vector<int> val;	
		for(int i = circuit.size() - 1;i >= 0;i--)
		{
			if (circuit[i] == 'X')
				val.push_back(1);
			else if (circuit[i] == 'B')
			{
				int a = val.back();
				val.pop_back();
				int b = val.back();
				val.pop_back();
				val.push_back(a > b ? a : b);
			}
			else
			{
				int a = val.back();
				val.pop_back();
				int b = val.back();
				val.pop_back();
				val.push_back(a + b);
			}
		}
		int res = 0;
		for(int i = 0;i < val[0];i++)
			res += conductors[i];
		return res;
	}
};
