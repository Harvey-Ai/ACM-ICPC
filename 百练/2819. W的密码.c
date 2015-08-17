/*
描述
加密一条信息需要三个整数码, k1, k2 和 k3。字符[a-i] 组成一组, [j-r] 是第二组, 其它所有字符 ([s-z] 和下划线)组成第三组。 在信息中属于每组的字符将被循环地向左移动ki个位置。 每组中的字符只在自己组中的字符构成的串中移动。解密的过程就是每组中的字符在自己所在的组中循环地向右移动ki个位置。 
例如对于信息 the_quick_brown_fox 以ki 分别为 2, 3 和 1蔼进行加密。加密后变成 _icuo_bfnwhoq_kxert。下图显示了右旋解密的过程。 



观察在组[a-i]中的字符，我们发现{i,c,b,f,h,e}出现在信息中的位置为{2,3,7,8,11,17}。当k1=2右旋一次后, 上述位置中的字符变成{h,e,i,c,b,f}。下表显示了经过所有第一组字符旋转得到的中间字符串，然后是所有第二组，第三组旋转的中间字符串。在一组中变换字符将不影响其它组中字符的位置。



所有输入字符串中只包含小写字母和下划线(_)。所有字符串最多有偿服务0个字符。ki 是1-100之间的整数。
输入
输入包括一到多组数据。每个组前面一行包括三个整数 k1, k2 和 k3，后面是一行加密信息。输入的最后一行是由三个0组成的。
输出
对于每组加密数据，输出它加密前的字符串。
样例输入
2 3 1
_icuo_bfnwhoq_kxert
1 1 1
bcalmkyzx
3 7 4
wcb_mxfep_dorul_eov_qtkrhe_ozany_dgtoh_u_eji
2 4 3
cjvdksaltbmu
0 0 0

样例输出
the_quick_brown_fox
abcklmxyz
the_quick_brown_fox_jumped_over_the_lazy_dog
ajsbktcludmv
*/


#include <stdio.h>

char group[3][100];
int pos[3][100];
char res[100];

int main()
{
	int i;
	int k1, k2, k3;
	int num1, num2, num3;
	char str[500];
	while(scanf("%d %d %d", &k1, &k2, &k3), k1 || k2 || k3)
	{
		scanf("%s", str);
		num1 = num2 = num3 = 0;
		for(i = 0;str[i] != '\0';i++)
		{
			if (str[i] >= 'a' && str[i] <= 'i')
			{
				pos[0][num1] = i;
				group[0][num1++] = str[i];
			}
			else if (str[i] >= 'j' && str[i] <= 'r')
			{
				pos[1][num2] = i;
				group[1][num2++] = str[i];
			}
			else
			{
				pos[2][num3] = i;
				group[2][num3++] = str[i];
			}
		}

		for(i = 0;i < num1;i++)
			res[pos[0][(i + k1 + num1) % num1]] = group[0][i];
		for(i = 0;i < num2;i++)
			res[pos[1][(i + k2 + num2) % num2]] = group[1][i];
		for(i = 0;i < num3;i++)
			res[pos[2][(i + k3 + num3) % num3]] = group[2][i];

		for(i = 0;str[i] != '\0';i++)
			putchar(res[i]);
		putchar('\n');
	}
	return 0;
}
