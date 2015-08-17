/*
题目描述:
百度公司在纳斯达克上市的股票代码是 bidu,度度熊为了制作股票价格的显示屏,希望在一个矩形液晶屏上显示”bidu”字样的图标。图标可以看作由一个 13 * 6 的矩形表格组成,其中每个单元格的尺寸以及颜色请参照下图,度度熊使用 a, b 两个参数来控制字体的粗细和大小,图中显示的是 a=1, b=2 的例子,占用 16*7 个单元格。

液晶屏的分辨率为 w * h,在摆放图标的时候,度度熊发现液晶屏有一个尺寸为 p * q 像素的损坏部分,其中损坏的像素称为坏点。坏点无法点亮,只能显示黑色。为了不影响显示效果,他决定在摆放图标时一定要满足下述条件:
1. 图标中所有橙色区域必须正常显示,也就是不可与坏点有交集,并且不会超出液晶屏的显示范围。
2. 图标及显示屏均不可翻转或旋转。
请你实现一个程序,帮助度度熊计算满足条件的图标摆放位置一共有多少种。
输入描述
输入包含一组数据。
第一行包含 8 个整数 w, h, a, b, s, t,p, q,以空格分割,表示液晶屏的宽(左右包含的像素数)为 w、液晶屏的高(上下包含的像素数)为 h、控制显示的两个参数为 a 和 b、坏点区域距左边 s 个像素、坏点区域距上边 t 个像素、坏点区域宽 p、坏点区域高 q。
输出描述
第一行包含一个整数,表示图标可以摆放的位置个数
样例输入
17 8 1 2 8 4 1 1
样例输出
1
提示
以最左上角的单元格坐标为(0,0),最右下角的单元格坐标为(16,7),那么坏格的坐标为(8,4)。图标以(0,0)为左上角,恰好可以放进液晶屏。
对于 40%的测试数据,0 < w, h ≤ 104;
对于 100%的测试数据,0 < w, h ≤ 109,b >a > 0,10a + 3b ≤ w,3a + 2b ≤ h,0 ≤ s < s + p ≤ w,0 ≤ t < t + q ≤ h。
*/

#include <iostream>
using namespace std;

struct line
{
	long long x;
	long long y;
	long long duan[2];
};
struct line heng[100], shu[100];
int shuN, hengN;

void init(int a, int b)
{
	shu[0].x = 0;
	shu[0].duan[0] = 0;
	shu[0].duan[1] = 2 * b + 3 * a - 1;

	shu[1].x = a + b;
	shu[1].duan[0] = a + b;
	shu[1].duan[1] = 2 * b + 3 * a - 1;

	shu[2].x = 3 * a + b;
	shu[2].duan[0] = b - a;
	shu[2].duan[1] = b - 1;

	shu[3].x = 3 * a + b;
	shu[3].duan[0] = b + a;
	shu[3].duan[1] = 2 * b + 3 * a - 1;

	shu[4].x = 5 * a + b;
	shu[4].duan[0] = b + a;
	shu[4].duan[1] = 2 * b + 3 * a - 1;

	shu[5].x = 6 * a + 2 * b;
	shu[5].duan[0] = 0;
	shu[5].duan[1] = 2 * b + 3 * a - 1;

	shu[6].x = 8 * a + 2 * b;
	shu[6].duan[0] = a + b;
	shu[6].duan[1] = 2 * b + 3 * a - 1;

	shu[7].x = 9 * a + 3 * b;
	shu[7].duan[0] = a + b;
	shu[7].duan[1] = 2 * b + 3 * a - 1;

	shuN = 8;

	heng[0].y = a + b;
	heng[0].duan[0] = a;
	heng[0].duan[1] = a + b - 1;

	heng[1].y = a + b;
	heng[1].duan[0] = 6 * a + b;
	heng[1].duan[1] = 6 * a + 2 * b - 1;

	heng[2].y = 2 * a + 2 * b;
	heng[2].duan[0] = a;
	heng[2].duan[1] = a + b - 1;

	heng[3].y =  2 * a + 2 * b;
	heng[3].duan[0] = 6 * a + b;
	heng[3].duan[1] = 6 * a + 2 * b - 1;

	heng[4].y = 2 * a + 2 * b;
	heng[4.duan[0] = 9 * a + 2 * b;
	heng[4].duan[1] = 9 * a + 3 * b - 1;

	hengN = 5;

}

int check(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3, long long x4, long long y4, long long s, long long t, long long p, long q)
{
	if (x1 >= s && x1 < s + p && y1 >= t && y1 < t + q)
		return 0;
	if (x2 >= s && x2 < s + p && y2 >= t && y2 < t + q)
		return 0;
	if (x3 >= s && x3 < s + p && y3 >= t && y3 < t + q)
		return 0;
	if (x4 >= s && x4 < s + p && y4 >= t && y4 < t + q)
		return 0;
	return 1;
}


int main()
{
	long long w, h, a, b, s, t, p, q;
	long long bw, bh;
	int i, j, k;
	long long res;
	struct line tempS[100], tempH[100];
	scanf("%lld %lld %lld %lld %lld %lld %lld %lld", &w, &h, &a, &b, &s, &t, &p, &q);

	init(a, b);

	bw = 10 * a + 3 * b;
	bh = 2 * b + 3 * a;

	res = 0;
	for(i = 0;i + bw <= w;i++)
		for(j = 0;j + bh <= h;j++)
		{
			for(k = 0;k < shuN;k++)
			{
				tempS[k].x = shu[k].x + i;
				tmepS[k].duan[0] = shu[k].duan[0] + j;
				tmepS[k].duan[1] = shu[k].duan[1] + j;
			}

			for(k = 0;k < hengN;k++)
			{
				tempH[k].x = heng[k].x + i;
				tmepH[k].duan[0] = heng[k].duan[0] + j;
				tmepH[k].duan[1] = heng[k].duan[1] + j;
			}
			for(l = 0;l < shuN;l++)
				if (check(tempS[l].x, tempS[l].duan[0], tempS[l].x + a - 1, tempS[l].duan[0], tempS[l].x, tempS[l].duan[1], tempS[l].x + a - 1, tempS[l].duan[1], s, t, q, p) == 0)
						break;

			if (l < shuN)
				continue;

			for(l = 0;l < hengN;l++)
				if (check(tmepH[l].duan[0], tmepH[l].y, tmepH[l].duan[0], tmepH[l].y + a - 1, tmepH[l].duan[1], tmepH[l].y, tmepH[l].duan[1], tmepH[l].y + a - 1, s, t, q, p) == 0)
						break;
			if (l < hengN)
				continue;

			res++;
		}

	printf("%ll\n", res);

	return 0;
}
