/*
Elfness is studying in an operation "NOT".
For a binary number A, if we do operation "NOT A", after that, all digits of A will be reversed. (e.g. A=1001101, after operation "NOT A", A will be 0110010).
Now Elfness has N binary numbers of length K, now he can do operations "NOT" for some of his numbers. 
Let's assume after his operations, the maximum number is M, the minimum number is P. He wants to know what's the maximum M - P he can get. Can you help him?
 
Input
The first line of input is an integer T (T ≤ 60), indicating the number of cases.
For each case, the first line contains 2 integers N (1 ≤ N ≤ 10000) and K (1 ≤ K ≤ 60), the next N lines contains N binary numbers, one number per line, indicating the numbers that Elfness has. The length of each binary number is K.
 
Output
For each case, first output the case number as "Case #x: ", and x is the case number. Then you should output an integer, indicating the maximum result that Elfness can get.

Sample Input
2
5 6
100100
001100
010001
010001
111111
5 7
0001101
0001011
0010011
0111000
1001011
Sample Output
Case #1: 51
Case #2: 103

*/

#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int ncase;
	cin >> ncase;
	int icase = 1;
	while(ncase--)
	{
		int n, k;
		cin >> n >> k;
		int minIndex = -1, maxIndex = -1;
		long long minV = -1, maxV = -1;
		
		long long value[10005], reValue[10005];
		getchar();
		for(int i = 0;i < n;i++)
		{
			char a[100];
			scanf("%s", a);
			value[i] = 0, reValue[i] = 0;
			for(int j = 0;j < k;j++)
			{
				value[i] *= 2;
				reValue[i] *= 2;
				value[i] += a[j] - '0';
				reValue[i] += '1' - a[j];
			}
			if (minV == -1 || minV > value[i] || minV > reValue[i])
			{
				minIndex = i;
				minV = value[i] < reValue[i] ? value[i] : reValue[i];
			}
			if (maxV == -1 || maxV < value[i] || maxV < reValue[i])
			{
				maxIndex = i;
				maxV = value[i] > reValue[i] ? value[i] : reValue[i];
			}
		}
		long long res = 0;
		for(int i = 0;i < n;i++)
		{
			if (minIndex == i)
				continue;
			if (res < value[i] - minV)
			   res = value[i] - minV;
			if (res < reValue[i] - minV)
				res = reValue[i] - minV;
		}
		for(int i = 0;i < n;i++)
		{
			if (maxIndex == i)
				continue;
			if (res < maxV - value[i])
			   res = maxV - value[i];
			if (res < maxV - reValue[i])
				res = maxV - reValue[i];
		}
		cout << "Case #" << icase++ << ": " << res << endl;
	}
	return 0;
}
