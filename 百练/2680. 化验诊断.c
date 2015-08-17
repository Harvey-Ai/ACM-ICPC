/*
描述
下表是进行血常规检验的正常值参考范围，及化验值异常的临床意义：


给定一张化验单，判断其所有指标是否正常，如果不正常，统计有几项不正常。化验单上的值必须严格落在正常参考值范围内，才算是正常。正常参考值范围包括边界，即落在边界上也算正常。
输入

输出
对于每组测试数据，输出一行。如果所有检验项目正常，则输出：normal；否则输出不正常的项的数目。
样例输入
2
female 4.5 4.0 115 37 200
male 3.9 3.5 155 36 301
样例输出
normal
3
*/


#include <stdio.h>
#include <string.h>

int main()
{
	int k;
	char sex[10];
	double arr[10];
	int i, un;
	scanf("%d", &k);

	while(k--)
	{
		scanf("%s", sex);
		for(i = 0;i < 5;i++)
			scanf("%lf", &arr[i]);
		un = 0;

		if (arr[0] < 4.0 || arr[0] > 10.0)
			un++;

		if (arr[1] < 3.5 || arr[1] > 5.5)
			un++;
		if (strcmp(sex, "female") == 0)
		{
			if (arr[2] < 110 ||arr[2] > 150)
				un++;
		}
		else if (arr[2] < 120 || arr[2] > 160)
			un++;

		if (strcmp(sex, "female") == 0)
		{
			if (arr[3] < 36 || arr[3] > 40)
				un++;
		}
		else if (arr[3] < 42 || arr[3] > 48)
			un++;

		if (arr[4] < 100 || arr[4] > 300)
			un++;
		if (un == 0)
			printf("normal\n");
		else
			printf("%d\n", un);
	}
	return 0;
}
