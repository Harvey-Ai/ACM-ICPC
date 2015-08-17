/*
Description

Fermat's theorem states that for any prime number p and for any integer a > 1, ap = a (mod p). That is, if we raise a to the pth power and divide by p, the remainder is a. Some (but not very many) non-prime values of p, known as base-a pseudoprimes, have this property for some a. (And some, known as Carmichael Numbers, are base-a pseudoprimes for all a.)

Given 2 < p ≤ 1000000000 and 1 < a < p, determine whether or not p is a base-a pseudoprime.

Input

Input contains several test cases followed by a line containing "0 0". Each test case consists of a line containing p and a.

Output

For each test case, output "yes" if p is a base-a pseudoprime; otherwise output "no".

Sample Input

3 2
10 3
341 2
341 3
1105 2
1105 3
0 0
Sample Output

no
no
yes
no
yes
yes

*/


#include <stdio.h>
bool check(long long a)
{
	int i;
	for(i=2;i*i<=a;i++)
	{
		if(a%i==0)
			return 1;
	}
	return 0;
}
int main()
{
	long long temp,a,p,tt;
	int cnt,ct;
	while(scanf("%lld%lld",&p,&a),a&&p)
	{
		if(check(p)==0)
		{
			printf("no\n");
			continue;
		}
		temp=a;cnt=1;
		while(cnt<p)
		{
			ct=1;tt=a;
			while(cnt+ct<=p)
			{
				cnt+=ct;
				ct+=ct;
				tt*=tt;
				tt%=p;
				temp*=tt;
				temp%=p;
			}
		}
		if(temp==a)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
