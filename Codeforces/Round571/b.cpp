#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {

	int n, k;
	vector<long long> arr;
	
	cin >> n >> k;
	for(int i = 0;i < n;i++) {
		long long a;
		cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());

	long long res = 0;
	int pos = 0;
	for(int i = 0;i < n;i++) {
		if (pos > 0) {
			res += arr[i] - arr[i - 1];
		}

		pos += k;
		if (pos >= n) {
			pos = 0;
		}
	}

	cout << res << endl;
	return 0;
}
