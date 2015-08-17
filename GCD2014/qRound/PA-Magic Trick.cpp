#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int ncase;
	
	ifstream input("input.txt", ios::in);
	ofstream output("output.txt", ios::out);
	input >> ncase;

	for(int icase = 0;icase < ncase;icase++)
	{
		int row1, row2;
		int a[4], b[4];
		
		input >> row1;
		for(int rowI = 0;rowI < 4;rowI++)
			for(int colJ = 0;colJ < 4;colJ++)
			{
				int temp;
				if (rowI == row1 - 1)
					input >> a[colJ];
				else
					input >> temp;
			}
		input >> row2;
		for(int rowI = 0;rowI < 4;rowI++)
			for(int colJ = 0;colJ < 4;colJ++)
			{
				int temp;
				if (rowI == row2 - 1)
					input >> b[colJ];
				else
					input >> temp;
			}

		int res = -1;
		int resNum = 0;
		for(int j1 = 0;j1 < 4;j1++)
		{
			for(int j2 = 0;j2 < 4;j2++)
				if (a[j1] == b[j2])
				{
					resNum++;
					res = a[j1];
				}
		}
		if (resNum == 1)
			output << "Case #" << icase + 1 << ": " << res << endl;
		else if (resNum == 0)
			output << "Case #" << icase + 1 << ": Volunteer cheated!" << endl;
		else 
			output << "Case #" << icase + 1 << ": Bad magician!" << endl;
	}
	return 0;
}
