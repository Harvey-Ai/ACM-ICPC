#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <cstdio>
using namespace std;


class BalancedSubstrings {
	public:
	int countSubstrings(string s) {
		int res = 0;

		for(int i = 0;i < s.size();i++) {
			int sum = 0;
			map<int, int> sumMap;
			sumMap[0] = 1;
			for(int j = i - 1;j >= 0;j--) {
				if (s[j] == '1') {
					sum += (i - j);
				}
				if (sumMap.find(sum) == sumMap.end()) {
					sumMap[sum] = 1;
				} else {
					sumMap[sum]++;
				}
			}

			sum = 0;
			res += sumMap[0];
			for(int j = i + 1;j < s.size();j++) {
				if (s[j] == '1') {
					sum += (j - i);
				}
				if (sum == 0 && s[i] == '0') {
					continue;
				}

				if (sumMap.find(sum) != sumMap.end()) {
					res += sumMap[sum];
				}
			}
		}
		return res;
	}
};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
