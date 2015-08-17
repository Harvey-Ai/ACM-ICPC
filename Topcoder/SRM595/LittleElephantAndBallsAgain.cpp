#include <string>
#include <vector>
#include <iostream>
using namespace std;
class LittleElephantAndBallsAgain {
	public:
	int getNumber(string S) {
		int sameN = 1;
		int temp = 1;
		for(int i = 1;i < S.size();i++)
			if (S[i] == S[i - 1])
				temp++;
			else
			{
				sameN = temp > sameN ? temp : sameN;
				temp = 1;
			}
		sameN = temp > sameN ? temp : sameN;
		return S.size() - sameN;
	}
};
