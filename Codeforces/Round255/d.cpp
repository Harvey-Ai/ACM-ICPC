#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long long rowCost[1000005];
long long colCost[1000005];
int main()
{
	int n, m, k, p;
	priority_queue<long long, vector<long long>, less<long long> > rowSumQ;
	priority_queue<long long, vector<long long>, less<long long> > colSumQ;
	cin >> n >> m >> k >> p;

	long long rowSum[1005], colSum[1005];
	for(int i = 0;i < 1005;i++)
		rowSum[i] = colSum[i] = 0;
	for(int i = 0; i < n;i++)
		for(int j = 0;j < m;j++)
		{
			int ijVal;
			cin >> ijVal;
			rowSum[i] += ijVal;
			colSum[j] += ijVal;
		}
	for(int i = 0;i < n;i++)
		rowSumQ.push(rowSum[i]);
	for(int i = 0;i < m;i++)
		colSumQ.push(colSum[i]);

	rowCost[0] = 0;
	for(int i = 1;i <= k;i++)
	{
		long long rowMax = rowSumQ.top();
		rowCost[i] = rowCost[i - 1] + rowMax;
		rowSumQ.pop();
		rowSumQ.push(rowMax - p * m);
	}
	colCost[0] = 0;
	for(int i = 1;i <= k;i++)
	{
		long long colMax = colSumQ.top();
		colCost[i] = colCost[i - 1] + colMax;
		colSumQ.pop();
		colSumQ.push(colMax - p * n);
	}

	long long res = rowCost[k];
	for(int i = 0;i <= k;i++)
	{
		long long cost = rowCost[i] + colCost[k - i] - (long long)i * (k - i) * p;
		res = res < cost ? cost : res;
	}
	
	cout << res << endl;
	return 0;
}
