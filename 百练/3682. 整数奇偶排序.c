/*
描述
输入10个整数，彼此以空格分隔
重新排序以后输出(也按空格分隔)，要求:
1.先输出其中的奇数,并按从大到小排列；
2.然后输出其中的偶数,并按从小到大排列。
输入
任意排序的10个整数（0～100），彼此以空格分隔
输出
按照要求排序后输出，由空格分隔
样例输入
4 7 3 13 11 12 0 47 34 98
样例输出
47 13 11 7 3 0 4 12 34 98
*/

#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(const int a, const int b)
{
	return a < b ? 0 : 1;
}

int main()
{
	int num1, num2;
	int a[100];
	int odd[100], even[100];
	int i;

	while(cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5] >> a[6] >> a[7] >> a[8] >> a[9])
	{
		num1 = num2 = 0;
		for(i = 0;i < 10;i++)
			if (a[i] % 2)
				odd[num1++] = a[i];
			else
				even[num2++] = a[i];

		sort(&odd[0], &odd[num1], cmp);
		sort(&even[0], &even[num2]);
		for(i = 0;i < num1;i++)
			cout << odd[i] << " ";
		for(i = 0;i < num2;i++)
			cout << even[i] << " ";
		cout << endl;
	}
	return 0;
}
