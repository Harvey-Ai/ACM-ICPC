#include <string>
#include <vector>
#include <iostream>
using namespace std;
class LittleElephantAndRGB {
	public:
	long long getNumber(vector <string> list, int minGreen) {
		string str = "";
		for(int i = 0;i < list.size();i++)
			str += list[i];
		
		long long res = 0;
		int end = str.size();
		int indexBeginG[2505] = {0};
		int indexCon = 0;
		int indexLastCon = -1;
		int beginG = 0;
		for(int i = end - 1;i >= 0;i--)
		{
			if (str[i] == 'G')
			{
				beginG++;
				if (beginG >= minGreen)
					indexLastCon = i + minGreen - 1;
			}
			else
				beginG = 0;

			if (indexLastCon != -1)
				indexCon += end - indexLastCon;
			if (beginG)
			{
				if (beginG >= minGreen)
					for(int k = 1;k < minGreen;k++)
						indexBeginG[k] += minGreen - k;
				else
					for(int k = 1;k <= beginG;k++)
					{
						if (indexLastCon != -1)
							indexBeginG[k] += (indexLastCon) - (i + k) + 1;
						else
							indexBeginG[k] += end - (i + k) + 1;
					}
			}

			int rightF = 1;
			int seqG = 0;
			int haveMin = 0;
			int rightGNum = 0;
			for(int j = i - 1; j >= 0;j--)
			{
				if (str[j] == 'G')
				{
					if (rightF)
						rightGNum++;
					seqG++;
				}
				else
				{
					rightF = 0;
					seqG = 0;
				}
				if (seqG >= minGreen)
					haveMin = 1;
				if (haveMin)
					res += ((end - i) * (end - i + 1)) / 2;
				else
				{
					if (rightGNum > 0)
						res += indexBeginG[minGreen - rightGNum];
					res += indexCon;
				}
			}
		}
		return res;
	}
};
