#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct segmentType
{
	int start, end;
};
segmentType segs[500005];

bool cmp(const segmentType &a, const segmentType &b)
{
	if (a.start < b.start)
		return 1;
	else
		return 0;
}

int main()
{
	int n, m;

	cin >> n >> m;
	for(int i = 0;i < m;i++)
		scanf("%d %d", &segs[i].start, &segs[i].end);
	sort(segs, segs + m, cmp);

	int res = 0;
	int endPos = 1;
	int index = 0;
	while(index < m && endPos <= n)
	{
		int optIndex = -1;
		while(index < m && segs[index].start <= endPos)
		{
			if (optIndex == -1 || segs[optIndex].end < segs[index].end)
				optIndex = index;
			index++;
		}
		res++;
		endPos = segs[optIndex].end + 1;
	}

	cout << res << endl;
	return 0;
}
