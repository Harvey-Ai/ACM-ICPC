/*
Description

Professor Octastichs has invented a new programming language, Smeech. An expression in Smeech may be a positive or negative integer, or may be of the form (p e1 e2) where p is a real number between 0 and 1 (inclusive) and e1 and e2 are Smeech expressions. The value represented by a Smeech expression is as follows:

An integer represents itself
With probability p, (p e1 e2) represents x + y where x is the value of e1 and y is the value of e2; otherwise it represents x - y.
Given a Smeech expression, what is its expected value?

Input

Input consists of several Smeech expressions, one per line, followed by a line containing ().

Output

For each expression, output its expected value to two decimal places.

Sample Input

7
(.5 3 9)
()
Sample Output

7.00
3.00
*/

#include <iostream>
using namespace std;
int flag;
double cla()
{
	double p,a,b;
	char c;
	c=cin.peek();
	if(c!='(')
	{
		scanf("%lf",&a);
		return a;
	}
	else
		getchar();
	c=cin.peek();
	if(c==')')
	{
		flag=0;
		return -1;
	}
	if(c=='(')
		p=cla();
	else
		scanf("%lf",&p);
	getchar();
	c=cin.peek();
	if(c=='(')
		a=cla();
	else
		scanf("%lf",&a);
	getchar();
	c=cin.peek();
	if(c=='(')
		b=cla();
	else
		scanf("%lf",&b);
	getchar();
	return (b*(2*p-1)+a);
}
int main()
{
	double res;
	flag=1;
	while(1)
	{
		res=cla();
		if(flag)
		{
			getchar();
			printf("%.2lf\n",res);
		}
		else
			break;
	}
	return 0;
}
