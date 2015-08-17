/*
描述
A number of students sit in a circle facing their teacher in the center. Each student initially has an even number of pieces of candy. When the teacher blows a whistle, each student simultaneously gives half of his or her candy to the neighbor on the right. Any student, who ends up with an odd number of pieces of candy, is given another piece by the teacher. The game ends when all students have the same number of pieces of candy.
Write a program which determines the number of times the teacher blows the whistle and the final number of pieces of candy for each student from the amount of candy each child starts with.
输入
The input may describe more than one game. For each game, the input begins with the number N of students,followed by N (even) candy counts for the children counter-clockwise around the circle. The input ends with a student count of 0. Each input number is on a line by itself.
输出
For each game, output the number of rounds of the game followed by the amount of candy each child ends up with,both on one line.
样例输入
6
36
2
2
2
2
2
11
22
20
18
16
14
12
10
8
6
4
2
4
2
4
6
8
0
样例输出
15 14
17 22
4 8
提示
Notes:
The game ends in a finite number of steps because:
1. The maximum candy count can never increase.
2. The minimum candy count can never decrease.
3. No one with more than the minimum amount will ever decrease to the minimum.
4. If the maximum and minimum candy count are not the same, at least one student with the minimum amount must have their count increase
*/


#include <stdio.h>

int arr[10005];
int main()
{
	int n;
	int i;
	int ans, last;

	while(scanf("%d", &n), n)
	{
	for(i = 0;i < n;i++)
		scanf("%d", &arr[i]);

	ans = 0;
	while(1)
	{
		for(i = 0;i < n;i++)
			arr[i] += arr[i] % 2;
		for(i = 1;i < n;i++)
			if (arr[i] != arr[i - 1])
				break;
		if (i >= n)
			break;

		ans++;
		for(i = 0;i < n;i++)
			arr[i] /= 2;
		last = arr[n - 1];
		for(i = n - 1;i > 0;i--)
			arr[i] += arr[i - 1];
		arr[0] += last;
	}
	printf("%d %d\n", ans, arr[0]);
	}
	return 0;
}
