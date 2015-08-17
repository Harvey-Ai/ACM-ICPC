/*
描述
N只小白鼠(1 < N < 100)，每只鼠头上戴着一顶有颜色的帽子。现在称出每只白鼠的重量，要求按照白鼠重量从小到大的顺序输出它们头上帽子的颜色。帽子的颜色用 “red”，“blue”等字符串来表示。不同的小白鼠可以戴相同颜色的帽子。白鼠的重量用整数表示。

输入
输入第一行为一个整数N，表示小白鼠的数目。
下面有N行，每行是一只白鼠的信息。第一个为正整数，表示白鼠的重量，；第二个为字符串，表示白鼠的帽子颜色，字符串长度不超过10个字符。

注意：白鼠的重量各不相同。
输出
按照白鼠的重量从小到大的顺序输出白鼠的帽子颜色。
样例输入
3
30 red
50 blue
40 green
样例输出
red
green
blue
*/


#include <iostream>
#include <algorithm>
using namespace std;

struct ms
{
	int weight;
	char color[100];
};

bool cmp(const struct ms a, const struct ms b)
{
	return a.weight - b.weight > 0 ? 0 : 1;
}

int main()
{
	int n;
	struct ms mouse[150];
	int i;
	cin >> n;
	for(i = 0;i < n;i++)
		cin >> mouse[i].weight >> mouse[i].color;

	sort(&mouse[0], &mouse[n], cmp);

	for(i = 0;i < n;i++)
		cout << mouse[i].color << endl;
	return 0;
}
