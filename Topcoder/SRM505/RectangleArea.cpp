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

#include <stdio.h>



int main()
{
	int  i;
	long long n;
	long long t;
	scanf("%lld", &n);

	i = 4;
	t = 0x01;
	for(i = 0;i < 8;i++)
	{
		printf("%d ", t & n ? 1 : 0);
		t <<= 1;
	}
	
	putchar('\n');
	printf("%d\n", i < n);

	printf("=================\n");
	n = 1;
	t = 0x01;
	for(i = 0;i < 8;i++)
	{
		printf("%d ", t & n ? 1 : 0);
		t <<= 1;
	}
	putchar('\n');
	printf("%lld\n", i < n);
}

class RectangleArea
{
public:
int minimumQueries(vector <string> known)
{

}
}; 
