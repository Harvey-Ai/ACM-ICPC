/*
描述
有9个时钟，排成一个3*3的矩阵。

|-------|    |-------|    |-------|
|       |    |       |    |   |   |
|---O   |    |---O   |    |   O   |
|       |    |       |    |       |
|-------|    |-------|    |-------|
    A            B            C    

|-------|    |-------|    |-------|
|       |    |       |    |       |
|   O   |    |   O   |    |   O   |
|   |   |    |   |   |    |   |   |
|-------|    |-------|    |-------|
    D            E            F    

|-------|    |-------|    |-------|
|       |    |       |    |       |
|   O   |    |   O---|    |   O   |
|   |   |    |       |    |   |   |
|-------|    |-------|    |-------|
    G            H            I    
(图 1)
现在需要用最少的移动，将9个时钟的指针都拨到12点的位置。共允许有9种不同的移动。如下表所示，每个移动会将若干个时钟的指针沿顺时针方向拨动90度。


移动    影响的时钟
 
 1         ABDE
 2         ABC
 3         BCEF
 4         ADG
 5         BDEFH
 6         CFI
 7         DEGH
 8         GHI
 9         EFHI    
     (图 2)
输入
从标准输入设备读入9个整数，表示各时钟指针的起始位置。0=12点、1=3点、2=6点、3=9点。
输出
输出一个最短的移动序列，使得9个时钟的指针都指向12点。按照移动的序号大小，输出结果。
样例输入
3 3 0 
2 2 2 
2 1 2 
样例输出
4 5 8 9 
*/

#include <iostream>
using namespace std;
int move[9][6] = {{0, 1, 3, 4}, {0, 1, 2}, {1, 2, 4, 5}, {0, 3, 6}, {1, 3, 4, 5, 7}, {2, 5, 8}, {3, 4, 6, 7}, {6, 7, 8}, {4, 5, 7, 8}};
int moveNum[9] = {4, 3, 4, 3, 5, 3, 4, 3, 4};

//int ok;
int best;
int Clock[9];
int flag[9];
int res[1000];
int dfs(int layer, int moveCount)
{
	int i, j;
	if (best <= moveCount)
		return 0;
	if (layer == 9)
	{
		for(i = 0;i < 9;i++)
			if (Clock[i] != 0)
				return 0;
		for(i = 0;i < 9;i++)
			res[i] = flag[i];

		best = moveCount;
		return 0;
	}
	for(i = 0;i < 4;i++)
	{
		flag[layer] = i;
		for(j = 0;j < moveNum[layer];j++)
			Clock[move[layer][j]] = (Clock[move[layer][j]] + i) % 4;
		dfs(layer + 1, i + moveCount);
		
		for(j = 0;j < moveNum[layer];j++)
			Clock[move[layer][j]] = (Clock[move[layer][j]] - i + 4) % 4;
	}
}
int main()
{
	int initClock[9];
	int i, j;

	for(i = 0;i < 9;i++)
	{
		cin >> initClock[i];
		Clock[i] = initClock[i];
	}

//	ok = 0;
	for(i = 0;i < 9;i++)
		flag[i] = 0;
	best = 10000000;
	dfs(0, 0);
	for(i = 0;i < 9;i++)
	//	if (res[i])
		for(j = 0;j < res[i];j++)
			cout << i + 1 << " ";

	//if (best == 10000000)
	//	while(1);
	return 0;
}
