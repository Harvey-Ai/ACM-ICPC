/*
Description

In the second year of the university somebody started a study on the romantic relations between the students. The relation "romantically involved" is defined between one girl and one boy. For the study reasons it is necessary to find out the maximum set satisfying the condition: there are no two students in the set who have been "romantically involved". The result of the program is the number of students in such a set.
Input

The input contains several data sets in text format. Each data set represents one set of subjects of the study, with the following description: 

the number of students 
the description of each student, in the following format 
student_identifier:(number_of_romantic_relations) student_identifier1 student_identifier2 student_identifier3 ... 
or 
student_identifier:(0) 

The student_identifier is an integer number between 0 and n-1 (n <=500 ), for n subjects.
Output

For each given data set, the program should write to standard output a line containing the result.
Sample Input

7
0: (3) 4 5 6
1: (2) 4 6
2: (0)
3: (0)
4: (2) 0 1
5: (1) 0
6: (2) 0 1
3
0: (2) 1 2
1: (1) 0
2: (1) 0
Sample Output

5
2

*/

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int graph[505][505];
int matchX[505], matchY[505];
int visited[505];
int nodeNum;

bool find(int x)
{
	for(int i = 0;i < nodeNum;i++)
	{
		if (graph[x][i] && !visited[i])
		{
			visited[i] = 1;
			if (matchY[i] == -1 || find(matchY[i]))
			{
				matchY[i] = x;
				matchX[x] = i;
				return true;
			}
		}
	}
	return false;
}

int maxMatch()
{
	int res = 0;
	for(int i = 0;i < nodeNum;i++)
		matchX[i] = matchY[i] = -1;

	for(int i = 0;i < nodeNum;i++)
	{
		memset(visited, 0, sizeof(visited));
		if (find(i))
			res++;
	}
	return res;
}

int main()
{
	int n;
	while(cin >> n)
	{
		memset(graph, 0, sizeof(graph));
		for(int i = 0;i < n;i++)
		{
			int id, fNum;
			scanf("%d: (%d)", &id, &fNum);

			for(int j = 0;j < fNum;j++)
			{
				int fId;
				scanf(" %d", &fId);
				graph[id][fId] = 1;
			}
		}
		nodeNum = n;
		cout << n - (maxMatch() / 2) << endl;
	}
	return 0;
}
