/*
Description

Now that the Loonie is hovering about par with the Greenback, you have decided to use your $1000 entrance scholarship to engage in currency speculation. So you gaze into a crystal ball which predicts the closing exchange rate between Canadian and U.S. dollars for each of the next several days. On any given day, you can switch all of your money from Canadian to U.S. dollars, or vice versa, at the prevailing exchange rate, less a 3% commission, less any fraction of a cent.

Assuming your crystal ball is correct, what's the maximum amount of money you can have, in Canadian dollars, when you're done?

Input

The input contains a number of test cases, followed by a line containing 0. Each test case begins with 0 < d ≤ 365, the number of days that your crystal ball can predict. d lines follow, giving the price of a U.S. dollar in Canadian dollars, as a real number.

Output

For each test case, output a line giving the maximum amount of money, in Canadian dollars and cents, that it is possible to have at the end of the last prediction, assuming you may exchange money on any subset of the predicted days, in order. 
Sample Input

3
1.0500
0.9300
0.9900
2
1.0500
1.1000
0
Sample Output

1001.60
1000.00
*/


#include<cstdio>
int main()
{
	double a,temp,maxc,maxd,tt;
	int i,n;
	while(scanf("%d",&n),n)
	{
		maxd=0;
		maxc=1000;
		for(i=0;i<n;i++)
		{
			scanf("%lf",&a);
			tt=maxc;
			temp =int(maxd*a*0.97*100.0)/100.0;
			if(temp>maxc)maxc=temp;
			temp =int(tt/a*0.97*100.0)/100.0;
			if(temp>maxd) maxd=temp;
		}
		printf("%.2lf\n",maxc);
	}
	return 0;
}
