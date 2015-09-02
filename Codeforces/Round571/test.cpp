#include <iostream>
#include <cstdio>
using namespace std;

bool fun(int a, int b, int c)
{
	if (a + b <= c || a + c <= b || b + c <= a) 
		return false;

	return true;
}

int main() {

	for(int i = 1;i <= 6;i++) 
		for(int j = 2;j <= 7;j++)
			for(int k = 1;k <= 6;k++) {
				if (i + j + k > 9)
					continue;

				if (fun(i, j, k))
					printf("%d %d %d\n", i, j, k);
			}

	return 0;
}
