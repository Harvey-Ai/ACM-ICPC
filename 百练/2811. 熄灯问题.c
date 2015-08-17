/*
描述
有一个由按钮组成的矩阵，其中每行有6个按钮，共5行。每个按钮的位置上有一盏灯。当按下一个按钮后，该按钮以及周围位置(上边、下边、左边、右边)的灯都会改变一次。即，如果灯原来是点亮的，就会被熄灭；如果灯原来是熄灭的，则会被点亮。在矩阵角上的按钮改变3盏灯的状态；在矩阵边上的按钮改变4盏灯的状态；其他的按钮改变5盏灯的状态。



在上图中，左边矩阵中用X标记的按钮表示被按下，右边的矩阵表示灯状态的改变。对矩阵中的每盏灯设置一个初始状态。请你按按钮，直至每一盏等都熄灭。与一盏灯毗邻的多个按钮被按下时，一个操作会抵消另一次操作的结果。在下图中，第2行第3、5列的按钮都被按下，因此第2行、第4列的灯的状态就不改变。



请你写一个程序，确定需要按下哪些按钮，恰好使得所有的灯都熄灭。根据上面的规则，我们知道1）第2次按下同一个按钮时，将抵消第1次按下时所产生的结果。因此，每个按钮最多只需要按下一次；2）各个按钮被按下的顺序对最终的结果没有影响；3）对第1行中每盏点亮的灯，按下第2行对应的按钮，就可以熄灭第1行的全部灯。如此重复下去，可以熄灭第1、2、3、4行的全部灯。同样，按下第1、2、3、4、5列的按钮，可以熄灭前5列的灯。


输入
第一行是一个正整数N，表示需要解决的案例数。每个案例由5行组成，每一行包括6个数字。这些数字以空格隔开，可以是0或1。0表示灯的初始状态是熄灭的，1表示灯的初始状态是点亮的。
输出
对每个案例，首先输出一行，输出字符串“PUZZLE #m”，其中m是该案例的序号。接着按照该案例的输入格式输出5行，其中的1表示需要把对应的按钮按下，0则表示不需要按对应的按钮。每个数字以一个空格隔开。
样例输入
2 
0 1 1 0 1 0
1 0 0 1 1 1 
0 0 1 0 0 1 
1 0 0 1 0 1 
0 1 1 1 0 0 
0 0 1 0 1 0 
1 0 1 0 1 1 
0 0 1 0 1 1 
1 0 1 1 0 0 
0 1 0 1 0 0 
样例输出
PUZZLE #1 
1 0 1 0 0 1 
1 1 0 1 0 1 
0 0 1 0 1 1 
1 0 0 1 0 0 
0 1 0 0 0 0
PUZZLE #2 
1 0 0 1 1 1 
1 1 0 0 0 0 
0 0 0 1 0 0 
1 1 0 1 0 1 
1 0 1 1 0 1 
*/


#include <iostream>
using namespace std;

int lig[100][100];
int g[100][100];
int temp[100][100];
int result;

/*
int check()
{
	int i, j;
	int temp[100][100];

	for(i = 0;i < 5;i++)
		for(j = 0;j < 6;j++)
			temp[i][j] = g[i][j];

	for(i = 0;i < 5;i++)
		for(j = 0;j < 6;j++)
			if (lig[i][j] == 1)
			{
				if (i - 1 >= 0) temp[i-1][j] = 1 - temp[i-1][j];
				if (j - 1 >= 0) temp[i][j-1] = 1 - temp[i][j-1];
				if (i + 1 < 5) temp[i+1][j] = 1 - temp[i+1][j];
				if (j + 1 < 6) temp[i][j+1] = 1 - temp[i][j+1];
				temp[i][j] = 1 - temp[i][j];
			}

	for(i = 0;i < 5;i++)
		for(j = 0;j < 6;j++)
			if (temp[i][j] == 1)
				return 0;
	return 1;
}
*/
int cal(int row, int column)
{
	int i = row, j = column;
	if (i - 1 >= 0) temp[i-1][j] = 1 - temp[i-1][j];
	if (j - 1 >= 0) temp[i][j-1] = 1 - temp[i][j-1];
	if (i + 1 < 5) temp[i+1][j] = 1 - temp[i+1][j];
	if (j + 1 < 6) temp[i][j+1] = 1 - temp[i][j+1];
	temp[i][j] = 1 - temp[i][j];
}

int check(int a, int b)
{
	int i, j;
	for(i = a; i <= b;i++)
		for(j = 0;j < 6;j++)
			if (temp[i][j] == 1)
				return 0;
	return 1;
}

void dfs(int row, int column)
{
	int i, j;
	if (row == 5 && column == 0 && result == 0)
	{
		result = check(3, 4);
		if (result == 1)
		{
			for(i = 0;i < 5;i++)
			{
				for(j = 0;j < 6;j++)
					cout<<lig[i][j]<<" ";
				cout<<endl;
			}
		}
	}
	if (column == 0 && row > 1)
		if (!check (row - 2, row - 2))
			return;

	if (result == 1 || row >= 5)
		return;
	//cout << row << " " << column << endl;
	lig[row][column] = 0;
	if (column + 1 == 6)
		dfs(row + 1, 0);
	else
		dfs(row, column + 1);

	lig[row][column] = 1;
	cal(row, column);
	if (column + 1 == 6)
		dfs(row + 1, 0);
	else
		dfs(row, column + 1);
	cal(row, column);
}

int main()
{
	int n;
	int i, j;
	int icase;

	cin >> n;

	for(icase = 1;icase <= n;icase++)
	{
		for(i = 0;i < 5;i++)
			for(j = 0;j < 6;j++)
			{
				cin >> g[i][j];
				temp[i][j] = g[i][j];
			}

		result = 0;
		cout << "PUZZLE #" << icase << endl; 
		dfs(0, 0);
	//	cout << "fdasfd" << endl;
	}

	return 0;
}
