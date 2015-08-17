/*
Description

You are given two sequences of integer numbers. Write a program to determine their common increasing subsequence of maximal possible length. 
Sequence S1 , S2 , . . . , SN of length N is called an increasing subsequence of a sequence A1 , A2 , . . . , AM of length M if there exist 1 <= i1 < i2 < . . . < iN <= M such that Sj = Aij for all 1 <= j <= N , and Sj < Sj+1 for all 1 <= j < N .
Input

Each sequence is described with M --- its length (1 <= M <= 500) and M integer numbers Ai (-231 <= Ai < 231 ) --- the sequence itself.
Output

On the first line of the output file print L --- the length of the greatest common increasing subsequence of both sequences. On the second line print the subsequence itself. If there are several possible answers, output any of them.
Sample Input

5
1 4 2 5 -12
4
-12 1 2 4
Sample Output

2
1 4
*/


#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int arr1[505], arr2[505];
int dp[505][505];
int path[505][505][2];

int main()
{
	int n1, n2;
	cin >> n1;
	for(int i = 0;i < n1;i++)
		scanf("%d", &arr1[i]);
	cin >> n2;
	for(int i = 0;i < n2;i++)
		scanf("%d", &arr2[i]);

	for(int i = 0;i < 505;i++)
	{
		dp[i][0] = dp[0][i] = 0;
		path[i][0][0] = path[i][0][1] = path[0][i][0] = path[0][i][1] = -1;
	}

	for(int i = 1;i <= n1;i++)
		for(int j = 1;j <= n2;j++)
		{
            if (arr1[i - 1] != arr2[j - 1])
            {
                dp[i][j] = dp[i][j - 1];
                path[i][j][0] = i;
                path[i][j][1] = j - 1;
            }
			else
            {
				int h = -1, v = -1;
				int maxV = 0;				
                for(int k = 0;k < i - 1;k++)
                    if (arr1[k] < arr1[i - 1])
                        if (maxV < dp[k + 1][j - 1])
                        {
                            maxV = dp[k + 1][j - 1];
                            h = k + 1;
                            v = j - 1;
                        }
                
                dp[i][j] = maxV + 1;
                path[i][j][0] = h;
                path[i][j][1] = v;
			}
		}

    
    
    vector<int> ans;
    int res = 0;
    int h = n1, v = n2;
    for(int i = 0;i < n1;i++)
        if (dp[i + 1][n2] > res)
        {
            res = dp[i + 1][n2];
            h = i + 1;
        }
        
	while (h > 0 && v > 0)
	{
        if (arr1[h - 1] == arr2[v - 1])
            ans.push_back(arr1[h - 1]);
     
       // cout << h << " " << v << endl;
        int tempH = path[h][v][0];
        int tempV = path[h][v][1];   
        h = tempH;
		v = tempV;
	}

	cout << ans.size() << endl;
	for(int i = ans.size() - 1;i >= 0;i--)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}
