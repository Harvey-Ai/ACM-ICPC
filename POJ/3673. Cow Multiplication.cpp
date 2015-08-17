/*
Description

Bessie is tired of multiplying pairs of numbers the usual way, so she invented her own style of multiplication. In her style, A*B is equal to the sum of all possible pairwise products between the digits of A and B. For example, the product 123*45 is equal to 1*4 + 1*5 + 2*4 + 2*5 + 3*4 + 3*5 = 54. Given two integers A and B (1 ≤ A, B ≤ 1,000,000,000), determine A*B in Bessie's style of multiplication.

Input

* Line 1: Two space-separated integers: A and B.

Output

* Line 1: A single line that is the A*B in Bessie's style of multiplication.

Sample Input

123 45

Sample Output

54

*/


#include <stdio.h>
#include <string.h>
int main()
{
	char str1[20],str2[20];
	double res;
	int i,j,len1,len2;
	while(scanf("%s%s",str1,str2)!=EOF)
	{
		len1=strlen(str1);
		len2=strlen(str2);
		res=0;
		for(i=0;i<len1;i++)
			for(j=0;j<len2;j++)
				res+=(str1[i]-'0')*(str2[j]-'0');
		printf("%.0lf\n",res);
	}
	return 0;
}
