#include <string>
#include <vector>
#include <iostream>
using namespace std;
class ConundrumReloaded {
	public:
	int minimumLiars(string answers) {
		int num = answers.size();
		
		int pos = 0;
		for(int i = 0;i < num;i++)
			if(answers[i] == '?')
			{
				pos = i;
				break;
			}
		for(int i = 0;i < num;i++)
		{
			if (answers[pos] != '?')
				break;
			pos = (pos + 1) % num;
		}

		if (answers[pos] == '?')
			return 0;

		int res = 0;
		int begin = pos, end = pos;
		int walkNum = 0;
		while(walkNum < num)
		{
			end = begin;
			int isTrue = 1;
			int liarNum = 0;
			while(walkNum < num && answers[end] != '?')
			{
				liarNum += (isTrue == 0);

				if ((answers[end] == 'L' && isTrue) || (answers[end] == 'H' && !isTrue))
					isTrue = 0;
				else
					isTrue = 1;
				end = (end + 1) % num;
				walkNum++;
			}
			if (walkNum == num && answers[end] != '?')
			{
				if (isTrue != 1)
					return -1;
			}

			if (walkNum < num)
				liarNum += (isTrue == 0);
			int totalNum;
			if (begin >= end)
				totalNum = end + num - begin + (walkNum < num);
			else
				totalNum = end - begin + (walkNum < num);
			if ((totalNum - liarNum ) < liarNum)
				liarNum = (totalNum - liarNum);
			res += liarNum;

			begin = end;
			while(walkNum < num && answers[begin] == '?')
			{
				walkNum++;
				begin = (begin + 1) % num;
			}
		}
		return res;
	}
};
