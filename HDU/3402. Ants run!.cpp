/*
Problem Description
Professor Yang likes to play with ants when he is free.
This time, Professor Yang caught several ants after finishing his lecture for freshmen. At the beginning of the game, he puts N ants around a plate and numbers them in clockwise order. The ants are so obedient that they run clockwise under the guide of Professor Yang on the boundary of the plate which is a circle. At first the distances of every two adjacent ants are the same around the boundary of the circle. When one ant catches up with its previous ant, the game is over. Knowing the speed of ants, Professor Yang wants you to help him to change the order of the ants to make the game last longer.
 

Input
The first line of the input is T (no more than 100), which stands for the number of test cases you need to solve.
Each test case begins with N and R, representing the number of ants participating the game is N ( N <= 100000)and the radius of the circle is R(R <= 100000) cm. The next line lists N integers and the i-th number is the speed (cm/s) of the i-th ant in clockwise direction. All these N numbers are positive integer not larger than 1000.
 

Output
If the game can last forever, print “Inf” in a single line, otherwise please output the longest time in seconds each game can last, which should be printed accurately rounded to three decimals.
 

Sample Input
2
3 1
1 1 1
2 1
1 2
 

Sample Output
Inf
3.142
*/

#include <stdio.h>
#include <stdlib.h>
#define pi 3.1415926
#define N 100005

int cmp(const void *a, const void *b)
{
    int aa = *(int *)(a);
    int bb = *(int *)(b);
    return aa - bb;
}

int main()
{
    int arr[N];
    int i, min, max, n, ncase;
    double r, dis;
    scanf("%d", &ncase);
    while(ncase--)
    {
        scanf("%d %lf", &n, &r);
        dis = 2 * pi * r / n;

        for(i = 0;i < n;i++)
            scanf("%d", &arr[i]);

        qsort(arr, n, sizeof(arr[0]), cmp);

        max = 0;
        for(i = 1;i < n;i++)
            if (arr[i] - arr[i - 1] > max)
                max = arr[i] - arr[i - 1];
                
        if (max == 0)
            printf("Inf\n");
        else
            printf("%.3lf\n", dis / max); 
    }
    return 0;
}
