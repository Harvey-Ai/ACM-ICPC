#include <iostream>
#include <cstring>
using namespace std;

int graph[20][20];
long long dp[1 << 19][19];

int cnt(int i)
{
    int k = 0;
    while(i)
    {
        k++;
        i = i & (i - 1);
    }
    return k;
}

int main()
{
	int n, m;
	cin >> n >> m;

	for(int i = 0;i < m;i++)
	{
		int a, b;
		cin >> a >> b;
		graph[b - 1][a - 1] = graph[a - 1][b - 1] = 1;
	}


	for (int i=0;i<n;i++) dp[1<<i][i]=1;
	long long res = 0;
	for(int i = 1;i < (1 << n);i++)
	{
		int temp = i;
        int minNode = 0;
        while((temp & 0x01) == 0)
        {
            temp >>= 1;
            minNode++;
        }

		for(int e = 0;e < n;e++)
		{
			if (!(i & (1 << e)))
				continue;

            if (cnt(i) > 2 && graph[e][minNode])
            {
                res += dp[i][e];
//                cout << i << " " << e << " " << dp[i][e] << "fda" << endl;
            }
			for(int ee = 0;ee < n;ee++)
			{
				if ((i & (1 << ee)) || ee < minNode)
					continue;
				if (!graph[e][ee])
					continue;
                
  //              cout << i << " " << ee << " " << (i | (1 << ee)) << "aaa" << endl;
				dp[i | (1 << ee)][ee] += dp[i][e];
    //            cout << i << " " << ee << " " << (i | (1 << ee)) << "ccccccc" << dp[i | (1 << ee)][ee] << endl;
			}
		}
	}

	cout << res / 2 << endl;
	return 0;

}
