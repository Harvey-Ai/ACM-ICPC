#include <iostream>
#include <map>
#include <cstring>
#include <cstdio>
using namespace std;

int leftLen[1000005], rightLen[1000005];
int diffMap[1000005];
char str[1000005];

int main() {
	scanf("%s", str);
	int len = strlen(str);
	memset(leftLen, 0, sizeof(leftLen));
	memset(rightLen, 0, sizeof(rightLen));

	int s[2] = {0, 0};
	memset(diffMap, -1, sizeof(diffMap));
	diffMap[0] = 0;
	for(int i = 0;i < len;i++) {
		s[str[i] - '0']++;

		int t = min(s[0] - s[1] - 1, 0);
		if (diffMap[-t] >= 0) {
		    leftLen[i] = i + 1 - diffMap[-t];
		}

        if (s[1] >= s[0] && diffMap[s[1] - s[0]] == -1) {
            diffMap[s[1] - s[0]] = i + 1;
		}
	}

    memset(diffMap, -1, sizeof(diffMap));
	diffMap[0] = len;
	s[0] = s[1] = 0;
	for(int i = len - 1;i >= 0;i--) {
		s[str[i] - '0']++;

		int t = min(s[1] - s[0] - 1, 0);
		if (diffMap[-t] >= 0) {
		    rightLen[i] = diffMap[-t] - i;
		}

        if (s[0] >= s[1] && diffMap[s[0] - s[1]] == -1) {
            diffMap[s[0] - s[1]] = i;
		}
	}

	int res = 0;
	for(int i = 0;i < len - 1;i++) {
		if (leftLen[i] && rightLen[i + 1]) {
			res = max(res, leftLen[i] + rightLen[i + 1]);
		}
	}

	cout << res << endl;

	return 0;
}
