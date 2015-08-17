/*
题目描述:
百度计划开发一个在线的健康专家系统,帮助用户足不出户就能初步了解自己所患的疾病,
并以此向用户推荐适合的医院就诊。经过对海量数据的分析,百度提取出了若干表征疾病性
状的特征,并把每种疾病是否符合某项特征都进行了标记,最终得到如下数据表格:
		
		疾病名称			A0			A1		。。 An	
		D0				Yes			Yes			Yes
		D1				No 			Probably	No
		.....			...			...			...
		Dm-1			Probably	No			No
		
其中,D0,D1,...,Dm-1 表示疾病名称,A0,A1,..., An-1 表示疾病的特征。m、n 均为正整数且 m < 4096,n < 128。特征的取值为 Yes(符合该项特征), Probably(有可能符合该项特征)或 No(不符合该项特征)。
这个专家系统被命名为 i-Doctor,因为它的工作方式很人性化,就像医院的专家一样通过
与病人的一问一答来得出诊断。每当开始一个诊断时,i-Doctor 首先提问:”你是否感觉
到有 A 症状?” 其中,A 为一疾病特征。用户依据自己的感觉回答。不幸的是,有时候病
人对自己是否有 A 症状不能肯定,甚至会给出错误的回答。统计表明,病人的回答及置信度
如下
		Yes 			0.95
		Probably Yes	0.90
		Probably No		0.90
		No				0.95
		Don't know		 -

注意:每个病人在诊断之前患有一种(且仅一种)确定的疾病,且该疾病保证存在于上述疾
病数据库中。现在,请你编写一个程序来让 i-Doctor 开始工作。
交互:
你的程序应当读写标准输入输出,以便与测试库交互。交互方式如下:
首先,你的程序(doctor)应从标准输入读取疾病特征表。第一行是两个正整数 m 和 n,表
示疾病的种类数和特征的种类数。m 和 n 之间以一个空格 隔开。接下来共有 m 行,其中每一行描述一种疾病,格式为:
疾病名称 特征值 0 特征值 1 ... 特征值 n-1
开头的字符串为疾病名称,长度不超过 7 字节;一个空格之后依次是各特征值,取值为英
文字母 Y 或 N 或 P,分别表示 Yes、No 和 Probably。相邻特征值以一个空格隔开。
接下来,你的程序可以向病人(patient)提问,提问方式为在标准输出上打印一行,格式
为:Do you feel Ai? 其中 Ai 表示特征特 i。 此后,你的程序应当从标准输入读取病人的回答。病人每次的回答也为一行,内容为 Yes、Probably yes、Probably no、No 和 Don’t know 之一。如此一问一答,直到你的程序诊断出病人所患疾病,此时应在标准输出上打印一行:I think of Dj! 其中 Dj 为此疾病名称。如果无法确诊,你的程序可以在标准输出上打印一行:Give up. 表示你放弃诊断该病人。
注意:很快你将看到,放弃诊断总比错误的诊断要好。
在确诊或放弃后,你的程序应自行终止。程序举例:
下面是一个示例程序(省略了 include),它能正确的与测试库进行交互,尽管它的得分可
能不高:
int main()
{
int m, n;
char name[10], line[256];
char table[4096][128][2];
int i, j, q;
srand(time(0));
scanf(“%d %d\n”, &m, &n);
for(i = 0; i < m; i++)
{
2scanf(“%s”, name);
for(j = 0; j < n; j++)
scanf(“%s”, table[j]);
fgetc(stdin); // consume ‘\n’
}
for(q = 0; q < 4; q++)
{
printf(“Do you feel A%d?\n”, rand() % n);
fflush(stdout); // Important 
fgets(line, sizeof(line), stdin);
}
if(rand() % 3 == 0)
printf(“I think of D%d!\n”, rand() % m);
else
printf(“Give up.\n”);
fflush(stdout); // Important 
return 0;
}
注意,
你的程序应当像上面的程序一样,在每次输出后立即执行 fflush(stdout)语句,使输出的
内容立即被送入测试库(而不是留在输出缓冲区中)。另外,你的程序应能独立编译,不能
依赖于任何其他外部文件(包括测试库)。
*/


#include <stdio.h>
#include <string.h>

char table[5000][128][2];

int check(int k, int c, char *str)
{
	int a1, a2;
	a1 = -1;
	if (strcmp(str, "Yes") == 0)
		a1 = 0;
	else if (strcmp(str, "Probably yes") == 0)
		a1 = 1;
	else if (strcmp(str, "Probably no") == 0)
		a1 = 2;
	else if (strcmp(str, "No") == 0)
		a1 = 3;
	
	a2 = -1;
	if (strcmp(table[k][c], "Y") == 0)
		a2 = 0;
	else if (strcmp(table[k][c], "P") == 0)
		a2 = 1;
	else 	if (strcmp(table[k][c], "N") == 0)
		a2 = 3;
	if (a1 != -1 && a2 != -1 && (a1 == a2 || a2 == 1))
		return 1;
	return 0;
}

int main()
{
    int m, n;
    char name[5000][10], line[256];
    int i, j, q;
    int res;
    int leftN;
    int left[5000];


    scanf("%d %d\n", &m, &n);
    for(i = 0; i < m; i++)
    {
        scanf("%s", name[i]);
        for(j = 0; j < n; j++)
            scanf("%s", table[i][j]);
        fgetc(stdin); /* consume '\n' */
    }
    
    for(i = 0;i < m;i++)
    	left[i] = 1;
    leftN = m;
    for(q = 0; q < n; q++)
    {
        printf("Do you feel A%d?\n", q);
        fflush(stdout); /* Important */
        fgets(line, sizeof(line), stdin);
        for(i = 0;i < m;i++)
        	if (left[i])
        		if (!check(i, q, line))
        		{
        			left[i] = 0;
        			leftN--;
        		}
        if (leftN == 1)
        	break;
    }

	if (leftN == 1)
		for(i = 0;i < m;i++)
			if (left[i])
			{
				res = i;
				break;
			}
				
    if(leftN == 1)
        printf("I think of %s!\n", name[res]);
    else
        printf("Give up.\n");
    fflush(stdout); /* Important */

    return 0;
}
