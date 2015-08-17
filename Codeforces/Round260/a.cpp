#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct lapTopType
{
	int price, quality;
};

lapTopType lapTop[100005];
int minQ[100005];

bool cmp(const lapTopType &a, const lapTopType &b)
{
	if (a.price < b.price)
		return 1;
	else
		return 0;
}

int main()
{
	int n;
	cin >> n;
	for(int i = 0;i < n;i++)
		scanf("%d %d", &lapTop[i].price, &lapTop[i].quality);

	sort(lapTop, lapTop + n, cmp);

	minQ[n] = n + 1;
	for(int i = n - 1;i >= 0;i--)
		minQ[i] = minQ[i + 1] > lapTop[i].quality ? lapTop[i].quality : minQ[i + 1];
	
	int ok = 0;
	for(int i = 0;i < n;i++)
		if (lapTop[i].quality > minQ[i + 1])
		{
			ok = 1;
			break;
		}
	if (ok)
		cout << "Happy Alex" << endl;
	else
		cout << "Poor Alex" << endl;
	
	return 0;
}
