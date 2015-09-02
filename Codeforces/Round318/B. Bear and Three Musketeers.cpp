/*****************************************************
 * Author: Ai Hongwei 
 * Email: ufo008ahw@163.com
 * Last modified: 2015-08-30 01:17
 * Filename: B. Bear and Three Musketeers.cpp
 * Description: 
 ****************************************************/

/*
Do you know a story about the three musketeers? Anyway, you will learn about its origins now.

Richelimakieu is a cardinal in the city of Bearis. He is tired of dealing with crime by himself. He needs three brave warriors to help him to fight against bad guys.

There are n warriors. Richelimakieu wants to choose three of them to become musketeers but it's not that easy. The most important condition is that musketeers must know each other to cooperate efficiently. And they shouldn't be too well known because they could be betrayed by old friends. For each musketeer his recognition is the number of warriors he knows, excluding other two musketeers.

Help Richelimakieu! Find if it is possible to choose three musketeers knowing each other, and what is minimum possible sum of their recognitions.

Input
The first line contains two space-separated integers, n and m (3 ≤ n ≤ 4000, 0 ≤ m ≤ 4000) — respectively number of warriors and number of pairs of warriors knowing each other.

i-th of the following m lines contains two space-separated integers ai and bi (1 ≤ ai, bi ≤ n, ai ≠ bi). Warriors ai and bi know each other. Each pair of warriors will be listed at most once.

Output
If Richelimakieu can choose three musketeers, print the minimum possible sum of their recognitions. Otherwise, print "-1" (without the quotes).

Sample test(s)
input
5 6
1 2
1 3
2 3
2 4
3 4
4 5
output
2
input
7 4
2 1
3 6
5 1
1 7
output
-1
Note
In the first sample Richelimakieu should choose a triple 1, 2, 3. The first musketeer doesn't know anyone except other two musketeers so his recognition is 0. The second musketeer has recognition 1 because he knows warrior number 4. The third musketeer also has recognition 1 because he knows warrior 4. Sum of recognitions is 0 + 1 + 1 = 2.

The other possible triple is 2, 3, 4 but it has greater sum of recognitions, equal to 1 + 1 + 1 = 3.

In the second sample there is no triple of warriors knowing each other.
*/

#include <iostream>
#include <cstring>
using namespace std;

bool graph[4004][4004];
int knowPair[5005][2];
int recog[5005];

int main() {
	int n, m;
	cin >> n >> m;

	memset(recog, 0, sizeof(recog));
	memset(graph, false, sizeof(graph));
	for(int i = 0;i < m;i++) {
		cin >> knowPair[i][0] >> knowPair[i][1];
		knowPair[i][0]--;
		knowPair[i][1]--;

		graph[knowPair[i][0]][knowPair[i][1]] = graph[knowPair[i][1]][knowPair[i][0]] = true;
		recog[knowPair[i][0]]++;
		recog[knowPair[i][1]]++;
	}


	int minRecog = -1;
	for(int i = 0;i < m;i++) {
		int a = knowPair[i][0], b = knowPair[i][1];

		for(int j = 0;j < n;j++) {
			if (j != a && j != b && graph[a][j] && graph[b][j]) {
				if (minRecog == -1)
					minRecog = recog[a] + recog[b] + recog[j] - 6;
				minRecog = min(minRecog, recog[a] + recog[b] + recog[j] - 6);
			}
		}
	}

	cout << minRecog << endl;
	
	return 0;
}
