#include <string>
#include <vector>
#include <iostream>
using namespace std;
class HappyLetterDiv2 {
	public:
	char getHappyLetter(string letters) {
		int chNum[27];
	
		for(int i = 0;i < 27;i++)
			chNum[i] = 0;

		for(int i = 0;i < letters.size();i++)
			chNum[letters[i] - 'a']++;

		for(int i = 0;i < 26;i++)
		{
			if (chNum[i] > (letters.size() / 2))
				return (char)(i + 'a');
		}

		return '.';
	}
};
