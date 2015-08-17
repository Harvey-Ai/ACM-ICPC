#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
#define N 100000

struct stackEle
{
	long long value, times;
	stackEle(long long v, long long t)
	{
		value = v;
		times = t;
	}
};

int main()
{
	long long x, k;
	cin >> x >> k;

	vector<long long> divisor;
	for(long long j = 1;j * j <= x;j++)
		if (x % j == 0)
		{
			divisor.push_back(j);
			if (j * j != x)
				divisor.push_back(x / j);
		}

	sort(divisor.begin(), divisor.end());
	stack<stackEle> valStack;
	valStack.push(stackEle(x, 0));
	vector<long long> ans;

	while(!valStack.empty() && ans.size() < N)
	{
		stackEle oneEle = valStack.top();
		valStack.pop();

		if (oneEle.times >= k)
			ans.push_back(oneEle.value);
		else if (oneEle.value == 1)
			ans.push_back(1);
		else
		{
			for(int i = 0;i < divisor.size() && divisor[i] <= oneEle.value;i++)
				if (oneEle.value % divisor[i] == 0)
					valStack.push(stackEle(oneEle.value / divisor[i], oneEle.times + 1));
		}
	}

	for(int i = 0;i < ans.size();i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}
