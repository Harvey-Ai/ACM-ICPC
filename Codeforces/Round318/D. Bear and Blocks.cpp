/*****************************************************
 * Author: Ai Hongwei 
 * Email: ufo008ahw@163.com
 * Last modified: 2015-08-30 01:46
 * Filename: D. Bear and Blocks.cpp
 * Description: 
 ****************************************************/

/*
Limak is a little bear who loves to play. Today he is playing by destroying block towers. He built n towers in a row. The i-th tower is made of hi identical blocks. For clarification see picture for the first sample.

Limak will repeat the following operation till everything is destroyed.

Block is called internal if it has all four neighbors, i.e. it has each side (top, left, down and right) adjacent to other block or to the floor. Otherwise, block is boundary. In one operation Limak destroys all boundary blocks. His paws are very fast and he destroys all those blocks at the same time.

Limak is ready to start. You task is to count how many operations will it take him to destroy all towers.

Input
The first line contains single integer n (1 ≤ n ≤ 105).

The second line contains n space-separated integers h1, h2, ..., hn (1 ≤ hi ≤ 109) — sizes of towers.

Output
Print the number of operations needed to destroy all towers.

Sample test(s)
input
6
2 1 4 6 2 2
output
3
input
7
3 3 3 1 3 3 3
output
2
*/


#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int leftNum[100005], rightNum[100005];
int arr[100005];
int main() {

	int n;
	cin >> n;

	for(int i = 0;i < n;i++) {
		cin >> arr[i];
	}

	leftNum[0] = 1;
	for(int i = 1;i < n;i++) {
		leftNum[i] = leftNum[i - 1] + 1;
		leftNum[i] = min(arr[i], leftNum[i]);
//		cout << leftNum[i] << endl;
	}
//	cout << "--" << endl;

	rightNum[n - 1] = 1;
	for(int i = n - 2;i >= 0;i--) {
		rightNum[i] = rightNum[i + 1] + 1;
		rightNum[i] = min(arr[i], rightNum[i]);
//		cout << rightNum[i] << endl;
	}

	int res = 0;
	for(int i = 0;i < n;i++) {
		res = max(min(leftNum[i], rightNum[i]), res);
	}

	cout << res << endl;
	return 0;
}
