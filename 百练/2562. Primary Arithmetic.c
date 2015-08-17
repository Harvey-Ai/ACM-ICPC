/*
描述
Children are taught to add multi-digit numbers from right-to-left one digit at a time. Many find the "carry" operation - in which a 1 is carried from one digit position to be added to the next - to be a significant challenge. Your job is to count the number of carry operations for each of a set of addition problems so that educators may assess their difficulty.
输入
Each line of input contains two unsigned integers less than 10 digits. The last line of input contains 0 0.
输出
For each line of input except the last you should compute and print the number of carry operations that would result from adding the two numbers, in the format shown below.
样例输入
123 456
555 555
123 594
0 0
样例输出
No carry operation.
3 carry operations.
1 carry operation.
*/


#include <stdio.h>
#include <string.h>

void convert(char *str)
{
	char temp;
	int i;
	int len = strlen(str);

	for(i = 0;i < len / 2;i++)
	{
		temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
	}
}

int main()
{
	char str1[100], str2[100];
	int len;
	int ans;
	int i, carry;

	while(scanf("%s %s", str1, str2), (strcmp(str1, "0") != 0 || strcmp(str2, "0") != 0))
	{
		convert(str1);
		convert(str2);

		len = strlen(str1);
		if (strlen(str2) < len)
			len = strlen(str2);

		carry = 0;
		ans = 0;
		for(i = 0; i < len;i++)
		{
			carry = (carry + str1[i] + str2[i] - '0' - '0') / 10;
			if (carry)
				ans++;
		}
		if (str1[len] != '\0')
			for(i = len;str1[i] != '\0';i++)
			{
				carry = (carry + str1[i] - '0') / 10;
				if (carry)
					ans++;
			}
		else
			for(i = len;str2[i] != '\0';i++)
			{
				carry = (carry + str2[i] - '0') / 10;
				if (carry)
					ans++;
			}
		if (ans == 0)
		{
			printf("No carry operation.\n");
			continue;
		}
		if (ans == 1)
			printf("1 carry operation.\n");
		else
			printf("%d carry operations.\n", ans);
	}
	return 0;
}
