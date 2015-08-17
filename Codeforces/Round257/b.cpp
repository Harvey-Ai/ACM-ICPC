#include <iostream>
#include <cstdlib>
using namespace std;
#define N 1000000007

int main()
{
	long long x, y;
	long long n;
	cin >> x >> y;
	cin >> n;

	n--;
	n %= 6;
	switch(n)
	{
		case 0:cout << (x + N) % N << endl;break;
		case 1:cout << (y + N) % N << endl;break;
		case 2:cout << (y - x + N + N) % N << endl;break;
		case 3:cout << (-x + N) % N << endl;break;
		case 4:cout << (-y + N) % N << endl;break;
		case 5:cout << (-y + x + N + N) % N << endl;break;
		default:break;
	}
	return 0;
}
