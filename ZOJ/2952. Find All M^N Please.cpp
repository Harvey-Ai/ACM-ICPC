/*
Recently, Joey has special interest in the positive numbers that could be represented as M ^ N (M to the power N), where M and N are both positive integers greater than or equal to 2. For example, 4, 8, 9 and 16 are first four such numbers, as 4 = 2 ^ 2, 8 = 2 ^ 3, 9 = 3 ^ 2, 16 = 2 ^ 4. You are planning to give Joey a surprise by giving him all such numbers less than 2 ^ 31 (2147483648). List them in ascending order, one per line.

Sample Output

4
8
9
16
25
27
32
|
| <-- a lot more numbers
|
1024
1089
1156
1225
1296
1331
|
|
|

*/

#include <stdio.h>
#include <algorithm>
using namespace std;
long long arr[100000];
int main()
{
	long long temp;
	int i,r;
	r=0;
	for(i=2;i<46341;i++)
	{
		temp=i*i;
		while(temp<2147483648)
		{
			arr[r++]=temp;
			temp*=i;
		}
	}
	sort(&arr[0],&arr[r]);
	printf("%lld\n",arr[0]);
	for(i=1;i<r;i++)
	{
		if(arr[i]!=arr[i-1]) printf("%lld\n",arr[i]);
	}
	return 0;
}
