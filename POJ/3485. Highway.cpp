/*
Description

Bob is a skilled engineer. He must design a highway that crosses a region with few villages. Since this region is quite unpopulated, he wants to minimize the number of exits from the highway. He models the highway as a line segment S (starting from zero), the villages as points on a plane, and the exits as points on S. Considering that the highway and the villages position are known, Bob must find the minimum number of exists such that each village location is at most at the distance D from at least one exit. He knows that all village locations are at most at the distance D from S.

Input

The program input is from a text file. Each data set in the file stands for a particular set of a highway and the positions of the villages. The data set starts with the length L (fits an integer) of the highway. Follows the distance D (fits an integer), the number N of villages, and for each village the location (x,y). The program prints the minimum number of exits.

White spaces can occur freely in the input. The input data are correct and terminate with an end of file.

Output

For each set of data the program prints the result to the standard output from the beginning of a line. An input/output sample is in the table below. There is a single data set. The highway length L is 100, the distance D is 50. There are 3 villages having the locations (2, 4), (50, 10), (70, 30). The result for the data set is the minimum number of exits: 1.

Sample Input

100
50
3
2 4
50 10
70 30
Sample Output

1
*/


#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
double p[10000][2];
struct dd
{
	double a,b;
}arr[10000];
bool cmp(const dd a,const dd b)
{
	return a.a<b.a;
}
int main()
{
	int i,res,n;
	double d,l,temp,pos;
	while(scanf("%lf",&l)!=EOF)
	{
		scanf("%lf%d",&d,&n);
		for(i=0;i<n;i++)
			scanf("%lf%lf",&p[i][0],&p[i][1]);
		d*=d;
		for(i=0;i<n;i++)
		{
			temp=sqrt(d-p[i][1]*p[i][1]);
			if(p[i][0]-temp<0)
				arr[i].a=0;
			else
				arr[i].a=p[i][0]-temp;
			if(p[i][0]+temp>l)
				arr[i].b=l;
			else
				arr[i].b=p[i][0]+temp;
		}
		sort(&arr[0],&arr[n],cmp);
		pos=-1;
		res=0;
		for(i=0;i<n;i++)
		{
			if(arr[i].a>pos)
			{
				res++;
				pos=arr[i].b;
			}
			else
			{
				if(arr[i].b<pos)
					pos=arr[i].b;
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
