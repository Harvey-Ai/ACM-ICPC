#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct person
{
	long long p, q;
	int g;
};


long long gcd(long long a, long long b)
{
	if (a < b)
	{
		long long temp = a;
		a = b;
		b = temp;
	}

	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

void add(long long p1, long long q1, long long p2, long long q2, long long *rp, long long *rq)
{
	long long mu = q1 * q2 * 2;

	long long zi = q2 * p1 + q1 * p2;
	long long com = gcd(mu, zi);

	*rp = zi / com;
	*rq = mu / com;
}

int main()
{
	vector<person> gen;

	person a;
	a.p = 1;
	a.q = 1;
	a.g = 0;
	gen.push_back(a);
	a.p = 0;
	a.q = 1;
	a.g = 50;
	gen.push_back(a);	
	a.p = 1;
	a.q = 2;
	a.g = 1;
	gen.push_back(a);

	int head = 2;
	for(int i = 0;i < 40;i++)
	{
		vector <person> newP;
		newP.clear();
		for(int j = head;j < gen.size();j++)
		{
			long long p1 = gen[j].p;
			long long q1 = gen[j].q;
			int g1 = gen[j].g;
			for(int k = 0;k < head;k++)
			{
				long long p2 = gen[k].p;
				long long q2 = gen[k].q;
				int g2 = gen[k].g;
				long long rp, rq;
				add(p2, q2, p1, q1, &rp, &rq);
				
				int found = 0;
				for(int l = 0;l < gen.size();l++)
					if (gen[l].p == rp && gen[l].q == rq)
					{
						found = 1;
						break;
					}
				if (!found)
				{
					person c;
					c.p = rp;
					c.q = rq;

					c.g = g1 < g2 ? (g1 + 1) : (g2 + 1);
					newP.push_back(c);
				}
			}
		}
		head = gen.size();
		for(int j = 0;j < newP.size();j++)
			gen.push_back(newP[j]);
	}

	int ncase;
	cin >> ncase;

	for(int icase = 0;icase < ncase;icase++)
	{
		long long p, q;
		scanf("%lld/%lld", &p, &q);

		if (p == 0 && q == 1)
		{
			 cout << "Case #" << icase + 1 << ": " << 1 << endl;
			 continue;
		}
		else if (p == 1 && q == 1)
		{
			cout << "Case #" << icase + 1 << ": " << 1 << endl;
			continue;
		}

		cout << "fdsafd" << endl;
		long long com = gcd(p, q);
		p /= com;
		q /= com;

		int found = 0;
		for(int i = 0;i < gen.size();i++)
		{
			if (p == gen[i].p && q == gen[i].q)
			{	
				found = gen[i].g;
				break;
			}
		}
		cout << "Case #" << icase + 1 << ": ";
		if (found)
			cout << found << endl;
		else
			cout << "impossible" << endl;
	}
	return 0;
}
