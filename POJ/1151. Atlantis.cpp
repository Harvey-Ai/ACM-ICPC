/*
Description

There are several ancient Greek texts that contain descriptions of the fabled island Atlantis. Some of these texts even include maps of parts of the island. But unfortunately, these maps describe different regions of Atlantis. Your friend Bill has to know the total area for which maps exist. You (unwisely) volunteered to write a program that calculates this quantity.
Input

The input consists of several test cases. Each test case starts with a line containing a single integer n (1 <= n <= 100) of available maps. The n following lines describe one map each. Each of these lines contains four numbers x1;y1;x2;y2 (0 <= x1 < x2 <= 100000;0 <= y1 < y2 <= 100000), not necessarily integers. The values (x1; y1) and (x2;y2) are the coordinates of the top-left resp. bottom-right corner of the mapped area. 
The input file is terminated by a line containing a single 0. Don't process it.
Output

For each test case, your program should output one section. The first line of each section must be "Test case #k", where k is the number of the test case (starting with 1). The second one must be "Total explored area: a", where a is the total explored area (i.e. the area of the union of all rectangles in this test case), printed exact to two digits to the right of the decimal point. 
Output a blank line after each test case.
Sample Input

2
10 10 20 20
15 15 25 25.5
0
Sample Output

Test case #1
Total explored area: 180.00 
*/


#include <stdio.h>
#include <algorithm>
using namespace std;
struct map
{
	double x1,x2,y;
	int tag;
}p[201];
double arr[201];
bool cmp(const map a,const map b)
{
	if(a.y<b.y)
		return 1;
	else
		return 0;
}
int main()
{
	double a,b,c,d,low,len,res;
	int i,j,n,l,f;
	l=1;
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n*2;i+=2)
		{
			scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
			p[i].x1=a;
			p[i].y=b;
			p[i].x2=c;
			p[i].tag=0;
			p[i+1].x1=a;
			p[i+1].y=d;
			p[i+1].x2=c;
			p[i+1].tag=1;
			arr[i]=a;
			arr[i+1]=c;
		}
		sort(&arr[0],&arr[n*2]);
		sort(&p[0],&p[2*n],cmp);
		res=0;
		for(i=1;i<2*n;i++)
		{
			f=0;
			len=(arr[i]-arr[i-1]);
			if(len==0)
				continue;
			for(j=0;j<2*n;j++)
				if(p[j].x1<=arr[i-1]&&p[j].x2>=arr[i])
				{
					if(p[j].tag==0)
					{	
						if(f==0)
							low=p[j].y;
						f++;
					}
					else
						f--;
					if(f==0)
						res+=(p[j].y-low)*len;
				}
		}
		printf("Test case #%d\n",l++);
        printf("Total explored area: %.2lf\n\n",res);
	}
	return 0;
}
