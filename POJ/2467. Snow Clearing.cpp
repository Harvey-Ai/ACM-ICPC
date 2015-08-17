/*
Description

As the days become shorter and the nights become longer we turn our thoughts to snow clearing. Due to budget cuts, the Big Noisy City has exactly one snow plow. The plow can clear exactly one lane of a road in a single pass. Whenever there is snow on the ground, the plow departs from its hangar and tours the city, plowing as it goes. What is the minimum time that the plow needs to clear every lane of every road?
Input

The first line of input contains two integers: the x,y coordinates of the hangar (in metres). Up to 100 lines follow. Each gives the coordinates (in metres) of the beginning and end of a street. All roads are perfectly straight, with one lane in each direction. The plow can turn any direction (including a U-turn) at any intersection, and can turn around at the end of any street. The plow travels at 20 km/h if it is plowing, and 50 km/h if the lane it is driving on has already been plowed. It is possible to reach all streets from the hangar.
Output

Your output should be the time, in hours and minutes, required to clear the streets and return to the hangar. Round to the nearest minute.
Sample Input

0 0
0 0 10000 10000
5000 -10000 5000 10000
5000 10000 10000 10000
Sample Output

3:55
*/


#include <stdio.h>
#include <math.h>
int main()
{
	double dis;
	int x1,x2,y1,y2,time;
	scanf("%d%d",&x1,&x2);
	dis=0;
	while (scanf("%d%d%d%d",&x1,&y1,&x2,&y2)!=EOF)
		dis+=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	time=dis/1000*2/20*60+0.5; 
	printf("%d:%0.2d\n",time/60,time%60);
	return 0;
}
