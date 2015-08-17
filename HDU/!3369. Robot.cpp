/*
Problem Description
An intelligent robot decided to learn a new language which has many words. In the i-th day the robot could memorize i^k (the k-th power of i) words. The exception is, on Saturday and Sunday, the robot will do some sports instead of learning the boring language. For example, if the first day is Wednesday and k = 2, the number of words the robot memorized each day is 1, 4, 9, 0, 0, 36, 49... 
And n days passed. Do you know how many words the robot has memorized? The answer may be huge, just output the remainder after divided by 1000000007.
 

Input
The first line contains an integer T (T<=20) indicating the number of test cases.
T*2 lines follows. the first line of each test case contains a string(Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday) indicating the first day after the robot decided to learn a new language.
The second line contains two integers n (1<=n<=1000000000) and k (1<=k<=10).
 

Output
For each test case, print the case number and the answer in a single line.
Please follow the format of the sample output.
 

Sample Input
3
Monday
10 1
Wednesday
7 2
Saturday
3 10
 

Sample Output
Case 1: 42
Case 2: 99
Case 3: 59049
*/

