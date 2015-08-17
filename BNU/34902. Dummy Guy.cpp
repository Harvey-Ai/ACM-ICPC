/*
Every year students of our university participate in Regional Contest in Saint Petersburg. Train journeys from Yekaterinburg to Saint Petersburg make students very thirsty, so they usually take a lot of drinks with them. But the director of Institute of Mathematics and Computer Sciences doesn’t like when students carry all these bottles. So the students try to hide their bottles from the director. The Psych Up team invented a special device for that: a dummy guy.
The very first journey showed that the dummy guy can hardly hide two bottles. So you have decided to make a new dummy guy. You have n bottles that can be considered as cylinders of a unit radius. At first you want to draw a circle and place all your bottles inside it so that each of the bottle bottoms touches the circle. What is the minimum radius of such circle?
Input
The only line contains an integer n that is the number of bottles (1 ≤ n ≤ 10).
Output
Output the minimum radius of a circle with an absolute or relative error not exceeding 10−6.
Sample Input
input
2
output
2
*/

#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

#define PI 3.1415926535898

int main()
{
	int n;
	cin >> n;
	switch(n)
	{
		case 1: cout << 1 << endl;break;
		case 2: cout << 2 << endl;break;
		case 3: printf("%.7lf\n", 2 / sqrt(3.0) + 1);break;
		case 4: printf("%.7lf\n", sqrt(2.0) + 1);break;
		case 5: printf("%.7lf\n", 2 * sin(PI * 3 / 10) / sin(PI * 2 / 5) + 1);break;
		case 6: printf("3\n");break;
		case 7: printf("%.7lf\n", 2 * sin(PI * 5 / 14) / sin(PI * 2 / 7) + 1);break; 
		case 8: printf("%.7lf\n", 2 * sin(PI * 6 / 16) / sin(PI * 2 / 8) + 1);break;
		case 9: printf("%.7lf\n", 2 * sin(PI * 7 / 18) / sin(PI * 2 / 9) + 1);break;
		case 10: printf("%.7lf\n", 2 * sin(PI * 8 / 20) / sin(PI * 2 / 10) + 1);break;   
	}
	return 0;
}
