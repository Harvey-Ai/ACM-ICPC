#include <string>
#include <vector>
#include <iostream>
using namespace std;
class WolfDelaymaster {
	public:
	string check(string str) {
		
		int rn = 0;
		int tempn = 0;
		int status = 3;
		int res = 1;
		for	(int i = 0;i < str.size();i++)
		{
			if ((str[i] == 'w') && (status == 3 || status == 0))
			{
				if (status == 3 && tempn != rn)
				{
					res = 0;
					break;
				}
				if (status == 3)
					rn = 1;
				else
					rn++;
				status = 0;
				continue;
			}
			if (str[i] == 'o' && (status == 0 || status == 1))
			{
				if (status == 0)
					tempn = 1;
				else
					tempn++;
				status = 1;
				continue;
			}
			if (str[i] == 'l' && (status == 1 || status == 2))
			{
				if (status == 1 && tempn != rn)
				{
					res = 0;
					break;
				}
				if (status == 1)
					tempn = 1;
				else
					tempn++;
				status = 2;
				continue;
			}
			if (str[i] == 'f' && (status == 2 || status == 3))
			{
				if (status == 2 && tempn != rn)
				{
					res = 0;
					break;
				}
				if (status == 2)
					tempn = 1;
				else
					tempn++;
				status = 3;
				continue;
			}
			res = 0;
			break;
		}
		if (tempn != rn || status != 3)
			res = 0;
		return res == 1 ? "VALID" : "INVALID";
	}
};
