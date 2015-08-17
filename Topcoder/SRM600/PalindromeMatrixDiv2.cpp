#include <string>
#include <vector>
#include <iostream>
using namespace std;
class PalindromeMatrixDiv2 {
	public:
	int matrix[10][10];
	int best;
	int rowC, columnC;
	int row, column;
	int columnP[10], rowP[10];

	void dfsC(int k, int l)
	{	
		if (k < column)
		{
			if (l > 0)
			{
				columnP[k] = 1;
				dfsC(k + 1, l - 1);
			}
			if (column - k - 1 >= l)
			{
				columnP[k] = 0;		
				dfsC(k + 1, l);
			}
		}
		else
		{
			int revertNum = 0;
			int tempMatrix[10][10];
			for(int i = 0;i < row;i++)
				for(int j = 0;j < column;j++)
					tempMatrix[i][j] = matrix[i][j];
			for(int i = 0;i < row;i++)
			{
				if (!rowP[i] && !rowP[row - i - 1])
				{
					for(int j = 0;j < column;j++)
						tempMatrix[i][j] = matrix[i][j];
				}
				if (rowP[i])
				{
					for(int j = 0;j < column / 2;j++)
					{
						int c1 = j;
						int c2 = column - j - 1;

						int z = 0;
						int o = 0;
						if (matrix[i][c1] == 1)
							o++;
						else
							z++;
						if (matrix[i][c2] == 1)
							o++;
						else
							z++;
						if (columnP[c1] || (columnP[c2] && rowP[row - i - 1]))
						{
							if (matrix[row - i - 1][c1] == 1)
								o++;
							else
								z++;
						}
						if (columnP[c2] || (columnP[c1] && rowP[row - i - 1]))
						{
							if (matrix[row - i - 1][c2] == 1)
								o++;
							else
								z++;
						}

						tempMatrix[i][c1] = tempMatrix[i][c2] = z > o ? 0 : 1;
						if (columnP[c1] || (columnP[c2] && rowP[row - i - 1]))
							tempMatrix[row - i - 1][c1] = z > o ? 0 : 1;
						if (columnP[c2] || (columnP[c1] && rowP[row - i - 1]))
							tempMatrix[row - i - 1][c2] = z > o ? 0 : 1;
					}
				}
			}
			for(int i = 0;i < column;i++)
			{
				if (!columnP[i])
					continue;
				for(int j = 0;j < row / 2;j++)
					if (!rowP[j] && !rowP[row - 1 - j])
						tempMatrix[j][i] =  tempMatrix[row - 1 - j][i];
			}
			for(int i = 0;i < row;i++)
				for(int j = 0;j < column;j++)
					revertNum += tempMatrix[i][j] ^ matrix[i][j];
			if (revertNum < best || best == -1)
				best = revertNum;
		}
	}
	void dfsR(int k, int l)
	{
		if (k < row)
		{
			if (l > 0)
			{
				rowP[k] = 1;
				dfsR(k + 1, l - 1);
			}
			if (row - k - 1 >= l)
			{
				rowP[k] = 0;		
				dfsR(k + 1, l);
			}
		}
		else
			dfsC(0, columnC);
	}

	int minChange(vector <string> A, int rowCount, int columnCount) {
		
		for(int i = 0;i < A.size();i++)
			for(int j = 0;j < A[0].size();j++)
				matrix[i][j] = A[i][j] - '0';
		rowC = rowCount;
		columnC = columnCount;
		row = A.size();
		column = A[0].size();
		best = -1;
		dfsR(0, rowC);
		
		return best;
	}
};
