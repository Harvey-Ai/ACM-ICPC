/*
题目描述：
读入一个字符串，字符串中包含ZOJ三个字符，个数不一定相等，按ZOJ的顺序输出，当某个字符用完时，剩下的仍然按照ZOJ的顺序输出。
输入：
题目包含多组用例,每组用例占一行，包含ZOJ三个字符，当输入“E”时表示输入结束。
1<=length<=100。
输出：
对于每组输入,请输出一行，表示按照要求处理后的字符串。
具体可见样例。
样例输入：
ZZOOOJJJ
ZZZZOOOOOJJJ
ZOOOJJ
E
样例输出：
ZOJZOJOJ
ZOJZOJZOJZOO
ZOJOJO
*/

#include <iostream>
using namespace std;

int main()
{
	int i, j;
	char str[10000];

	while(cin >> str, str[0] != 'E')
	{
		int arr[3] = {0, 0, 0};
		char ss[3] = {'Z', 'O', 'J'};

	//	arr[0] = arr[1] = arr[2] = 0;
		for(i = 0;str[i] != '\0';i++)
		{
			if (str[i] == 'Z')
				arr[0]++;
			else if (str[i] == 'O')
				arr[1]++;
			else arr[2]++;
		}

		//cout << arr[0] << arr[1] << arr[2] << endl;
		for(i = 0, j = 0;str[i] != '\0';i++)
		{
			while (arr[j] == 0)
				j = (j + 1) % 3;
			cout << ss[j];
			arr[j]--;
			j = (j + 1) % 3;
		}
		cout << endl;
	}
	return 0;
}
