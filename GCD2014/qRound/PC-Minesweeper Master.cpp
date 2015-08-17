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
		int R, C, M;
		input >> R >> C >> M;

		
	}


	return 0;
}
