#include <string>
#include <vector>
using namespace std;
class TeamsSelection {
	public:
	string simulate(vector <int> preference1, vector <int> preference2) {
		
		int chosed[100] = {0};
		int peopleNum = preference1.size();
		
		int i1 = 0, i2 = 0;
		for(int i = 0;i < peopleNum;i++)
		{
			if (i % 2 == 0)
			{
				while(chosed[preference1[i1] - 1]) i1++;
				chosed[preference1[i1] - 1] = 1;
			}
			else
			{
				while(chosed[preference2[i2] - 1]) i2++;
				chosed[preference2[i2] - 1] = 2;
			}
		}

		char res[100];
		for(int i = 0;i < peopleNum;i++)
			res[i] = chosed[i] + '0';
		res[peopleNum] = '\0';
		return string(res);
	}
};
