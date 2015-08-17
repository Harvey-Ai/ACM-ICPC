#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
using namespace std;

int main()
{
	ifstream input("input.txt", ios::in);
	ofstream output("output.txt", ios::out);

	int ncase;
	input >> ncase;

	for(int icase = 0;icase < ncase;icase++)
	{
		double c, f, x;
		input >> c >> f >> x;

		double earn = 2;
		double money = 0;
		double nowTime = 0;
		double res = x / 2 + 1;

		for(int buildNum = 0;;buildNum++)
		{
			if ((x - money) / earn + nowTime <= res)
				res = nowTime + (x - money) / earn;
			else
				break;

			double CTime = c / earn;
			if (nowTime + CTime >= res)
				break;
			else
			{
				nowTime += CTime;
				earn += f;
				money = 0;
			}
		}
		output << "Case #" << icase + 1 << ": "; 
		output << setiosflags(ios::fixed) << setprecision(7) << res << endl;
	}
	return 0;
}
