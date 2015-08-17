/*
Recently, researchers on Mars have discovered N powerful atoms. All of them are different. These atoms have some properties. When two of these atoms collide, one of them disappears and a lot of power is produced. Researchers know the way every two atoms perform when collided and the power every two atoms can produce.

You are to write a program to make it most powerful, which means that the sum of power produced during all the collides is maximal.

Input

There are multiple cases. The first line of each case has an integer N (2 <= N <= 10), which means there are N atoms: A1, A2, ... , AN. Then N lines follow. There are N integers in each line. The j-th integer on the i-th line is the power produced when Ai and Aj collide with Aj gone. All integers are positive and not larger than 10000.

The last case is followed by a 0 in one line.

There will be no more than 500 cases including no more than 50 large cases that N is 10.

Output

Output the maximal power these N atoms can produce in a line for each case.

Sample Input

2
0 4
1 0
3
0 20 1
12 0 1
1 10 0
0

Sample Output

4
22
*/


#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;

int graph[11][11];
int dp[1 << 10];
int main()
{
    int n;
	while(cin >> n, n)
	{
		for(int i = 0;i < n;i++)
			for(int j = 0;j < n;j++)
				cin >> graph[i][j];

        memset(dp, 0, sizeof(dp));
        
        for(int i = 0;i < (1 << n);i++)
            for(int j = 0;j < n;j++)
            {
                if ((1 << j) & i) continue;
                for(int k = 0;k < n;k++)
                {
                    if (((1 << k) & i) || k == j) continue;
                    dp[i | (1 << k)] = max(dp[i | (1 << k)], dp[i] + graph[j][k]);
                }
            }
                    
        int res = 0;
		for(int i = 0;i < (1 << n);i++)
            res = max(res, dp[i]);
                
         cout << res << endl;
	}
	
	return 0;
}
