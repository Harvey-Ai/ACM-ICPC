/*
Description

Let N be the set of all natural numbers {0 , 1 , 2 , . . . }, and R be the set of all real numbers. wi, hi for i = 1 . . . n are some elements in N, and w0 = 0. 
Define set B = {< x, y > | x, y ∈ R and there exists an index i > 0 such that 0 <= y <= hi ,∑0<=j<=i-1wj <= x <= ∑0<=j<=iwj} 
Again, define set S = {A| A = WH for some W , H ∈ R+ and there exists x0, y0 in N such that the set T = { < x , y > | x, y ∈ R and x0 <= x <= x0 +W and y0 <= y <= y0 + H} is contained in set B}.
Your mission now. What is Max(S)? 
Wow, it looks like a terrible problem. Problems that appear to be terrible are sometimes actually easy. 
But for this one, believe me, it's difficult.
Input

The input consists of several test cases. For each case, n is given in a single line, and then followed by n lines, each containing wi and hi separated by a single space. The last line of the input is an single integer -1, indicating the end of input. You may assume that 1 <= n <= 50000 and w1h1+w2h2+...+wnhn < 109.
Output

Simply output Max(S) in a single line for each case.
Sample Input

3
1 2
3 4
1 2
3
3 4
1 2
3 4
-1
Sample Output

12
14
*/


#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int main()
{
	int n;

	while(cin >> n, n != -1)
	{
		int arr[500005][2];
		for(int i = 0;i < n;i++)
			scanf("%d %d", &arr[i][0], &arr[i][1]);

		stack<int> hStack, wStack;
		int res = 0;
		int width = 0;
		for(int i = 0;i < n;i++)
		{
			int minWidth = width;
			while(!hStack.empty() && hStack.top() > arr[i][1])
			{
				if (hStack.top() * (width - wStack.top()) > res)
					res = hStack.top() * (width - wStack.top());
				minWidth = wStack.top();
				hStack.pop();
				wStack.pop();
			}
			hStack.push(arr[i][1]);
			wStack.push(minWidth);
			width += arr[i][0];
		}

		while(!hStack.empty())
		{
			if (hStack.top() * (width - wStack.top()) > res)
				res = hStack.top() * (width - wStack.top());
			hStack.pop();
			wStack.pop();
		}
		cout << res << endl;
	}
	return 0;
}
