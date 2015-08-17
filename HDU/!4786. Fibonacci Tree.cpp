/*
Problem Description
　　Coach Pang is interested in Fibonacci numbers while Uncle Yang wants him to do some research on Spanning Tree. So Coach Pang decides to solve the following problem:
　　Consider a bidirectional graph G with N vertices and M edges. All edges are painted into either white or black. Can we find a Spanning Tree with some positive Fibonacci number of white edges?
(Fibonacci number is defined as 1, 2, 3, 5, 8, ... )
 

Input
　　The first line of the input contains an integer T, the number of test cases.
　　For each test case, the first line contains two integers N(1 <= N <= 105) and M(0 <= M <= 105).
　　Then M lines follow, each contains three integers u, v (1 <= u,v <= N, u<> v) and c (0 <= c <= 1), indicating an edge between u and v with a color c (1 for white and 0 for black).
 

Output
　　For each test case, output a line “Case #x: s”. x is the case number and s is either “Yes” or “No” (without quotes) representing the answer to the problem.
 

Sample Input
2
4 4
1 2 1
2 3 1
3 4 1
1 4 0
5 6
1 2 1
1 3 1
1 4 1
1 5 1
3 5 1
4 2 1
 

Sample Output
Case #1: Yes
Case #2: No
*/
