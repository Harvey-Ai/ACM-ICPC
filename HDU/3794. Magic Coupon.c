/*
Problem Description
The magic shop in Mars is offering some magic coupons. Each coupon has an integer N printed on it, meaning that when you use this coupon with a product, you may get N times the value of that product back! What is more, the shop also offers some bonus product for free. However, if you apply a coupon with a positive N to this bonus product, you will have to pay the shop N times the value of the bonus product... but hey, magically, they have some coupons with negative N's!
For example, given a set of coupons {1 2 4 -1}, and a set of product values {7 6 -2 -3} (in Mars dollars M)whereanegativevaluecorrespondstoabonusproduct.Youcanapplycoupon3(withNbeing4)toproduct1(withvalueM7) to get M28back;coupon2toproduct2togetM12 back; and coupon 4 to product 4 to get M3back.Ontheotherhand,ifyouapplycoupon3toproduct4,youwillhavetopayM12 to the shop.
Each coupon and each product may be selected at most once. Your task is to get as much money back as possible.
 

Input
Your program must read test cases from standard input.
The input file consists of several test cases. For each case, the first line contains the number of coupons NC, followed by a line with NC coupon integers. Then the next line contains the number of products NP, followed by a line with NP product values. Here 1<= NC, NP <= 10^6, and it is guaranteed that all the numbers will not exceed 10^7.
The input is finished by a negative NC.
 

Output
For each test case, your program must output to standard output. Simply print in a line the maximum amount of money you can get back.
 

Sample Input
4
1 2 4 -1
4
7 6 -2 -3
4
3 2 6 1
3 
2 6 3
-1
 

Sample Output
43
49
*/


#include <iostream>
#include <algorithm>
using namespace std;

__int64 arr1[1000006], arr2[1000006];

int main()
{
	int i, j;
	int nc, np;
	__int64 res;
	
	while(scanf("%d", &nc), nc >= 0)
	{
		for(i = 0;i < nc;i++)
			scanf("%I64d", &arr1[i]);
	
		scanf("%d", &np);
		for(i = 0;i < np;i++)
			scanf("%I64d", &arr2[i]);

		sort(&arr1[0], &arr1[nc]);
		sort(&arr2[0], &arr2[np]);

		res = 0;
		for(i = 0,j = 0;i < nc && j < np && arr1[i] < 0 && arr2[j] < 0;i++, j++)
			res += arr1[i] * arr2[j];

		for(i = nc - 1,j = np - 1;i >= 0 && j >= 0 && arr1[i] > 0 && arr2[j] > 0;i--, j--)
			res += arr1[i] * arr2[j];

		printf("%I64d\n", res);
	}
	return 0;
}
