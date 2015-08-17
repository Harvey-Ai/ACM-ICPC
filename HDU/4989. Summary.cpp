/*
Problem Description
Small W is playing a summary game. Firstly, He takes N numbers. Secondly he takes out every pair of them and add this two numbers, thus he can get N*(N - 1)/2 new numbers. Thirdly he deletes the repeated number of the new numbers. Finally he gets the sum of the left numbers. Now small W want you to tell him what is the final sum.
 

Input
Multi test cases, every case occupies two lines, the first line contain n, then second line contain n numbers a1, a2, ……an separated by exact one space. Process to the end of file.
[Technical Specification]
2 <= n <= 100
-1000000000 <= ai <= 1000000000
 

Output
For each case, output the final sum.
 

Sample Input
4
1 2 3 4
2
5 5
 

Sample Output
25
10
Hint
Firstly small W takes any pair of 1 2 3 4 and add them, he will get 3 4 5 5 6 7. Then he deletes the repeated numbers, he will get 3 4 5 6 7, Finally he gets the sum=3+4+5+6+7=25.
*/


#include <iostream>
#include <set>
using namespace std;

int main()
{
	int n;

	int arr[105];
	while(cin >> n)
	{
		set<int> sumSet;

		for(int i = 0;i < n;i++)
			cin >> arr[i];

		for(int i = 0;i < n;i++)
			for(int j = i + 1;j < n;j++)
				sumSet.insert(arr[i] + arr[j]);

		__int64 res = 0;
		for(set<int>::iterator it = sumSet.begin();it != sumSet.end();it++)
			res += (__int64)(*it);
		cout << res << endl;
	}
	return 0;
}
