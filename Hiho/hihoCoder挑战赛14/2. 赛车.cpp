#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[100005];
int res;

void dfs(int a, int d, int &l) {

	int l1 = 0, l2 = 0;
    for(int i = 0;i < graph[a].size();i++) {
		int l;
        dfs(graph[a][i], d + 1, l);
		
		if (l > l1) {
			l2 = l1;
			l1 = l;
		} else if (l > l2) {
			l2 = l;
		}
    }

	l = l1 + 1;
	res = max(res, l1 + l2 + d);
}


int main() {
    int n;
    cin >> n;
    for(int i = 0;i < n - 1;i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b); 
    }
    
	res = 0;
	int l;
    dfs(1, 0, l);
    cout << res << endl;


    return 0;
}
