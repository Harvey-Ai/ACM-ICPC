#include <cstdio>
#include <vector>
using namespace std;
#define N 100010
using namespace std;

int arr[N];
int main()
{
	int i, j;
	int n;
	int temp;
	int indu[N];
	int visit[N];
	int tV[N];
	vector < pair <int, int> > vL;
	vector <int> point;

	scanf("%d", &n);

	memset(indu, 0, sizeof(indu));
	memset(visit, 0, sizeof(visit));
	for(i = 1;i <= n;i++)
	{
		scanf("%d", &arr[i]);
		indu[arr[i]]++;
	}

	vL.clear();
	point.clear();

	for(i = 1;i <= n;i++)
	{
		temp = i;
		if (indu[temp] == 0 && !visit[temp])
		{
			memset(tV, 0, sizeof(tV));
			while(!visit[temp])
			{
				visit[temp] = 1;
				tV[temp] = 1;
				temp = arr[temp];
			}
			vL.push_back(make_pair(i, temp));
		}	
	}

	for(i = 1;i <= n;i++)
	{
		temp = i;
		if (!visit[temp])
		{
			while(!visit[temp])
			{
				visit[temp] = 1;
				temp = arr[temp];
			}
			vL.push_back(make_pair(i, i));
		}
	}

	if (vL.size() == 1 && vL[0].first == vL[0].second)
	{
		printf("0\n");
		return 0;
	}

	printf("%d\n", vL.size());
	for(i = 1;i < vL.size();i++)
		printf("%d %d\n", vL[i - 1].second, vL[i].first);
	if (vL.size())
		printf("%d %d\n", vL[i - 1].second, vL[0].first);

 	return 0;
}
