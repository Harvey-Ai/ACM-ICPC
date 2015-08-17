#include <string>
#include <vector>
#include <iostream>
using namespace std;
class AstronomicalRecords {
	public:
	int gcd(int a, int b)
	{
		if (b == 0)
			return a;
		else
			return gcd(b, a % b);
	}
	int minimalPlanets(vector <int> A, vector <int> B) {
		
		int ratioA;
		int AA[100][2], BB[100][2];

		ratioA = A[0];
		for(int i = 0;i < A.size();i++)
		{
			int temp = gcd(A[i], ratioA);
			AA[i][0] = A[i] / temp;
			AA[i][1] = ratioA / temp;

		}

		int res = A.size() + B.size();
		for(int i = 0;i < A.size();i++)
			for(int j = 0;j < B.size();j++)
			{
				for(int k = 0;k < B.size();k++)
				{
					BB[k][0] = B[k] * AA[i][0];
					BB[k][1] = B[j] * AA[i][1];
					int temp = gcd(BB[k][0], BB[k][1]);
					BB[k][0] /= temp;
					BB[k][1] /= temp;
				}

				int tempRes = A.size() + B.size();
				int l = 0;
				for(int k = 0;k < A.size();k++, l++)
					for(;l < B.size();l++)
						if (AA[k][0] == BB[l][0] && AA[k][1] == BB[l][1])
						{
							tempRes --;
							break;
						}
				if (tempRes < res)
					res = tempRes;
			}
		return res;		
	}
};
