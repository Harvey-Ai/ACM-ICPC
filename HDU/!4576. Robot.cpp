/*
Problem Description
Michael has a telecontrol robot. One day he put the robot on a loop with n cells. The cells are numbered from 1 to n clockwise.




At first the robot is in cell 1. Then Michael uses a remote control to send m commands to the robot. A command will make the robot walk some distance. Unfortunately the direction part on the remote control is broken, so for every command the robot will chose a direction(clockwise or anticlockwise) randomly with equal possibility, and then walk w cells forward.
Michael wants to know the possibility of the robot stopping in the cell that cell number >= l and <= r after m commands.
 

Input
There are multiple test cases. 
Each test case contains several lines.
The first line contains four integers: above mentioned n(1≤n≤200) ,m(0≤m≤1,000,000),l,r(1≤l≤r≤n).
Then m lines follow, each representing a command. A command is a integer w(1≤w≤100) representing the cell length the robot will walk for this command.  
The input end with n=0,m=0,l=0,r=0. You should not process this test case.
 

Output
For each test case in the input, you should output a line with the expected possibility. Output should be round to 4 digits after decimal points.
 

Sample Input
3 1 1 2
1
5 2 4 4
1
2
0 0 0 0
 

Sample Output
0.5000
0.2500
*/

