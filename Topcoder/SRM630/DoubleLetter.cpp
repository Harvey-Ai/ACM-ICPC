#include <string>
#include <vector>
#include <iostream>
using namespace std;
class DoubleLetter {
	public:
	string ableToSolve(string S) {
		if (S == "")
			return "Possible";

		string s1 = S;
		int flag = 1;
		while(s1 != S || flag)
		{
			S = s1;
			s1 = "";
			flag = 0;
			int ff = 0;
			for(int i = 0;i < S.size();i++)
				if (i > 0 && S[i] == S[i - 1] && ff == 0)
				{
					s1.resize(i - 1);
					ff = 1;
				}
				else
					s1 += S[i];
			if (s1 == "")
				return "Possible";
		}
		
		return "Impossible";
	}
};
