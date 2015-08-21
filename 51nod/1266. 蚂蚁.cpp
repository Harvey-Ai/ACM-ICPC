#include <iostream>
using namespace std;

int main() {
    int n, l;
    cin >> n >> l;
    
    int minTime = 0, maxTime = 0;
    for(int i = 0;i < n;i++) {
        int pos;
        cin >> pos;
        minTime = max(minTime, min(pos, l - pos));
        maxTime = max(maxTime, max(pos, l - pos));
    }
    
    cout << minTime << " " << maxTime << endl;
    
    return 0;
}
