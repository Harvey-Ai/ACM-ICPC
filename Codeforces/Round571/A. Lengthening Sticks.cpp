#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	long long a, b, c, l;
	cin >> a >> b >> c >> l;
	long long res = 0;

	for(long long i = 1;i <= l;i++) {
		long long newA = a + i;
		long long left = l - i;

		long long bMin = abs(newA - c) + 1, bMax = newA + c - 1;
		bMin = max(b + 1, bMin);
		if (bMax >= bMin && left >= (bMin - b)) {
			res += min(left - (bMin - b) + 1, bMax - bMin + 1);
		}

		long long cMin = abs(newA - b) + 1, cMax = newA + b - 1;
		cMin = max(c + 1, cMin);
		if (cMax >= cMin && left >= (cMin - c)) {
			res += min(left -  (cMin - c) + 1, cMax - cMin + 1);
		}

		long long newB = b + i;
		cMin = abs(a - newB) + 1, cMax = a + newB - 1;
		cMin = max(c + 1, cMin);
		if (cMax >= cMin && left >= (cMin - c)) {
			res += min(left -  (cMin - c) + 1, cMax - cMin + 1);
		}
	}

	cout << res << endl;
	if (a > b) swap(a, b);
	if (a > c) swap(a, c);
	if (b > c) swap(b, c);

	long long minA = c - b + 1, maxA = c + b - 1;
	minA = max(minA, a + 1);
	if (maxA >= minA && l >= (minA - a))
		res += min(l - (minA - a) + 1, maxA - minA + 1);


	long long minB = c - a + 1, maxB = c + a - 1;
	minB = max(minB, b + 1);
	if (maxB >= minB && l >= (minB - b))
		res += min(l - (minB - b) + 1, maxB - minB + 1);

	long long minC = b - a + 1, maxC = a + b - 1;
	minC = max(minC, c + 1);
	if (maxC >= minC && l >= (minC - c))
		res += min(l - (minC - c) + 1, maxC - minC + 1);

	cout << res << endl;

	if (a + b > c) {
		res++;
	}

	cout << res << endl;
	return 0;
}
