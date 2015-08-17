/*
You are given n segments on a straight line. For each pair of segments it is known that they either have no common points or all points of one segment belong to the second segment.
Then m queries follow. Each query represents a point on the line. For each query, your task is to find the segment of the minimum length, to which this point belongs.
Input
The first line contains an integer n that is the number of segments (1 ≤ n ≤ 105). i’th of the next n lines contains integers ai and bi that are the coordinates of endpoints of the i’th segment (1 ≤ ai < bi ≤ 109). The segments are ordered by non-decreasing ai, and when ai = aj they are ordered by decreasing length. The next line contains an integer m that is the number of queries (1 ≤ m ≤ 105). j’th of the next m lines contains an integer cj that is the coordinate of the point (1 ≤ cj ≤ 109). The queries are ordered by non-decreasing cj.
Output
For each query output the number of the corresponding segment on a single line. If the point does not belong to any segment, output “-1”. The segments are numbered from 1 to n in order they are given in the input.
Sample Input
input
3
2 10
2 3
5 7
11
1
2
3
4
5
6
7
8
9
10
11

output
-1
2
2
1
3
3
3
1
1
1
-1
*/

#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

struct segType
{
	long long b, e;
	long long len;
	int index;
	segType()
	{
		b = e = 0;
		len = 0;
		index = 0;
	}
	segType(long long bb, long long ee, long long ll, int ii)
	{
		b = bb;
		e = ee;
		len = ll;
		index = ii;
	}

	bool operator()(segType &a, segType &b)
	{
		if (a.len < b.len)
			return 1;
		return 0;
	}
};

long long bb[100005], ee[100005];
int main()
{
	priority_queue<segType, vector<segType>, segType> segQ;
	int n;
	cin >> n;
	for(int i = 0;i < n;i++)
		scanf("%lld %lld", &bb[i], &ee[i]);
	
	int m;
	cin >> m;
	int pos = 0;

	while(m--)
	{
		int l;
		cin >> l;
		
		while(pos < n && bb[pos] <= l)
		{
			segQ.push(segType(bb[pos], ee[pos], ee[pos] - bb[pos], pos));
			pos++;
		}
		
		int res = -1;
		while(!segQ.empty())
		{
			segType a = segQ.top();
			if (a.e < l)
				segQ.pop();
			else
			{
				res = a.index;
				break;
			}
		}

		if (res != -1)
			res++;
		cout << res << endl;
	}

	return 0;
}
