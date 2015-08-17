#include <cstdio>
#include <algorithm>
using namespace std;

struct walkway
{
	int begin, end, w;
}walkways[1000006];

bool cmp2(const walkway a, const walkway b)
{
	return a.w < b.w ? 1 : 0;
}

int main()
{
	int ncase;
	int icase;
	int s, r, x;
	double t;
	int N;
	double res;
	double walkDis;
	double dis;
	double pos;
	double temp;
	int i;

	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	scanf("%d", &ncase);

	for(icase = 1;icase <= ncase;icase++)
	{
		scanf("%d %d %d %lf %d", &x, &s, &r, &t, &N);

		for(i = 0;i < N;i++)
			scanf("%d %d %d", &walkways[i].begin, &walkways[i].end, &walkways[i].w);

		res = 0;
		walkDis = 0;
		pos = 0;
		for(i = 0;i < N;i++)
		{
			walkDis += (walkways[i].begin - pos);
			pos = walkways[i].end;
		}
		walkDis += x - pos;

//		printf("%lf %lf\n", walkDis, t * r);
		if (t * r <= walkDis)
		{
	//		printf("fdsa\n");
			res = t;
			walkDis -= t * r;
			res += walkDis / s;
			for(i = 0;i < N;i++)
				res += (walkways[i].end - walkways[i].begin) * 1.0 / (walkways[i].w + s);
		}
		else
		{
			t -= walkDis / r;
			res = walkDis / r;
		//	printf("%lf\n", t);
			sort(&walkways[0], &walkways[N], cmp2);
			for(i = 0;i < N;i++)
			{
				if (t * (walkways[i].w + r) >= walkways[i].end - walkways[i].begin)
				{
					temp = (walkways[i].end - walkways[i].begin) * 1.0 / (walkways[i].w + r);
					res += temp;
					t -= temp;
				}
				else
				{
			//		printf("Fdsa\n");
					dis = walkways[i].end - walkways[i].begin - t * (r + walkways[i].w);
			//		printf("%lf\n", dis);
					temp = dis * 1.0 / (walkways[i].w + s) + t;
					res += temp;
					t = 0;
				}
			}
		}
		printf("Case #%d: %.6lf\n", icase, res);
	}
	return 0;
}
