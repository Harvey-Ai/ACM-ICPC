/*****************************************************
 * Author: Ai Hongwei 
 * Email: ufo008ahw@163.com
 * Last modified: 2015-08-30 00:51
 * Filename: A.
 * Description: 
 ****************************************************/

/*
Limak is a grizzly bear who desires power and adoration. He wants to win in upcoming elections and rule over the Bearland.

There are n candidates, including Limak. We know how many citizens are going to vote for each candidate. Now i-th candidate would get ai votes. Limak is candidate number 1. To win in elections, he must get strictly more votes than any other candidate.

Victory is more important than everything else so Limak decided to cheat. He will steal votes from his opponents by bribing some citizens. To bribe a citizen, Limak must give him or her one candy - citizens are bears and bears like candies. Limak doesn't have many candies and wonders - how many citizens does he have to bribe?

Input
The first line contains single integer n (2 ≤ n ≤ 100) - number of candidates.

The second line contains n space-separated integers a1, a2, ..., an (1 ≤ ai ≤ 1000) - number of votes for each candidate. Limak is candidate number 1.

Note that after bribing number of votes for some candidate might be zero or might be greater than 1000.

Output
Print the minimum number of citizens Limak must bribe to have strictly more votes than any other candidate.

Sample test(s)
	input
	5
	5 1 11 2 8
	output
	4
	input
	4
	1 8 8 8
	output
	6
	input
	2
	7 6
	output
	0
	Note
	In the first sample Limak has 5 votes. One of the ways to achieve victory is to bribe 4 citizens who want to vote for the third candidate. Then numbers of votes would be 9, 1, 7, 2, 8 (Limak would have 9 votes). Alternatively, Limak could steal only 3 votes from the third candidate and 1 vote from the second candidate to get situation 9, 0, 8, 2, 8.

	In the second sample Limak will steal 2 votes from each candidate. Situation will be 7, 6, 6, 6.

*/


#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int arr[105];
	int n;
	cin >> n;
	for(int i = 0;i < n;i++) {
		cin >> arr[i];
	}

	int flag = 1;
	int res = 0;

	while(flag) {
		flag = 0;
		
		sort(arr + 1, arr + n);
		if (arr[0] <= arr[n - 1]) {
			arr[0]++, arr[n - 1]--;
			flag = 1;
			res++;
		}

	}
	cout << res << endl;

	return 0;
}


