#include <string>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
	if (a < b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}

class LCMSet {
	public:
	string equal(vector <int> A, vector <int> B) {
		vector<int> newA;
		vector<int> newB;

		sort(A.begin(), A.end());
		sort(B.begin(), B.end());

		newA.push_back(A[0]);
		for(int i = 1;i < A.size();i++)
		{
			vector<int> temp;
			temp.clear();
			for(int j = i - 1;j >= 0;j--)
			{
				if(A[i] % A[j] == 0)
					temp.push_back(A[j]);
			}
			if (temp.size() <= 0)
			{
				newA.push_back(A[i]);
				continue;
			}

			long long multi = temp[0];
			for(int j = 1;j < temp.size();j++)
			{
				int common = gcd(multi, temp[j]);
				multi *= temp[j] / common;
				if (multi < 0 || multi > A[i])
					break;
			}
			if (multi != A[i])
				newA.push_back(A[i]);
		}

		newB.push_back(B[0]);
		for(int i = 1;i < B.size();i++)
		{
			vector<int> temp;
			temp.clear();
			for(int j = i - 1;j >= 0;j--)
			{
				if(B[i] % B[j] == 0)
					temp.push_back(B[j]);
			}
			if (temp.size() <= 0)
			{
				newB.push_back(B[i]);
				continue;
			}
			
			long long multi = temp[0];
			for(int j = 1;j < temp.size();j++)
			{
				int common = gcd(multi, temp[j]);
				multi *= temp[j] / common;
				if (multi < 0 || multi > B[i])
					break;
			}
			if (multi != B[i])
				newB.push_back(B[i]);
		}

		if (newA.size() != newB.size())
			return "Not equal";
		else
		{
			for(int i = 0;i < newA.size();i++)
				if (newA[i] != newB[i])
					return "Not equal";
		}
		return "Equal";
	}
};
