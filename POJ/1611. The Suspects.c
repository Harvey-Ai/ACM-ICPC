/*
Description

Severe acute respiratory syndrome (SARS), an atypical pneumonia of unknown aetiology, was recognized as a global threat in mid-March 2003. To minimize transmission to others, the best strategy is to separate the suspects from others. 
In the Not-Spreading-Your-Sickness University (NSYSU), there are many student groups. Students in the same group intercommunicate with each other frequently, and a student may join several groups. To prevent the possible transmissions of SARS, the NSYSU collects the member lists of all student groups, and makes the following rule in their standard operation procedure (SOP). 
Once a member in a group is a suspect, all members in the group are suspects. 
However, they find that it is not easy to identify all the suspects when a student is recognized as a suspect. Your job is to write a program which finds all the suspects.
Input

The input file contains several cases. Each test case begins with two integers n and m in a line, where n is the number of students, and m is the number of groups. You may assume that 0 < n <= 30000 and 0 <= m <= 500. Every student is numbered by a unique integer between 0 and n−1, and initially student 0 is recognized as a suspect in all the cases. This line is followed by m member lists of the groups, one line per group. Each line begins with an integer k by itself representing the number of members in the group. Following the number of members, there are k integers representing the students in this group. All the integers in a line are separated by at least one space. 
A case with n = 0 and m = 0 indicates the end of the input, and need not be processed.
Output

For each case, output the number of suspects in one line.
Sample Input

100 4
2 1 2
5 10 13 11 12 14
2 0 1
2 99 2
200 2
1 5
5 1 2 3 4 5
1 0
0 0
Sample Output

4
1
1
*/

#include <stdio.h>
#include <string.h>

int students[30005];
int getF(int id)
{
	int father = id;
	while(students[id] >= 0)
	{
		id = students[id];
		father = id;
	}
	return father;
}

void uion(int id1, int id2)
{
	int fA, fB;
	fA = getF(id1);
	fB = getF(id2);

	if (fA == fB)
		return;
	if (students[fA] < students[fB])
	{
		students[fA] += students[fB];
		students[fB] = fA;
	}
	else
	{
		students[fB] += students[fA];
		students[fA] = fB;
	}
}
int main()
{
	int i, k, a, b, m, n, res, ncase = 1;

	while(scanf("%d %d", &n, &m), m || n)
	{
		memset(students, -1, sizeof(students));

		for(i = 0;i < m;i++)
		{
			scanf("%d", &k);
			if (k > 0)
			{
				scanf("%d", &a);
				k--;
				while(k--)
				{
					scanf("%d", &b);
					uion(a, b);
				}
			}
		}

		res = getF(0);
		printf("%d\n", -students[res]);
	}
	return 0;
}
