/*
Problem Description
Shaolin temple is very famous for its Kongfu monks.A lot of young men go to Shaolin temple every year, trying to be a monk there. The master of Shaolin evaluates a young man mainly by his talent on understanding the Buddism scripture, but fighting skill is also taken into account.
When a young man passes all the tests and is declared a new monk of Shaolin, there will be a fight , as a part of the welcome party. Every monk has an unique id and a unique fighting grade, which are all integers. The new monk must fight with a old monk whose fighting grade is closest to his fighting grade. If there are two old monks satisfying that condition, the new monk will take the one whose fighting grade is less than his.
The master is the first monk in Shaolin, his id is 1，and his fighting grade is 1,000,000,000.He just lost the fighting records. But he still remembers who joined Shaolin earlier, who joined later. Please recover the fighting records for him.
 

Input
There are several test cases.
In each test case:
The first line is a integer n (0 <n <=100,000),meaning the number of monks who joined Shaolin after the master did.(The master is not included).Then n lines follow. Each line has two integer k and g, meaning a monk's id and his fighting grade.( 0<= k ,g<=5,000,000)
The monks are listed by ascending order of jointing time.In other words, monks who joined Shaolin earlier come first.
The input ends with n = 0.
 

Output
A fight can be described as two ids of the monks who make that fight. For each test case, output all fights by the ascending order of happening time. Each fight in a line. For each fight, print the new monk's id first ,then the old monk's id.
 

Sample Input
3
2 1
3 3
4 2
0
 

Sample Output
2 1
3 2
4 2

*/
