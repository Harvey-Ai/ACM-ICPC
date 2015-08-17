#include <string>
#include <vector>
#include <iostream>
using namespace std;
class LittleElephantAndDouble {
	public:
	string getAnswer(vector <int> A) {
		int max = A[0];
		for(int i = 0;i < A.size();i++)
			if (A[i] > max)
				max = A[i];

		for(int i = 0;i < A.size();i++)
		{
			while(A[i] < max)
				A[i] *= 2;
			if (A[i] > max)
				return "NO";
		}
		return "YES";
	}
};
