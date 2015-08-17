/*
Problem Description
Traditionally after the Local Contest, judges and contestants go to their favourite restaurant, Alfredos Pizza Restaurant. The contestants are really hungry after trying hard for five hours. To get their pizza as quickly as possible, they just decided to order one big pizza for all instead of several small ones. They wonder whether it is possible to put the big rectangular pizza on the surface of the round table such that it does not overhang the border of the table. Write a program that helps them!
 

Input
The input file contains several test cases. Each test case starts with an integer number r, the radius of the surface of the round table the contestants are sitting at. Input is terminated by r=0. Otherwise, 1 ≤ r ≤ 1000. Then follow 2 integer numbers w and l specifying the width and the length of the pizza, 1 ≤ w ≤ l ≤ 1000. 
 

Output
Output for each test case whether the ordered pizza will fit on the table or not. Adhere to the format shown in the sample output. A pizza which just touches the border of the table without intersecting it is considered fitting on the table, see example 3 for clarification. 
 

Sample Input
38 40 60
35 20 70
50 60 80
0
 

Sample Output
Pizza 1 fits on the table.
Pizza 2 does not fit on the table.
Pizza 3 fits on the table.
*/
#include <stdio.h>
int main()
{
    int r,w,h,l;
    l=1;
    while(scanf("%d",&r),r)
    {
        scanf("%d%d",&h,&w);
        r*=2;
        if(r*r>=w*w+h*h)
            printf("Pizza %d fits on the table.\n",l++);
        else
            printf("Pizza %d does not fit on the table.\n",l++);
    }
    return 0;
}
