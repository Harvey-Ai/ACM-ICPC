/*
描述
问题描述：
　　宇航员在太空中迷失了方向，在他的起始位置现在建立一个虚拟xyz坐标系，称为绝对坐标系，宇航员正面的方向为x轴正方向，头顶方向为z轴正方向，则宇航员的初始状态如下图所示：


现对六个方向分别标号，x，y，z正方向分别为0，1，2，负方向分别为3，4，5；称它们为绝对方向。宇航员在宇宙中只沿着与绝对坐标系xyz轴平行的方向行走，但是他不知道自己当前绝对坐标和自己面向的绝对方向。

任务描述：
　　请根据宇航员对自己在相对方向上移动的描述确定宇航员最终的绝对坐标和面向的绝对方向。对在相对方向上移动的描述及意义如下：
forward x 　向前走x米。
back x　先转向后，再走x米。
left x 先转向左，再走x米。
right x 先转向右，再走x米。
up x 先面向上，再走x米。
down x 先面向下，再走x米。
其中向上和向下如下图所示：

输入
第一行一个正整数m，表示测试数据的组数。每组测试数据第一行是一个正整数n(1<=n<=10000)表示宇航员行走的次数，下面n行每行输入一次相对行走，格式如上所述，其中( 1 <= x <= 10000 为正整数)。
输出
对于每组输入数据输出一行，x y z p, 中间用空格隔开，x y z是宇航员的位置的绝对坐标，p是宇航员面向的绝对方向编号（0<=p <=5）。
样例输入
1
6
left 10
right 11
up 12
down 13
forward 14
back 15
样例输出
23 -10 12 3
*/


#include <iostream>
#include <cstring>
using namespace std;

struct astor
{
	int head, foot;
	int left, right;
	int ahead, back;
	int x, y, z;
};

int main()
{
	struct astor person;
	int num, n;
	char str[100];
	cin >> n;

	while(n--)
	{
		person.head = 2;
		person.foot = 5;
		person.left = 4;
		person.right = 1;
		person.ahead = 0;
		person.back = 3;
		person.x = person.y = person.z = 0;

		int naction;
		cin >> naction;
		while(naction--)
		{
			cin >> str;
			cin >> num;
			if (strcmp(str, "left") == 0)
			{
				int temp1 = person.ahead;
				int temp2 = person.back;
				person.ahead = person.left;
				person.back = (person.ahead + 3) % 6;
				person.left = temp2;
				person.right = temp1;
			}
			else if (strcmp(str, "right") == 0)
			{
				int temp1 = person.ahead;
				int temp2 = person.back;
				person.ahead = person.right;
				person.back = (person.ahead + 3) % 6;
				person.right = temp2;
				person.left = temp1;
			}
			else if (strcmp(str, "back") == 0)
			{
				person.ahead = person.back;
				person.back = (person.ahead + 3) % 6;
				int temp = person.right;
				person.right = person.left;
				person.left = temp;
			}
			else if (strcmp(str, "up") == 0)
			{
				int temp1 = person.ahead;
				int temp2 = person.back;
				person.ahead = person.head;
				person.back = person.foot;
				person.foot = temp1;
				person.head = temp2;
			}
			else if (strcmp(str, "down") == 0)
			{
				int temp1 = person.ahead;
				int temp2 = person.back;
				person.ahead = person.foot;
				person.back = person.head;
				person.foot = temp2;
				person.head = temp1;
			}
			switch(person.ahead)
			{
				case 0: {person.x += num;break;}
				case 1: {person.y += num;break;}
				case 2: {person.z += num;break;}
				case 3: {person.x -= num;break;}
				case 4: {person.y -= num;break;}
				case 5: {person.z -= num;break;}
				default:break;
			}
		//	cout << "ahead" << person.ahead << endl;
		}
		cout << person.x << " " << person.y << " " << person.z << " " << person.ahead << endl;
	}
	return 0;
}
