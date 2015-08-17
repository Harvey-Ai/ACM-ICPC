#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
class GoodCompanyDivTwo {
	public:
	int countGood(vector <int> superior, vector <int> workType) {
		vector<int> departmentSet[105];
		for(int i = 1;i < superior.size();i++)
			departmentSet[superior[i]].push_back(i);
		
		int res = 0;
		queue<int> parent;
		parent.push(0);
		while(!parent.empty())
		{
			int boss = parent.front();
			parent.pop();
			
			int diverseT = true;	
			int workSet[101];
			memset(workSet, 0,  sizeof(workSet));
			workSet[workType[boss]] = true;
			for(int j = 0;j < departmentSet[boss].size();j++)
			{
				if (workSet[workType[departmentSet[boss][j]]])
					diverseT = false;
				else
					workSet[workType[departmentSet[boss][j]]] = true;
				parent.push(departmentSet[boss][j]);
			}

			if (diverseT)
				res++;
		}
		return res;
	}
};
