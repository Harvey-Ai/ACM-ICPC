/*
Description

In this problem, you have to analyze a particular sorting algorithm. The algorithm processes a sequence of n distinct integers by swapping two adjacent sequence elements until the sequence is sorted in ascending order. For the input sequence 
9 1 0 5 4 ,

Ultra-QuickSort produces the output 
0 1 4 5 9 .

Your task is to determine how many swap operations Ultra-QuickSort needs to perform in order to sort a given input sequence.
Input

The input contains several test cases. Every test case begins with a line that contains a single integer n < 500,000 -- the length of the input sequence. Each of the the following n lines contains a single integer 0 ≤ a[i] ≤ 999,999,999, the i-th input sequence element. Input is terminated by a sequence of length n = 0. This sequence must not be processed.
Output

For every input sequence, your program prints a single line containing an integer number op, the minimum number of swap operations necessary to sort the given input sequence.
Sample Input

5
9
1
0
5
4
3
1
2
3
0
Sample Output

6
0
*/


#include <iostream>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int segTree[500005];
int maxNum;

int lowBit(int i)
{
	return i & (-i);
}

int add(int i, int k)
{
	while(i <= maxNum)
	{
		segTree[i] += k;
		i += lowBit(i);
	}
	return 0;
}

int sum(int i)
{
	int res = 0;
	while(i > 0)
	{
		res += segTree[i];
		i -= lowBit(i);
	}
	return res;
}

struct eleType
{
    long long v;
    int index;
    int segIndex;
};

bool cmp1(const eleType &a, const eleType &b)
{
    return a.v < b.v;
}

bool cmp2(const eleType &a, const eleType &b)
{
    return a.index < b.index;
}

eleType elements[500005];

int main()
{
	int n;
	while(scanf("%d", &n), n)
	{
		for(int i = 0;i < n;i++)
		{
			scanf("%lld", &elements[i].v);
            elements[i].index = i;
		}
		sort(elements, elements + n, cmp1);
        elements[0].segIndex = 1;
        for(int i = 1;i < n;i++)
            if (elements[i].v == elements[i - 1].v)
                elements[i].segIndex = elements[i - 1].segIndex;
            else
                elements[i].segIndex = elements[i - 1].segIndex + 1;
        maxNum = elements[n - 1].segIndex;
        sort(elements, elements + n, cmp2);
        
		memset(segTree, 0, sizeof(segTree));
		long long res = 0;
		for(int i = 0;i < n;i++)
		{
			int index = elements[i].segIndex;
			add(index, 1);
			int s1 = sum(index);
			int s2 = sum(maxNum);
			res += s2 - s1;
		}
		printf("%lld\n", res);
	}
	return 0;
}
