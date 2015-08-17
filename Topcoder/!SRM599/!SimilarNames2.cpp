#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class SimilarNames2 {
	private:
		long long C[100][100];
		long long jie[50];
	public:
	void calcC()
	{
		C[1][1] = 1;
		C[1][0] = 1;
		for(int i = 2;i <= 50;i++)
		{
			C[i][0] = 1;
			for(int j = 1;j <= 50 && j <= i;j++)
				C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % 1000000007;
		}
	}
	void calcJ()
	{
		jie[0] = 1;
		jie[1] = 1;
		for(int i = 2;i <= 50;i++)
			jie[i] = (jie[i - 1] * i) % 1000000007;
	}

	int count(vector <string> names, int L) {
		long long res = 0;
		calcC();
		calcJ();
		sort(&names[0], &names[names.size()]);
		int begin = 0;
		for(int i = 1;i < names.size();i++)
		{
			int j = 0;
			for(j = 0;j < names[i - 1].size();j++)
				if (names[i].size() < j + 1 || names[i - 1][j] != names[i][j])
					break;
			if (j < names[i - 1].size())
			{
				if (L <= i - begin)
				{
					res += C[i - begin][L] * jie[names.size() - i + begin];
					res %= 1000000007;
				}
				begin = i;
			}
		}
		if (L + begin <= names.size())
		{
			res += C[names.size() - begin][L] * jie[begin];
			res %= 1000000007;
		}
		return int(res);
	}
};

int main()
{
	SimilarNames2 *a = new SimilarNames2();
	vector<string> b;
   	b.push_back("ryota");
	b.push_back("ryohei");
    b.push_back("ryotaro");
   	b.push_back("ryo");
   	b.push_back("ryoga");
   	b.push_back("ryoma");
   	b.push_back("ryoko");
    b.push_back("ryosuke");
   	b.push_back("ciel");
   	b.push_back("lun");
	b.push_back("ryuta");
   	b.push_back("ryuji");
   	b.push_back("ryuma");
   	b.push_back("ryujiro");
   	b.push_back("ryusuke");
   	b.push_back("ryutaro");
   	b.push_back("ryu");
   	b.push_back("ryuhei");
   	b.push_back("ryuichi");
   	b.push_back("evima");

	cout << a->count(b, 3) << endl;
	return 0;
}
