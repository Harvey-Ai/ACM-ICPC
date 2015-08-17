/*
描述
a的立方 = b的立方 + c的立方 + d的立方为完美立方等式。例如12的立方 = 6的立方 + 8的立方 + 10的立方 。编写一个程序，对任给的正整数N (N≤100)，寻找所有的四元组(a, b, c, d)，使得a的立方 = b的立方 + c的立方 + d的立方，其中a,b,c,d 大于 1, 小于等于N。
输入
正整数N (N≤100)
输出
每行输出一个完美立方，按照a的值，从小到大依次输出。当两个完美立方等式中a的值相同，则依次按照b、c、d进行非降升序排列输出，即b值小的先输出、然后c值小的先输出、然后d值小的先输出。
样例输入
24
样例输出
Cube = 6, Triple = (3,4,5) 
Cube = 12, Triple = (6,8,10) 
Cube = 18, Triple = (2,12,16) 
Cube = 18, Triple = (9,12,15) 
Cube = 19, Triple = (3,10,18) 
Cube = 20, Triple = (7,14,17) 
Cube = 24, Triple = (12,16,20) 
*/


#include <iostream>
using namespace std;

int main()
{
	int buf[1000];
	int i, j, k, l;
	int n;
	for(i = 1;i < 101;i++)
		buf[i] = i * i * i;

	cin >> n;

	for(i = 1;i <= n;i++)
		for(j = 2;j <= n;j++)
			for(k = j;k <= n;k++)
				for(l = k;l <= n;l++)
					if (buf[i] == buf[j] + buf[k] + buf[l])
						cout << "Cube = " << i << ", Triple = (" << j << "," << k << "," << l << ")" << endl;
	return 0;
}
