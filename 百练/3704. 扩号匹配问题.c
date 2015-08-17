/*
描述
在某个字符串（长度不超过100）中有左括号、右括号和大小写字母；规定（与常见的算数式子一样）任何一个左括号都从内到外与在它右边且距离最近的右括号匹配。写一个程序，找到无法匹配的左括号和右括号，输出原来字符串，并在下一行标出不能匹配的括号。不能匹配的左括号用"$"标注,不能匹配的右括号用"?"标注.
输入
输入包括多组数据，每组数据一行，包含一个字符串，只包含左右括号和大小写字母，字符串长度不超过100
注意：cin.getline(str,100)最多只能输入99个字符！
输出
对每组输出数据，输出两行，第一行包含原始输入字符，第二行由"$","?"和空格组成，"$"和"?"表示与之对应的左括号和右括号不能匹配。
样例输入
((ABCD(x)
)(rttyy())sss)(
样例输出
((ABCD(x)
$$
)(rttyy())sss)(
?            ?$
*/


#include <stdio.h>
#include <string.h>

int main()
{
	char str[105];
	int ans[101];
	int stack[101];
	int top;
	int i;
	while(scanf("%s", str) != EOF)
	{

		top = 0;
		memset(ans, 0, sizeof(ans));
		for(i = 0;str[i] != '\0';i++)
			if (str[i] == '(')
				stack[top++] = i;
			else if (str[i] == ')')
			{
				if (top <= 0)
					ans[i] = 1;
				else
					top--;
			}
		for(;top > 0;top--)
			ans[stack[top - 1]] = -1;

		printf("%s\n", str);
		for(i = 0;str[i] != '\0';i++)
		{
			if (ans[i] == 0)
				putchar(' ');
			if (ans[i] == -1)
				putchar('$');
			if (ans[i] == 1)
				putchar('?');
		}
		putchar('\n');
	}
	return 0;
}
