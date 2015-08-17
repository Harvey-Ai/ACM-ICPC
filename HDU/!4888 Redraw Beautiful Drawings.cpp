/*
Problem Description
Alice and Bob are playing together. Alice is crazy about art and she has visited many museums around the world. She has a good memory and she can remember all drawings she has seen.

Today Alice designs a game using these drawings in her memory. First, she matches K+1 colors appears in the picture to K+1 different integers(from 0 to K). After that, she slices the drawing into grids and there are N rows and M columns. Each grid has an integer on it(from 0 to K) representing the color on the corresponding position in the original drawing. Alice wants to share the wonderful drawings with Bob and she tells Bob the size of the drawing, the number of different colors, and the sum of integers on each row and each column. Bob has to redraw the drawing with Alice's information. Unfortunately, somtimes, the information Alice offers is wrong because of Alice's poor math. And sometimes, Bob can work out multiple different drawings using the information Alice provides. Bob gets confused and he needs your help. You have to tell Bob if Alice's information is right and if her information is right you should also tell Bob whether he can get a unique drawing.
 

Input
The input contains mutiple testcases.

For each testcase, the first line contains three integers N(1 ≤ N ≤ 400) , M(1 ≤ M ≤ 400) and K(1 ≤ K ≤ 40).
N integers are given in the second line representing the sum of N rows.
M integers are given in the third line representing the sum of M columns.

The input is terminated by EOF.
 

Output
For each testcase, if there is no solution for Bob, output "Impossible" in one line(without the quotation mark); if there is only one solution for Bob, output "Unique" in one line(without the quotation mark) and output an N * M matrix in the following N lines representing Bob's unique solution; if there are many ways for Bob to redraw the drawing, output "Not Unique" in one line(without the quotation mark).
 

Sample Input
2 2 4
4 2
4 2  
4 2 2
2 2 5 0
5 4
1 4 3
9
1 2 3 3
 

Sample Output
Not Unique
Impossible
Unique
1 2 3 3

*/

