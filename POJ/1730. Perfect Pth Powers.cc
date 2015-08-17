/*
Description

We say that x is a perfect square if, for some integer b, x = b2. Similarly, x is a perfect cube if, for some integer b, x = b3. More generally, x is a perfect pth power if, for some integer b, x = bp. Given an integer x you are to determine the largest p such that x is a perfect pth power.
Input

Each test case is given by a line of input containing x. The value of x will have magnitude at least 2 and be within the range of a (32-bit) int in C, C++, and Java. A line containing 0 follows the last test case.
Output

For each test case, output a line giving the largest integer p such that x is a perfect pth power.
Sample Input

17
1073741824
25
0
Sample Output

1
30
2

*/



#include <iostream>
#include <math.h>
using namespace std;
#define zerro 1e-6
int main()
{
	long long n;
	int i,b,max,k;
	while(cin>>n,n)
	{
		if(n<0)
			k=2;
		else
			k=1;
		if(n<0)
			n=-n;
		i=1;max=1;b=2;
		while(b>1)
		{
			i+=k;
			b=int(pow(n,1.0/i)+zerro);
			if(fabs(pow(b,i)-n)<zerro)
				max=i;
		}
		cout<<max<<endl;
	}
	return 0;
}
