#include <string>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
class LittleElephantAndString {
	public:
	int getNumber(string A, string B) {
		
		int countA[50], countB[50];
		memset(countA, 0, sizeof(countA));
		memset(countB, 0, sizeof(countB));
		for(int i = 0;i < A.size();i++)
		{
			countA[A[i] - 'A'] ++;
			countB[B[i] - 'A'] ++;
		}
		for(int i = 0;i < 50;i++)
			if (countA[i] != countB[i])
				return -1;
		

		int posB = B.size() - 1;
		for(int i = A.size() - 1;i >= 0;i--)
		{
			if (A[i] == B[posB])
				posB--;
		}
		return (posB + 1);
	}
};
