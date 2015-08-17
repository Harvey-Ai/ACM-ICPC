/*
题目描述：
    John von Neumann, b. Dec. 28, 1903, d. Feb. 8, 1957, was a Hungarian-American mathematician who made important contributions to the foundations of mathematics, logic, quantum physics, meteorology, science, computers, and game theory. He was noted for a phenomenal memory and the speed with which he absorbed ideas and solved problems. In 1925 he received a B.S. diploma in chemical engineering from Zurich Institute and in 1926 a Ph.D. in mathematics from the University of Budapest, His Ph.D. dissertation on set theory was an important contributions to the subject.
    At the age of 20, von Neumann proposed a new definition of ordinal numbers that was universally adopted. While still in his twenties, he made many contributions in both pure and applied mathematics that established him as a mathematician of unusual depth. His Mathematical Foundation of Quantum Mechanics (1932) built a solid framework for the new scientific discipline.
    During this time he also proved the mini-max theorem of GAME THEORY. He gradually expanded his work in game theory, and with coauthor Oskar Morgenstern he wrote Theory of Games and Economic Behavior (1944).
    There are some numbers which can be expressed by the sum of factorials. For example 9, 9 = 1! + 2! + 3! . Dr. von Neumann was very interested in such numbers. So, he gives you a number n, and wants you to tell whether or not the number can be expressed by the sum of some factorials.
Well, it is just a piece of case. For a given n, you will check if there are some xi, and let n equal to Σt (上标) i=1（下标） xi! (t≥1, xi≥0, xi = xj <==> i = j)
           t
     即 Σ  xi! (t≥1, xi≥0, xi = xj <==> i = j)
          i=1
    If the answer is yes, say "YES"; otherwise, print out "NO".
输入：
    You will get a non-negative integer n (n≤1,000,000) from input file.
输出：
    For the n in the input file, you should print exactly one word ("YES" or "NO") in a single line. No extra spaces are allowed.
样例输入：
9
2
样例输出：
YES
YES
*/


#include <iostream>
#include <cstring>
using namespace std;

int flag[1000005];
int factorial[50];

int main()
{
	int a, i, j;

	factorial[0] = 1;
	for(i = 1;i < 11;i++)
		factorial[i] = factorial[i - 1] * i;

//	cout << "fa" << endl;
	memset(flag, 0, sizeof(flag));
	flag[0] = 1;
	for(i = 0;i < 11;i++)
		for(j = 100000;j >= factorial[i];j--)
			if (flag[j - factorial[i]])
				flag[j] = 1;
	
//	cout << "fa2" << endl;
			
	while(cin >> a)
	{
		if (flag[a])
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
