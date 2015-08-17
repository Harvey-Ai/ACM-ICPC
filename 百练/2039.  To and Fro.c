/*
描述
Mo and Larry have devised a way of encrypting messages. They first decide secretly on the number of columns and write the message (letters only) down the columns, padding with extra random letters so as to make a rectangular array of letters. For example, if the message is "There’s no place like home on a snowy night" and there are five columns, Mo would write down
t o i o y
h p k n n
e l e a i
r a h s g
e c o n h
s e m o t
n l e w x

Note that Mo includes only letters and writes them all in lower case. In this example, Mo used the character "x" to pad the message out to make a rectangle, although he could have used any letter.

Mo then sends the message to Larry by writing the letters in each row, alternating left-to-right and right-to-left. So, the above would be encrypted as

toioynnkpheleaigshareconhtomesnlewx

Your job is to recover for Larry the original message (along with any extra padding letters) from the encrypted one.
输入
There will be multiple input sets. Input for each set will consist of two lines. The first line will contain an integer in the range 2. . . 20 indicating the number of columns used. The next line is a string of up to 200 lower case letters. The last input set is followed by a line containing a single 0, indicating end of input.
输出
Each input set should generate one line of output, giving the original plaintext message, with no spaces.
样例输入
5
toioynnkpheleaigshareconhtomesnlewx
3
ttyohhieneesiaabss
0
样例输出
theresnoplacelikehomeonasnowynightx
thisistheeasyoneab

*/

#include <iostream>
#include <cstring>
using namespace std;

char str[1000];
char str2[300][300];

int main()
{
	int n;
	int i, j;
	int c, x, y;
	int row;

	while(cin >> n, n != 0)
	{
		cin >> str;

		c = 1;
		x = 0, y = 0;
		for(i = 0;str[i] != '\0';i++)
		{
			str2[x][y] = str[i];
			y += c;
			if (y < 0)
			{
				y = 0;
				x++;
				c = -c;
			}
			else if (y >= n)
			{
				y = n - 1;
				x++;
				c = -c;
			}
		}
		row = strlen(str) / n;
		for(j = 0;j < n;j++)
			for(i = 0;i < row;i++)
				cout << str2[i][j];
		cout << endl;
	}
	return 0;
}
