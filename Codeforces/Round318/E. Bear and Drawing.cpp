/*****************************************************
 * Author: Ai Hongwei 
 * Email: ufo008ahw@163.com
 * Last modified: 2015-08-30 02:16
 * Filename: E. Bear and Drawing.cpp
 * Description: 
 ****************************************************/

/*
Limak is a little bear who learns to draw. People usually start with houses, fences and flowers but why would bears do it? Limak lives in the forest and he decides to draw a tree.

Recall that tree is a connected graph consisting of n vertices and n - 1 edges.

Limak chose a tree with n vertices. He has infinite strip of paper with two parallel rows of dots. Little bear wants to assign vertices of a tree to some n distinct dots on a paper so that edges would intersect only at their endpoints — drawn tree must be planar. Below you can see one of correct drawings for the first sample test.


Is it possible for Limak to draw chosen tree?

Input
The first line contains single integer n (1 ≤ n ≤ 105).

Next n - 1 lines contain description of a tree. i-th of them contains two space-separated integers ai and bi (1 ≤ ai, bi ≤ n, ai ≠ bi) denoting an edge between vertices ai and bi. It's guaranteed that given description forms a tree.

Output
Print "Yes" (without the quotes) if Limak can draw chosen tree. Otherwise, print "No" (without the quotes).

Sample test(s)
input
8
1 2
1 3
1 6
6 4
6 7
6 5
7 8
output
Yes
input
13
1 2
1 3
1 4
2 5
2 6
2 7
3 8
3 9
3 10
4 11
4 12
4 13
output
No
*/

#include <iostream>
using namespace std;

int degree[100005];
bool bigSon[100005];
bool longSon[100005];
int bigSonNum[100005];
int longSonNum[
int son[100005];
bool visit[100005];
vector<int> graph[100005];

int main() {
	int n;

	memset(degree, 0, sizeof(degree));
	cin >> n;
	for(int i = 0;i < n;i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;

		graph[a].push_back(b);
		graph[b].push_back(a);
		degree[a]++, degree[b]++;
	}

	memset(visit, 0, sizeof(visit));
	memset(bigSon, 0, sizeof(bigSon));
	memset(longSon, 0, sizeof(longSon));
	memset(bigSon, 0, sizeof(bigSon));
	memset(bigSon, 0, sizeof(bigSon));
	memset(son, 0, sizeof(son));
	queue<int> leafQ;
	for(int i = 0;i < n;i++) {
		if (degree[i] == 1) 
		{
			leafQ.push(i);
			visit[i] = true;
			degree[i]--;
		}
	}
	
	int ok = true;
	while(!leafQ.empyt()) {
		int a = leatQ.front();
		leftQ.pop();

		for(auto p : graph[a]) {
			if (degree[p] > 0) {
				if (bigSon[a])
					bigSonNum[p]++;
				if (longSon[a])
					longSonNum[a]++;

				degree[p]--;
				son[p]++;

				if (degree[p] == 1) {
					if (son[p] > 1) 
						bigSon[p] =  
					else
						longSon[p] = 1;
				}
			}
		}
	}



}
