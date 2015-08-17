/*
题目描述：
对给定的字符串(只包含'z','o','j'三种字符),判断他是否能AC。

是否AC的规则如下：
1. zoj能AC；
2. 若字符串形式为xzojx，则也能AC，其中x可以是N个'o' 或者为空；
3. 若azbjc 能AC，则azbojac也能AC，其中a,b,c为N个'o'或者为空；
输入：
输入包含多组测试用例，每行有一个只包含'z','o','j'三种字符的字符串，字符串长度小于等于1000。
输出：
对于给定的字符串，如果能AC则请输出字符串“Accepted”，否则请输出“Wrong Answer”。
样例输入：
zoj
ozojo
ozoojoo
oozoojoooo
zooj
ozojo
oooozojo
zojoooo
样例输出：
Accepted
Accepted
Accepted
Accepted
Accepted
Accepted
Wrong Answer
Wrong Answer
*/


#include <iostream>
#include <cstring>
using namespace std;


int check(char *str)
{
	if (strcmp(str, "zoj") == 0)
		return 1;
	
	int i, j;
	int midZ;
	int a, b;
	char ss[1005];
	int len = strlen(str);

	for(i = 0, a = 0;i < len && str[i] == 'o';i++)
		a++;
	for(j = len - 1, b = 0;j >= 0 && str[j] == 'o';j--)
		b++;

	if (a == b && len == a + b + 3 && str[a] == 'z' && str[len - b - 1] == 'j' && str[a + 1] == 'o')
		return 1;

	if (b >= a && str[a] == 'z' && str[len - b - 1] == 'j')
	{
		midZ = 0;
		for(i = a + 1;i < len - b - 1;i++)
			if (str[i] != 'o')
				return 0;
			else
				midZ++;

		if (midZ < 1)
			return 0;

		for(i = 0;i < a;i++)
			ss[i] = str[i];

		midZ--;
		ss[i++] = 'z';
		for(;midZ;midZ--, i++)
			ss[i] = 'o';
		ss[i++] = 'j';
		b -= a;
		for(;b;b--,i++)
			ss[i] = 'o';
		ss[i] = '\0';
		return check(ss);
	}
	return 0;
}

int main()
{
	char str[1005];

	while(cin >> str)
	{
		if (check(str))
			cout << "Accepted" << endl;
		else
			cout << "Wrong Answer" << endl;
	}
	return 0;
}
