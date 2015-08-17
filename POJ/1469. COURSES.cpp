/*
Description

Consider a group of N students and P courses. Each student visits zero, one or more than one courses. Your task is to determine whether it is possible to form a committee of exactly P students that satisfies simultaneously the conditions: 

every student in the committee represents a different course (a student can represent a course if he/she visits that course) 
each course has a representative in the committee 
Input

Your program should read sets of data from the std input. The first line of the input contains the number of the data sets. Each data set is presented in the following format: 

P N 
Count1 Student1 1 Student1 2 ... Student1 Count1 
Count2 Student2 1 Student2 2 ... Student2 Count2 
... 
CountP StudentP 1 StudentP 2 ... StudentP CountP 

The first line in each data set contains two positive integers separated by one blank: P (1 <= P <= 100) - the number of courses and N (1 <= N <= 300) - the number of students. The next P lines describe in sequence of the courses �from course 1 to course P, each line describing a course. The description of course i is a line that starts with an integer Count i (0 <= Count i <= N) representing the number of students visiting course i. Next, after a blank, you抣l find the Count i students, visiting the course, each two consecutive separated by one blank. Students are numbered with the positive integers from 1 to N. 
There are no blank lines between consecutive sets of data. Input data are correct. 
Output

The result of the program is on the standard output. For each input data set the program prints on a single line "YES" if it is possible to form a committee and "NO" otherwise. There should not be any leading blanks at the start of the line.
Sample Input

2
3 3
3 1 2 3
2 1 2
1 1
3 3
2 1 3
2 1 3
1 1
Sample Output

YES
NO
*/


#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int graph[305][305];
int matchX[305], matchY[305];
int p, n;
int visited[305];

bool find(int k)
{
	for(int i = 0;i < n;i++)
	{
		if (graph[k][i] && !visited[i])
		{
			visited[i] = 1;
			if (matchY[i] == -1 || find(matchY[i]))
			{
				matchX[k] = i;
				matchY[i] = k;
				return true;
			}
		}
	}

	return false;
}


int maxMatch()
{
	for(int i = 0;i < n;i++)
		matchX[i] = matchY[i] = -1;

	int pathNum = 0;
	for(int i = 0;i < p;i++)
	{
		memset(visited, 0, sizeof(visited));
		if (find(i))
			pathNum++;
	}

	return pathNum;
}



int main()
{
	int ncase;
	cin >> ncase;

	while(ncase--)
	{
		cin >> p >> n;

		memset(graph, 0, sizeof(graph));
		for(int i = 0;i < p;i++)
		{
			int num;
            scanf("%d", &num);
			for(int j = 0;j < num;j++)
			{
				int a;
                scanf("%d", &a);
				graph[i][a - 1] = 1;
			}
		}
        
        if (p > n)
        {
            cout << "NO" << endl;
            continue;
        }
		int matchNum = maxMatch();
		if (matchNum == p)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
