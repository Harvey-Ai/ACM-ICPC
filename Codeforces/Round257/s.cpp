#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int ,int> > v[100100];
priority_queue<pair<long long, int> > q;
int vis[100010] = {0};
long long d[100010];

int main()
{
    int a, b, c, i, x, y, z, sum = 0;
    cin >> a >> b >> c;
    d[0] = 0;
    for (i = 1; i < a; ++i)
      d[i] = 1e18;
    for (i = 0; i < b; ++i)
    {
        scanf("%d%d%d", &x, &y, &z);
        v[x - 1].push_back(make_pair(y - 1, z));
        v[y - 1].push_back(make_pair(x - 1, z));
    }
    q.push(make_pair(0, 0));
    for (i = 0; i < c; ++i)
    {
        scanf("%d%d", &x, &y);
        d[x - 1] = min((long long)y, d[x - 1]);
        q.push(make_pair(-y, 1 - x));
    }
    while (!q.empty())
    {
        x = q.top().second;
        long long y = -q.top().first;
        q.pop();
        if (x < 0)
            cout << x <<  " " << y << " " << vis[-x] << endl;
        else
            cout << x <<  " " << y << " " << vis[x] << endl;
        if (x < 0)
        {
            x = -x;
            if (vis[x])
            {
              sum++;
            }
        }
        if (vis[x])
          continue;
        vis[x] = 1;
        for (i = 0; i < v[x].size(); ++i)
        {
            if (d[v[x][i].first] >= v[x][i].second + y)
            {
                d[v[x][i].first] = v[x][i].second + y;
                q.push(make_pair(-d[v[x][i].first], v[x][i].first));
            }
        }
    }
    printf("%d\n", sum);
    return 0;
}