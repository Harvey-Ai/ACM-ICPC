/*
Description

两只青蛙在网上相识了，它们聊得很开心，于是觉得很有必要见一面。它们很高兴地发现它们住在同一条纬度线上，于是它们约定各自朝西跳，直到碰面为止。可是它们出发之前忘记了一件很重要的事情，既没有问清楚对方的特征，也没有约定见面的具体位置。不过青蛙们都是很乐观的，它们觉得只要一直朝着某个方向跳下去，总能碰到对方的。但是除非这两只青蛙在同一时间跳到同一点上，不然是永远都不可能碰面的。为了帮助这两只乐观的青蛙，你被要求写一个程序来判断这两只青蛙是否能够碰面，会在什么时候碰面。 
我们把这两只青蛙分别叫做青蛙A和青蛙B，并且规定纬度线上东经0度处为原点，由东往西为正方向，单位长度1米，这样我们就得到了一条首尾相接的数轴。设青蛙A的出发点坐标是x，青蛙B的出发点坐标是y。青蛙A一次能跳m米，青蛙B一次能跳n米，两只青蛙跳一次所花费的时间相同。纬度线总长L米。现在要你求出它们跳了几次以后才会碰面。 
Input

输入只包括一行5个整数x，y，m，n，L，其中x≠y < 2000000000，0 < m、n < 2000000000，0 < L < 2100000000。
Output

输出碰面所需要的跳跃次数，如果永远不可能碰面则输出一行"Impossible"
Sample Input

1 2 3 4 5
Sample Output

4
*/


#include <stdio.h>

long long gcd(long long a, long long b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

//（x+kb,y-ka）,(x,y)
void extgcd(long long a,long long b,long long *d,long long *x,long long *y)
{
	if(!b)
	{	
		*d=a;	*x=1;	*y=0;
	}
	else
	{
		extgcd(b,a%b,d,y,x);
		*y-=(*x)*(a/b);
	}
}

int main()
{
	long long p1, v1, p2, v2, l;
	long long t, disv, dist, td;
	long long temp;
	long long a, b, d;
	long long x, y;

	while(scanf("%lld %lld %lld %lld %lld", &p1, &p2, &v1, &v2, &l) != EOF)
	{
		while(p1 >= l)
			p1 -= l;
		while(p2 >= l)
			p2 -= l;
		if (v1 < v2)
		{
			temp = v1;
			v1 = v2;
			v2 = temp;

			temp = p1;
			p1 = p2;
			p2 = temp;
		}
		if (p1 > p2)
			dist = l - p1 + p2;
		else
			dist = p2 - p1;
		disv = v1 - v2;

		if (disv == 0)
		{
			if (dist != 0)
				printf("Impossible\n");
			else
				printf("0\n");
			continue;
		}

	//	printf("%lld %lld %lld %lld\n", p1, p2, l, dist);
		// disv * x +  (-y) * l = dist
		if (dist % gcd(disv, l) != 0)
		{
			printf("Impossible\n");
			continue;
		}

		extgcd(disv, l, &d, &a, &b);
//		printf("%lld\n", disv * a - l * b);
	//	printf("%lld %lld %lld %lld %lld %lld\n",disv, l, a, b, disv * a + l * b, d);
		x = a; y = b;
		x *= dist / d;
		y *= dist / d;
		x -= (x / (l / d)) * (l / d);
		while (x <= 0)
			x += l / d;

		printf("%lld\n", x);
	}
	return 0;
}
