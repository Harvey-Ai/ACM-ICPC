#include <iostream>
#include <map>
#include <cstdio>
using namespace std;

#define N 1000005
int arr[1000005];
int fLeft[1000005], fRight[1000005];
map<int, int> countMap;

#define typev int // type of res
typev ar[N]; // index: 1 ~ N
int lowb(int t) { return t & (-t) ; }
void add(int i, typev v) {
	for ( ; i < N; ar[i] += v, i += lowb(i));
}
typev sum(int i) {
	typev s = 0;
	for ( ; i > 0; s += ar[i], i -= lowb(i));
	return s;
}

int main()
{
	int n;
	cin >> n;

	for(int i = 0;i < n;i++)
		scanf("%d", &arr[i]);

	for(int i = 0;i < n;i++)
	{
		if (countMap.find(arr[i]) == countMap.end())
			countMap[arr[i]] = 0;
		countMap[arr[i]]++;
		fLeft[i] = countMap[arr[i]];
	}
	countMap.clear();

	for(int i = n - 1;i >= 0;i--)
	{
		if (countMap.find(arr[i]) == countMap.end())
			countMap[arr[i]] = 0;
		countMap[arr[i]]++;
		fRight[i] = countMap[arr[i]];
	}

	for(int i = 0;i < n;i++)
		add(fRight[i] + 1, 1);

	long long res = 0;
	for(int i = 0;i < n - 1;i++)
	{
		
		add(fRight[i] + 1, -1);
		res += sum(fLeft[i]);
	}
	cout << res << endl;
	return 0;
}
