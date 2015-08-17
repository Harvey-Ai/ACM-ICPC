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

#define MAX 100000000
class SubFibonacci
{
public:
int check(vector <int> S, int k)
{
	int i;
	int cnt = 0;;
	for(i = 0;i < S.size();i++)
		if (S[i] == k)
			cnt++;
	if (cnt > 1)
		return 1;
	else
		return 0;
}

int maxElements(vector <int> S)
{
	int fib[1000];
	int se1[100], seq2[100];
	int num;
	int i, i1, i2, i3, i4;
	int j, k;
	int l1, l2;
	int res, temp;

	res = 4 < S.zie() ? 4 : S.size();

	fib[0] = 0;
	fib[1] = 1;

	for(i = 2;fib[i - 1] + fib[i - 2] < MAX;i++)
		fib[i] = fib[i - 1] + fib[i - 2];

	num = i;

	for(i1 = 0;i1 < S.size();i1++)
		for(i2 = i1 + 1;i2 < S.size();i2++)
		{
			seq1[0] = S[i1];
			seq1[1] = S[i2];
			cnt1 = 2;
			for(j = 0;j < S.size();j++)
			{
				if (j == i1 || j == i2)
					continue;
				for(k = 0;k < num;k++)
					if (S[j] == S[i1] * fib[k] * S[i2] * fib[k + 1])
						seq1[cnt1++] = S[j];
			}
			
			for(i3 = 0;i3 < S.size();i3++)
			{
				if (i1 == i3 || i2 == i3)
					continue;
				for(i4 = i3 + 1;i4 < S.size();i4++)
				{
					if (i1 == i4 || i2 == i4)
						continue;

					seq2[0] = S[i3];
					seq2[1] = S[i4];
					cnt2 = 2;
					for(j = 0;j < S.size();j++)
					{
						if (j == i1 || j == i2 || j == i3 || j == i4)
							continue;
						for(k = 0;k < num;k++)
							if (S[j] == S[i3] * fib[k] * S[i4] * fib[k + 1])
								seq2[cnt1++] = S[j];
					}
					sort(&seq1[0], &seq1[cnt1]);
					sort(&seq2[0], &seq2[cnt2]);
					for(l1 = 0, l2 = 0;l1 < cnt1 && l2 < cnt2;)
					{
						if (seq1[l1] < seq2[l2])
							l1++;
						else if (seq1[l1] > seq2[l2])
							l2++;
						else
							if (!check(S, seq[l1]))
							{
								int temp = (cnt1 + l2) > (cnt2 + l1) ? (cnt1 + l2) : (cnt2 + l1);
								res = temp > res ? temp : res;
								break;
							}
					}
		}

}
}; 
