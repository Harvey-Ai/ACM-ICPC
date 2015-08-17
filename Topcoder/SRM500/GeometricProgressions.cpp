#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

map< int, int > fb1, fq1, fb2, fq2;
set< map< int, int > > res;
map< int, int> temp;

class GeometricProgressions
{
	public:
	map<int, int> div(int n)
	{
		map<int, int> factor;
		int i;

		if (n == 0)
		{
			factor[0] = 1;
			return factor;
		}
		for(i = 2;i * i <= n;i++)
		{
			if (n % i == 0)
				while (n % i == 0)
				{
					factor[i]++;
					n /= i;
				}
		}
		if (n != 1)
			factor[n]++;
		return factor;
	}

	int count(int b1, int q1, int n1, int b2, int q2, int n2)
	{
		int i;
		int ans;
		map<int, int>::iterator it;
		temp.clear();
	
		if (b1 == 0)
			n1 = 1;
		if (b2 == 0)
			n2 = 1;
		if (q1 == 1 && b1 > 0)
			n1 = 1;
		if (q2 == 1 && b2 > 0)
			n2 = 1;
		if (q1 == 0 && b1 > 0 && n1 > 2)
			n1 = 2;
		if (q2 == 0 && b2 > 0 && n2 > 2)
			n2 = 2;

		fb1 = div(b1);
		fq1 = div(q1);
		fb2 = div(b2);
		fq2 = div(q2);
		res.clear();
		
		temp = fb1;
		res.insert(temp);
		for(i = 1;i < n1;i++)
		{
			for(it = fq1.begin();it != fq1.end();it++)
				temp[it->first] += it->second;
			if (temp.find(0) != temp.end())
			{
				temp.clear();
				temp[0] = 1;
			}
			if (res.find(temp) == res.end())
				res.insert(temp);
		}

		ans = res.size();
	
		temp = fb2;
		if (res.find(temp) == res.end())
			ans++;
		for(i = 1;i < n2;i++)
		{
			for(it = fq2.begin();it != fq2.end();it++)
				temp[it->first] += it->second;
			if (temp.find(0) != temp.end())
			{
				temp.clear();
				temp[0] = 1;
			}
			if (res.find(temp) == res.end())
				ans++;
		}

		return ans;
	}
};
//{446185740, 410498683, 100500, 268953270, 164601714, 100500}
