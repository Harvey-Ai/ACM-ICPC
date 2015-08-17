#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

char str[100005];
int main()
{
	scanf("%s", str);
	int len = strlen(str);

	int num = str[len - 1] - '0';
	if (len - 2 >= 0)
		num += (str[len - 2] - '0') * 10;
	if (len - 3 >= 0)
		num += (str[len - 3] - '0') * 100;

	if (num % 4 == 0)
		cout << 4 << endl;
	else
		cout << 0 << endl;
	return 0;
}
