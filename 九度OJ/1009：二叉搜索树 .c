/*
题目描述：
判断两序列是否为同一二叉搜索树序列
输入：
开始一个数n，(1<=n<=20) 表示有n个需要判断，n= 0 的时候输入结束。
接下去一行是一个序列，序列长度小于10，包含(0~9)的数字，没有重复数字，根据这个序列可以构造出一颗二叉搜索树。
接下去的n行有n个序列，每个序列格式跟第一个序列一样，请判断这两个序列是否能组成同一颗二叉搜索树。
输出：
如果序列相同则输出YES，否则输出NO
样例输入：
2
567432
543267
576342
0
样例输出：
YES
NO
*/


#include <iostream>
#include <cstring>
using namespace std;

int gen(char *str, int *arr)
{
	int temp[1100];
	int i, j;
	for(i = 0;i < 1100;i++)
		temp[i] = -1;
	int len = strlen(str);
//	cout << len << endl;

	temp[0] = str[0] - '0';
	
	for(i = 1;i < len;i++)
	{
		int p = 0;
		while(temp[p] != -1)
		{
			if (temp[p] > str[i] - '0')
				p = p * 2 + 2;
			else
				p = p * 2 + 1;
		}
	//	cout << p << endl;
		temp[p] = str[i] - '0';
	}
	for(j = 0, i = 0;j < 1100;j++)
		if (temp[j] != -1)
			arr[i++] = temp[j];
//	cout << i << endl;
}

int main()
{
	int i, j, n;
	int len1, len2;
	char str[1000];
	int arr[1000], arr1[1000];

	while(cin >> n, n)
	{
	//	getchar();
		cin >> str;
		len1 = strlen(str);
	//	cout << len1 << endl;
		gen(str, arr);
		
		//cout << len1 << endl;
		for(int i = 0;i < n;i++)
		{
			cin >> str;
			
//		cout << len1 << endl;
			gen(str, arr1);
			
//		cout << len1 << endl;
			len2 = strlen(str);
			if (len1 != len2)
			{
//				cout << len1 << " " << len2 << endl;
				cout << "NO" << endl;
				continue;
			}
			for(j = 0;j < len1;j++)
				if (arr[j] != arr1[j])
					break;
			if (j < len1)
				cout << "NO" << endl;
			else
				cout << "YES" << endl;
		}
	}
	return 0;
}
