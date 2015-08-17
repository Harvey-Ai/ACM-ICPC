/*
描述
输入4行全部由大写字母组成的文本，输出一个垂直直方图，给出每个字符出现的次数。注意：只用输出字符的出现次数，不用输出空白字符，数字或者标点符号的输出次数。

输入
输入包括4行由大写字母组成的文本，每行上字符的数目不超过80个。
输出
输出包括若干行。其中最后一行给出26个大写英文字母，这些字母之间用一个空格隔开。前面的几行包括空格和星号，每个字母出现几次，就在这个字母的上方输出一个星号。注意：输出的第一行不能是空行。
样例输入
THE QUICK BROWN FOX JUMPED OVER THE LAZY DOG.
THIS IS AN EXAMPLE TO TEST FOR YOUR
HISTOGRAM PROGRAM.
HELLO!
样例输出
                            *
                            *
        *                   *
        *                   *     *   *
        *                   *     *   *
*       *     *             *     *   *
*       *     * *     * *   *     * * *
*       *   * * *     * *   * *   * * * *
*     * * * * * *     * * * * *   * * * *     * *
* * * * * * * * * * * * * * * * * * * * * * * * * *
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
*/

#include <stdio.h>
#include <string.h>

int main()
{
	int i, j;
	int max;
	char c;
	int arr[27];
	memset(arr, 0, sizeof(arr));
	while(scanf("%c", &c) != EOF)
		if (c >= 'A' && c <= 'Z')
			arr[c - 'A']++;

	max = 0;
	for(i = 0;i < 26;i++)
		if (max < arr[i])
			max = arr[i];

	for(i = max;i > 0;i--)
	{
		for(j = 0;j < 25;j++)
			if (arr[j] >= i)
				printf("* ");
			else
				printf("  ");
		if (arr[25] >= i)
			printf("*");
		else
			printf(" ");
		putchar('\n');
	}
	for(i = 0;i < 25;i++)
		printf("%c ", i + 'A');
	printf("Z\n");
	return 0;
}
