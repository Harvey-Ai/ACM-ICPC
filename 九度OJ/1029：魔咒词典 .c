/*
题目描述：
    哈利波特在魔法学校的必修课之一就是学习魔咒。据说魔法世界有100000种不同的魔咒，哈利很难全部记住，但是为了对抗强敌，他必须在危急时刻能够调用任何一个需要的魔咒，所以他需要你的帮助。

    给你一部魔咒词典。当哈利听到一个魔咒时，你的程序必须告诉他那个魔咒的功能；当哈利需要某个功能但不知道该用什么魔咒时，你的程序要替他找到相应的魔咒。如果他要的魔咒不在词典中，就输出“what?”
输入：
    首先列出词典中不超过100000条不同的魔咒词条，每条格式为：

    [魔咒] 对应功能

    其中“魔咒”和“对应功能”分别为长度不超过20和80的字符串，字符串中保证不包含字符“[”和“]”，且“]”和后面的字符串之间有且仅有一个空格。词典最后一行以“@END@”结束，这一行不属于词典中的词条。
    词典之后的一行包含正整数N（<=1000），随后是N个测试用例。每个测试用例占一行，或者给出“[魔咒]”，或者给出“对应功能”。
输出：
    每个测试用例的输出占一行，输出魔咒对应的功能，或者功能对应的魔咒。如果魔咒不在词典中，就输出“what?”
样例输入：
[expelliarmus] the disarming charm
[rictusempra] send a jet of silver light to hit the enemy
[tarantallegra] control the movement of one's legs
[serpensortia] shoot a snake out of the end of one's wand
[lumos] light the wand
[obliviate] the memory charm
[expecto patronum] send a Patronus to the dementors
[accio] the summoning charm
@END@
4
[lumos]
the summoning charm
[arha]
take me to the sky
样例输出：
light the wand
accio
what?
what?
*/


#include <iostream>
#include <map>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
	map<string, string> dir1, dir2;
	string str1, str2, str;
	while(getline(cin, str, '\n'), str != "@END@")
	{
		int pos = str.find(']');
		str1 = str.substr(0, pos + 1);
		str2 = str.substr(pos + 2);
		dir1[str1] = str2;
		dir2[str2] = str1;
	}
//	cout << str1 << endl;

	int n;
	cin >> n;
	getchar();
	while(n--)
	{
		getline(cin, str);
		if (str[0] == '[')
		{
			if (dir1.count(str) >= 1)
				cout << dir1[str] << endl;
			else
				cout << "what?" << endl;
		}
		else
		{
			if (dir2.count(str) >= 1)
				cout << dir2[str].substr(1, dir2[str].length() - 2) << endl;
			else
				cout << "what?" << endl;
		}
	}
	return 0;
}
