/*
Description

A computer programmer lives in a street with houses numbered consecutively (from 1) down one side of the street. Every evening she walks her dog by leaving her house and randomly turning left or right and walking to the end of the street and back. One night she adds up the street numbers of the houses she passes (excluding her own). The next time she walks the other way she repeats this and finds, to her astonishment, that the two sums are the same. Although this is determined in part by her house number and in part by the number of houses in the street, she nevertheless feels that this is a desirable property for her house to have and decides that all her subsequent houses should exhibit it. 
Write a program to find pairs of numbers that satisfy this condition. To start your list the first two pairs are: (house number, last number): 
         6         8

        35        49

Input

There is no input for this program.
Output

Output will consist of 10 lines each containing a pair of numbers, in increasing order with the last number, each printed right justified in a field of width 10 (as shown above).
Sample Input

Sample Output

         6         8
        35        49
*/


#include<stdio.h>
#include <math.h>
int main()
{
	double k;
	long i,t,cnt;
	printf("%10d%10d\n%10d%10d\n",6,8,35,49);
	cnt=0;
	k=sqrt(2);
	for(i=36;cnt<8;i++)
	{
		t=k*i;
		if(i*i*2-t*t==t)
		{
			printf("%10ld%10ld\n",i,t);
			cnt++;
		}
	}
	return 0;
}
