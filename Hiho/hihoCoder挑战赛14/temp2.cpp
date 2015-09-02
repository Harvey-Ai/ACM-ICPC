/*****************************************************
 * Author: Ai Hongwei 
 * Email: ufo008ahw@163.com
 * Last modified: 2015-08-30 19:10
 * Filename: 1 不等式.cpp
 * Description: 
 ****************************************************/

/*
描述
给定n个关于X的不等式，问最多有多少个成立。

每个不等式为如下的形式之一：

X < C

X <= C

X = C

X > C

X >= C

输入
第一行一个整数n。

以下n行，每行一个不等式。

数据范围:

1<=N<=50,0<=C<=1000

输出
一行一个整数，表示最多可以同时成立的不等式个数。

样例输入
4
X = 1
X = 2
X = 3
X > 0
样例输出
2
*/

#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

int equality[55][2];
string op[5] = {"<=", ">=", ">", "<", "="};

int getInt(string str) {
	int res = 0;
	for(int i = 0;i < str.size();i++) {
		res *= 10;
		res += str[i] - '0';
	}

	return res;
}

bool check1(double num, int k) {
	if ((equality[k][0] == 0 && num <= equality[k][1])
			|| (equality[k][0] == 1 && num >= equality[k][1])
			|| (equality[k][0] == 2 && num > equality[k][1])
			|| (equality[k][0] == 3 && num < equality[k][1])
			|| (equality[k][0] == 4 && num == equality[k][1]))
		return true;

	return false;
}

bool check2(int num, int k) {
	if ((equality[k][0] == 0 && num <= equality[k][1])
			|| (equality[k][0] == 1 && num >= equality[k][1])
			|| (equality[k][0] == 2 && num > equality[k][1])
			|| (equality[k][0] == 3 && num < equality[k][1])
			|| (equality[k][0] == 4 && num == equality[k][1]))
		return true;

	return false;
}


int main() {
	int n;
	cin >> n;
	memset(equality, -1, sizeof(equality));

	for(int i = 0;i < n;i++) {
		string str = "";
		getline(cin, str);

		if (str == "") {
			i--;
			continue;
		}

		for(int j = 0;j < 5;j++) {
			if (str.find(op[j]) != string::npos) {
				equality[i][0] = j;
				break;
			}
		}

		for(int j = 0;j < str.size();j++) {
			if (str[j] >='0' && str[j] <= '9') {
				int a = getInt(str.substr(j));
				equality[i][1] = a;
				break;
			}
		}
	}
	
	for(int i = 0;i < n;i++) {
		if (equality[i][0] == -1 || equality[i][1] == -1)
			while(1);
	}

	int res = 0;
	for(double i = -0.5;i <= 1001;i += 0.5) {
		int temp = 0;
		for(int j = 0;j < n;j++) {
			temp += check1(i, j);
		}
		res = max(res, temp);
	}

	for(int i = -1;i <= 1001;i++) {
		int temp = 0;
		for(int j = 0;j < n;j++) {
			temp += check2(i, j);
		}
		res = max(res, temp);
	}

	cout << res << endl;

	return 0;
}
