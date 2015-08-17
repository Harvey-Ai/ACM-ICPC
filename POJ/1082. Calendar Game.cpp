/*
Description

Adam and Eve enter this year's ACM International Collegiate Programming Contest. Last night, they played the Calendar Game, in celebration of this contest. This game consists of the dates from January 1, 1900 to November 4, 2001, the contest day. The game starts by randomly choosing a date from this interval. Then, the players, Adam and Eve, make moves in their turn with Adam moving first: Adam, Eve, Adam, Eve, etc. There is only one rule for moves and it is simple: from a current date, a player in his/her turn can move either to the next calendar date or the same day of the next month. When the next month does not have the same day, the player moves only to the next calendar date. For example, from December 19, 1924, you can move either to December 20, 1924, the next calendar date, or January 19, 1925, the same day of the next month. From January 31 2001, however, you can move only to February 1, 2001, because February 31, 2001 is invalid. 

A player wins the game when he/she exactly reaches the date of November 4, 2001. If a player moves to a date after November 4, 2001, he/she looses the game. 

Write a program that decides whether, given an initial date, Adam, the first mover, has a winning strategy. 

For this game, you need to identify leap years, where February has 29 days. In the Gregorian calendar, leap years occur in years exactly divisible by four. So, 1993, 1994, and 1995 are not leap years, while 1992 and 1996 are leap years. Additionally, the years ending with 00 are leap years only if they are divisible by 400. So, 1700, 1800, 1900, 2100, and 2200 are not leap years, while 1600, 2000, and 2400 are leap years.
Input

The input consists of T test cases. The number of test cases (T ) is given in the first line of the input file. Each test case is written in a line and corresponds to an initial date. The three integers in a line, YYYY MM DD, represent the date of the DD-th day of MM-th month in the year of YYYY. Remember that initial dates are randomly chosen from the interval between January 1, 1900 and November 4, 2001.
Output

Print exactly one line for each test case. The line should contain the answer "YES" or "NO" to the question of whether Adam has a winning strategy against Eve. Since we have T test cases, your program should output totally T lines of "YES" or "NO".
Sample Input

3 
2001 11 3 
2001 11 2 
2001 10 3 
Sample Output

YES
NO
NO
*/


#include<stdio.h>
main()
{
    int t,y,m,d;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&y,&m,&d);
        if((m+d)%2==0 || ((m==9||m==11)&&d==30))
        {
            puts("YES");
        }
        else
        {
            puts("NO");
        }
    }
} 
