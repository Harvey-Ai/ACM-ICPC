#include <vector>
#include <string>
using namespace std;

class RabbitVoting
{
public:
	string getWinner(vector <string> names, vector <string> votes)
	{
		int getV[60];
		int i, j;
		int winner, max;

		memset(getV, 0, sizeof(getV));
		for(i = 0;i < votes.size();i++)
		{
			for(j = 0;j < names.size();j++)
				if (votes[i] == names[j])
					break;
			if (j < names.size() && votes[i] != names[i])
				getV[j]++;
		}

		winner = -1;max = 0;
		for(i = 0;i < votes.size();i++)
		{
			if (getV[i] > max)
			{
				max = getV[i];
				winner = i;
			}
			else if (getV[i] == max)
				winner = -1;
		}
		if (winner != -1)
			return names[winner];
		else
			return "";
	}
};
