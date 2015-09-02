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

		int sum[2550], cnt[2550];
		memset(sum, 0, sizeof(sum));
		memset(cnt, 0, sizeof(cnt));
		for(int i = 0;i < s.size();i++) {
			cnt[i + 1] = cnt[i] + (s[i] == '1');
			sum[i + 1] = sum[i] + (s[i] == '1') * i;
		}

		int res = 0;
		for(int i = 0;i < s.size();i++) {
			for(int j = i;j < s.size();j++) {
				if (cnt[j + 1] - cnt[i] == 0 || 
						(sum[j + 1] - sum[i]) % (cnt[j + 1] - cnt[i]) == 0)
					res++;
			}
		}
		
		return res;
	}
};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
