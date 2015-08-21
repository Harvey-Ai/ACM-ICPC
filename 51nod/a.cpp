#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    while(n--) {
        string str;
        cin >> str;
        
        int minC[2505];
        minC[str.size() - 1] = str.size() - 1;
        for(int i = str.size() - 2;i >= 0;i--) {
            if (str[i] > str[minC[i + 1]]) {
                minC[i] = minC[i + 1];
            } else {
                minC[i] = i;
            }
        }
        
        int x = 0, y = 0;
        for(int i = 0;i < str.size();i++) {
            if (minC[i] != i) {
				x = i;
				y = minC[i];
                break;
            }
        }
		
		if (y != 0) {
			char c = str[y];
			for(int j = y + 1;j < str.size();j++) {
				if (str[j] == c) {
				    int l1, l2;
					for(l1 = j - 1, l2 = y - 1;l1 > y && l2 >= x;l1--, l2--) {		
						if (str[l1] < str[l2]) {
							y = j;
							break;
						} else if (str[l1] > str[l2]) {
						    break;
						}
					}
					if (l1 == y) {
						y = j;
					}
					if (l2 < x) {
						l2 = y + 1;
						while(l1 > l2) {
							if (str[l1] > str[l2]) break;
							if (str[l1] < str[l2]) {
								y = j;
								break;
							}
							l1--, l2++;
						}
						if (l1 <= l2)
							y = j;
					}
				}				
			}
		}
		
		while(x > 0 && y < str.size() - 1 && str[x - 1] == str[y + 1]) {
		    x--, y++;
		}
        cout << x << " " << y << endl;

    }
    
    return 0;
}
